#include <gtest/gtest.h>
#include <memory>

#include "Memento.hpp"
#include "ZapiekankaFactory.hpp"
#include "PlacNowyStore.hpp"
#include "WolnicaStore.hpp"
#include "Director.hpp"
#include "Zapiekantopia.hpp"

using namespace std;

const int base_price = 15;

/*  The first two tests test the class ZapiekankaFactory,
 *  checking that the price and name of the Zapiekanka made using the class and
 *  summing all the needed ingredients are equal and checking that the name corresponds.
 */
TEST(ZAPIEKANKAFACTORY, PEPPERONI) {
    ZakopaneZapiekanka zakopane= *static_cast<ZakopaneZapiekanka*>
                                  (ZapiekankaFactory::CreateZapiekanka("Zakopane").value().get());

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
    CheeseZapiekanka zakopane= *static_cast<CheeseZapiekanka*>
                                (ZapiekankaFactory::CreateZapiekanka("Cheese").value().get());

    Dough dough = ThickCrustDough();
    Cheese cheese = GoudaCheese();
    Sauce sauce = MarinaraSauce();

    int price = base_price + dough.getPrice() + cheese.getPrice() + sauce.getPrice();

    ASSERT_EQ(price, zakopane.getPrice());
    ASSERT_EQ("Cheese", zakopane.getName());
}


/*  These three tests check for the store PlacNowy that
 *      1) that the "Cheese" Zapiekanka from the store is
 *          the same as adding the ingredients one by one.
 *      2) the "Pepperoni" Zapiekanka does not exist in this store
 *      3) The retrieve order method works
 */
TEST(PLACNOWYSTORE, CHEESE) {
    unique_ptr<ZapiekankaStore> store = make_unique<PlacNowyStore>();
    optional<Zapiekanka> zapiekanka = store->orderZapiekanka("Cheese");

    Dough dough = ThickCrustDough();
    Cheese cheese = GoudaCheese();
    Sauce sauce = MarinaraSauce();

    int price = base_price + dough.getPrice() + cheese.getPrice() + sauce.getPrice();

    ASSERT_EQ(price, zapiekanka.value().getPrice());
    ASSERT_EQ("Cheese", zapiekanka.value().getName());
}


TEST(PLACNOWYSTORE, PEPPERONI) {
    unique_ptr<ZapiekankaStore> store = make_unique<PlacNowyStore>();
    optional<Zapiekanka> zapiekanka = store->orderZapiekanka("Zakopane");

    ASSERT_FALSE(zapiekanka.has_value());
}

TEST(PLACNOWYSTORE, RETRIEVE_ORDER) {
    unique_ptr<ZapiekankaStore> store = make_unique<PlacNowyStore>();
    vector<string> zapiekanki = {"Cheese", "Cheese", "Cheese"};

    for (const string& zapiekanka : zapiekanki){
        cout << zapiekanka << "\n";
        store->orderZapiekanka(zapiekanka);
    }

    vector<Zapiekanka> order = store->getOrderInfo();
    ASSERT_EQ(zapiekanki.size(), order.size());

    vector<string> zapiekanka_names = {"Cheese", "Cheese", "Cheese"};

    for(size_t i=0; i<zapiekanki.size(); i++)
        ASSERT_EQ(zapiekanka_names[i], order[i].getName());

}


/*  These three tests check for the store Wolnica that
 *      1) that the "Pepperoni" Zapiekanka from the store is
 *          the same as adding the ingredients one by one.
 *      2) the "Cheese" Zapiekanka does not exist in this store
 *      3) The retrieve order method works
 */
TEST(WOLNICASTORE, PEPPERONI) {
    unique_ptr<ZapiekankaStore> store = make_unique<WolnicaStore>();
    optional<Zapiekanka> zapiekanka = store->orderZapiekanka("Zakopane");

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
    optional<Zapiekanka> zapiekanka = store->orderZapiekanka("Cheese");
    ASSERT_FALSE(zapiekanka.has_value());
}

TEST(WOLNICASTORE, RETRIEVE_ORDER) {
    unique_ptr<ZapiekankaStore> store = make_unique<WolnicaStore>();
    vector<string> zapiekanki = {"Zakopane", "Zakopane", "Zakopane"};

    for (const string& zapiekanka : zapiekanki){
        cout << zapiekanka << "\n";
        store->orderZapiekanka(zapiekanka);
    }

    vector<Zapiekanka> order = store->getOrderInfo();
    ASSERT_EQ(zapiekanki.size(), order.size());

    vector<string> zapiekanka_names = {"Zakopane", "Zakopane", "Zakopane"};

    for(size_t i=0; i<zapiekanki.size(); i++)
        ASSERT_EQ(zapiekanka_names[i], order[i].getName());

}


/*  This test checks the cancelLastZapiekanka method which relies on the
 *  Memento and MementoTaker classes
 */
TEST(MEMENTO, UNDO) {
    unique_ptr<ZapiekankaStore> store = make_unique<WolnicaStore>();
    store->orderZapiekanka("Zakopane");
    store->orderZapiekanka("Zakopane");
    store->orderZapiekanka("Zakopane");

    ASSERT_EQ(3, store->getOrderInfo().size());
    store->cancelLastZapiekanka();
    ASSERT_EQ(2, store->getOrderInfo().size());
    store->cancelLastZapiekanka();
    ASSERT_EQ(1, store->getOrderInfo().size());
    store->cancelLastZapiekanka();
    ASSERT_EQ(0, store->getOrderInfo().size());
    store->cancelLastZapiekanka();
    ASSERT_EQ(0, store->getOrderInfo().size());
}

/*  This checks that the director made zapiekanka is the same as the one
 *  prepared from scratch
 */
TEST(DIRECTOR, MAKEPIZZA) {
    std::vector<std::unique_ptr<ZapiekankaOption>> ingredients;
    ingredients.emplace_back(make_unique<ThinCrustDough>());
    ingredients.emplace_back(make_unique<GoudaCheese>());
    Director director;
    CustomZapiekankaBuilder builder;
    unique_ptr<Zapiekanka> zapiekanka = director.makeCustomZapiekanka(builder,ingredients);
    CustomZapiekanka *test = new CustomZapiekanka;
    test->setCheese(GoudaCheese());
    test->setDough(ThinCrustDough());

    ASSERT_EQ(test->getPrice(), zapiekanka->getPrice());

    delete test;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
