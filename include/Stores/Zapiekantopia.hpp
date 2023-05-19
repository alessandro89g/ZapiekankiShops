#ifndef ZAPIEKANKATOPIA_HPP
#define ZAPIEKANKATOPIA_HPP


/*  Check the file ZapiekankaStore.hpp for most of the functionalities
 *  implemented here.
 *  Other functionalities are explained in the code below.
 *
 *  This ZapiekankaStore has a director, who is able to create the zapiekanka
 *  using all the ingredients asked by the costumer
 *
 */

#include "ZapiekankaStore.hpp"
#include "Director.hpp"

class Zapiekankatopia : public ZapiekankaStore {
public:
    Zapiekankatopia() : m_director(Director())
    {
        std::cout << "Zapiekankatopia.\n\n";
        std::cout << "Here you can order the best cheese zapiekanka or create your own zapiekanka.\n";
        m_delvery_price = 2;
    }

    int newOrder () override {
        m_zapiekanki.clear();
        m_n_zapiekanki.clear();
        size_t answer;
        do {
            std::cout << "Press 1 to build your (or another) zapiekanka or press 0 to finish your order: ";
            std::cin >> answer;
            if (answer==1)
                orderZapiekanka();
        } while(answer==1);
        showOrder();
        return m_n_zapiekanki.size();
    }

    std::optional<Zapiekanka> orderZapiekanka(std::string type="Custom") override {
        std::vector<std::unique_ptr<ZapiekankaOption>> ingredients;

        //  ingredients contains all the ingredients needed for the zapiekanka
        //  the list of ingredients is build using the auxiliary methods "choose----"
        ingredients.emplace_back(chooseDough());
        ingredients.emplace_back(chooseSauce());
        ingredients.emplace_back(chooseCheese());
        for (std::unique_ptr<Topping>& t: chooseToppings())
            ingredients.emplace_back(t.release());

        std::unique_ptr<Zapiekanka> zapiekanka;
        CustomZapiekankaBuilder builder;
        //  Here comes the director that using the builder and the ingredients
        //  builds the zapiekanka
        zapiekanka = m_director.makeCustomZapiekanka(builder,ingredients);

        //  From now on, this is the same as for the other stores
        auto pos = std::find(m_zapiekanki.begin(),m_zapiekanki.end(), *zapiekanka);
        if (pos==m_zapiekanki.end()){
            m_zapiekanki.push_back(*zapiekanka);
            m_n_zapiekanki.push_back(1);
        }
        else {
            m_n_zapiekanki[std::distance(m_zapiekanki.begin(),pos)]++;
        }

        std::cout << "\n\n"
                     "Ordered\n" << m_zapiekanki.back().info() << "\n\n";
        std::cout << "Total to pay: " << getOrderPrice() << "$ (" << m_delvery_price << " $ delivery).\n\n";
        saveStatusOrder();
        return *zapiekanka;
    }

private:
    std::unique_ptr<Dough> chooseDough() {
        int answer;
        do {
            std::cout << "---->Choose your dough\n"
                         "\t 1) Thin\n"
                         "\t 2) Thick\n";
            std::cout << "Choose your option: ";
            std::cin >> answer;
            if (answer==1)
                return std::make_unique<ThinCrustDough>();
            else if (answer==2)
                return std::make_unique<ThickCrustDough>();
        } while(answer!=1 && answer != 2);
        return nullptr;
    }
    std::unique_ptr<Sauce> chooseSauce() {
        int answer;
        do {
            std::cout << "---->Choose your sauce\n"
                         "\t 1) Marinara\n"
                         "\t 2) Plum Tomato\n";
            std::cout << "Choose your option: ";
            std::cin >> answer;
            if (answer==1)
                return std::make_unique<MarinaraSauce>();
            else if (answer==2)
                return std::make_unique<PlumTomatoSauce>();
        } while(answer!=1 && answer != 2);
        return nullptr;
    }
    std::unique_ptr<Cheese> chooseCheese() {
        int answer;
        do {
            std::cout << "---->Choose your cheese\n"
                         "\t 1) Oscypek\n"
                         "\t 2) Gouda\n"
                         "\t 3) Mozzarella\n";
            std::cout << "Choose your option: ";
            std::cin >> answer;
            if (answer==1)
                return std::make_unique<OscypekCheese>();
            else if (answer==2)
                return std::make_unique<GoudaCheese>();
            else if (answer==3)
                return std::make_unique<MozzarellaCheese>();
        } while( answer<1 || answer > 3);
        return nullptr;
    }
    std::vector<std::unique_ptr<Topping>> chooseToppings() {
        std::vector<std::unique_ptr<Topping>> toppings;
        int answer;
            do {
                std::cout << "---->Choose your toppings (you can add more of the same type)\n"
                             "\t 1) Mushrooms\n"
                             "\t 2) Olives\n"
                             "\t 3) Boczek\n"
                             "\t 4) Salami\n";
                std::cout << "Choose your option (if you want no more toppings, press 0): ";
                std::cin >> answer;
                if (answer==1)
                    toppings.emplace_back(std::make_unique<MushroomsTopping>());
                else if (answer==2)
                    toppings.emplace_back(std::make_unique<OlivesTopping>());
                else if (answer==3)
                    toppings.emplace_back(std::make_unique<BoczekTopping>());
                else if (answer==4)
                    toppings.emplace_back(std::make_unique<SalamiTopping>());
            } while( answer>0 && answer < 5);
        return toppings;
    }

private:
    Director m_director;
};

#endif // ZAPIEKANKATOPIA_HPP
