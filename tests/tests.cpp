#include <gtest/gtest.h>
#include <memory>

#include "Memento.hpp"
#include "ZapiekankaFactory.hpp"
#include "PlacNowyStore.hpp"
#include "WolnicaStore.hpp"
#include "Director.hpp"

using namespace std;

const int base_price = 15;

TEST(ZAPIEKANKAFACTORY, PEPPERONI) {
    ZapiekankaFactory& store = ZapiekankaFactory::getInstance();
    ZakopaneZapiekanka zakopane= *static_cast<ZakopaneZapiekanka*>
        (store.CreateZapiekanka("Zakopane").value().get());

    Dough dough = ThinCrustDough();
    Cheese cheese = OscypekCheese();
    Sauce sauce = PlumTomatoSauce();
    Topping topping1 = BoczekTopping();
    Topping topping2 = OlivesTopping();

    int price = base_price + dough.getPrice() + cheese.getPrice() + sauce.getPrice()
            + topping1.getPrice() + topping2.getPrice();

    ASSERT_EQ(price, zakopane.getPrice());
    ASSERT_EQ("Zakopane", zakopane.getName());
}

TEST(ZAPIEKANKAFACTORY, CHEESE_ZAPIEKANKA) {
    ZapiekankaFactory& store = ZapiekankaFactory::getInstance();
    CheeseZapiekanka zakopane= *static_cast<CheeseZapiekanka*>
                               (store.CreateZapiekanka("Cheese").value().get());

    Dough dough = ThickCrustDough();
    Cheese cheese = GoudaCheese();
    Sauce sauce = MarinaraSauce();

    int price = base_price + dough.getPrice() + cheese.getPrice() + sauce.getPrice();

    ASSERT_EQ(price, zakopane.getPrice());
    ASSERT_EQ("Cheese", zakopane.getName());
}

TEST(PLACNOWYSTORE, CHEESE) {
    unique_ptr<ZapiekankaStore> store = make_unique<PlacNowyStore>();
    optional<Zapiekanka> zapiekanka = store.get()->orderZapiekanka("Cheese");

    Dough dough = ThickCrustDough();
    Cheese cheese = GoudaCheese();
    Sauce sauce = MarinaraSauce();

    int price = base_price + dough.getPrice() + cheese.getPrice() + sauce.getPrice();

    ASSERT_EQ(price, zapiekanka.value().getPrice());
    ASSERT_EQ("Cheese", zapiekanka.value().getName());
}


TEST(PLACNOWYSTORE, PEPPERONI) {
    unique_ptr<ZapiekankaStore> store = make_unique<PlacNowyStore>();
    optional<Zapiekanka> zapiekanka = store.get()->orderZapiekanka("Zakopane");

    ASSERT_FALSE(zapiekanka.has_value());
}

TEST(PLACNOWYSTORE, RETRIEVE_ORDER) {
    unique_ptr<ZapiekankaStore> store = make_unique<PlacNowyStore>();
    vector<string> zapiekanki = {"Cheese", "Cheese", "Cheese"};

    for (const string& zapiekanka : zapiekanki){
        cout << zapiekanka << "\n";
        store.get()->orderZapiekanka(zapiekanka);
    }

    vector<Zapiekanka> order = store.get()->getOrderInfo();
    ASSERT_EQ(zapiekanki.size(), order.size());

    vector<string> zapiekanka_names = {"Cheese", "Cheese", "Cheese"};

    for(size_t i=0; i<zapiekanki.size(); i++)
        ASSERT_EQ(zapiekanka_names[i], order[i].getName());

}



TEST(WOLNICASTORE, PEPPERONI) {
    unique_ptr<ZapiekankaStore> store = make_unique<WolnicaStore>();
    optional<Zapiekanka> zapiekanka = store.get()->orderZapiekanka("Zakopane");

    Dough dough = ThinCrustDough();
    Cheese cheese = OscypekCheese();
    Sauce sauce = PlumTomatoSauce();
    Topping topping1 = BoczekTopping();
    Topping topping2 = OlivesTopping();

    int price = base_price + dough.getPrice() + cheese.getPrice() + sauce.getPrice()
                + topping1.getPrice() + topping2.getPrice();

    ASSERT_EQ(price, zapiekanka.value().getPrice());
    ASSERT_EQ("Zakopane", zapiekanka.value().getName());
}

TEST(WOLNICASTORE, CHEESE) {
    unique_ptr<ZapiekankaStore> store = make_unique<WolnicaStore>();
    optional<Zapiekanka> zapiekanka = store.get()->orderZapiekanka("Cheese");
    ASSERT_FALSE(zapiekanka.has_value());
}

TEST(WOLNICASTORE, RETRIEVE_ORDER) {
    unique_ptr<ZapiekankaStore> store = make_unique<WolnicaStore>();
    vector<string> zapiekanki = {"Zakopane", "Zakopane", "Zakopane"};

    for (const string& zapiekanka : zapiekanki){
        cout << zapiekanka << "\n";
        store.get()->orderZapiekanka(zapiekanka);
    }

    vector<Zapiekanka> order = store.get()->getOrderInfo();
    ASSERT_EQ(zapiekanki.size(), order.size());

    vector<string> zapiekanka_names = {"Zakopane", "Zakopane", "Zakopane"};

    for(size_t i=0; i<zapiekanki.size(); i++)
        ASSERT_EQ(zapiekanka_names[i], order[i].getName());

}

TEST(MEMENTO, UNDO) {
    unique_ptr<ZapiekankaStore> store = make_unique<WolnicaStore>();
    store.get()->orderZapiekanka("Zakopane");
    store.get()->orderZapiekanka("Zakopane");
    store.get()->orderZapiekanka("Zakopane");

    ASSERT_EQ(3, store.get()->getOrderInfo().size());
    store.get()->cancelLastZapiekanka();
    ASSERT_EQ(2, store.get()->getOrderInfo().size());
    store.get()->cancelLastZapiekanka();
    ASSERT_EQ(1, store.get()->getOrderInfo().size());
    store.get()->cancelLastZapiekanka();
    ASSERT_EQ(0, store.get()->getOrderInfo().size());
    store.get()->cancelLastZapiekanka();
    ASSERT_EQ(0, store.get()->getOrderInfo().size());
}

TEST(DIRECTOR, MAKEPIZZA) {
    std::vector<std::unique_ptr<ZapiekankaOption>> ingredients;
    ingredients.emplace_back(make_unique<ThinCrustDough>());
    ingredients.emplace_back(make_unique<GoudaCheese>());
    Director director;
    CustomZapiekankaBuilder builder;
    Zapiekanka *zapiekanka = director.makeCustomZapiekanka(builder,ingredients);
    CustomZapiekanka *test = new CustomZapiekanka;
    test->setCheese(GoudaCheese());
    test->setDough(ThinCrustDough());

    ASSERT_EQ(test->getPrice(), zapiekanka->getPrice());

    delete zapiekanka;
    delete test;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
