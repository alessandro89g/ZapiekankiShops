#ifndef PLACNOWYSTORE_HPP
#define PLACNOWYSTORE_HPP

/*  Check the file ZapiekankaStore.hpp for most of the functionalities
 *  implemented here.
 *  Other functionalities are explained in the code below.
 */

#include "ZapiekankaStore.hpp"

class PlacNowyStore : public ZapiekankaStore {
public:
    //  The constructor initializes the list of zapiekanki that the store sells
    //  and the delivery price of the store.
    PlacNowyStore() {
        m_zapiekanki_available = {"Cheese", "Custom"};
        std::cout << "Plac Nowy Zapiekanka.\n\n";
        std::cout << "Here you can order the best cheese zapiekanka or create your own zapiekanka.\n";
        m_delvery_price = 4;
    }

    int newOrder () override {
        m_zapiekanki.clear();
        m_n_zapiekanki.clear();

        size_t answer;  // This variable keeps the loop going until you enter 0
        do {
            std::cout << "Choose your zapiekanka:\n";
            for (size_t i=0; i<m_zapiekanki_available.size(); i++) {
                std::cout << "\t " << std::to_string(i+1) << ") " << m_zapiekanki_available[i] << "\n";
            }
            std::cout << "Insert the number or press 0 to finish your order: ";
            std::cin >> answer;
            switch (answer) {
            case 1:
                //From this store you can order only Cheese Zapiekanka
                orderZapiekanka("Cheese");
                break;
            case 2:
                // ... and make a custom zapiekanka with specific fixed ingredients
                orderZapiekanka("Custom");
                break;
            default:
                break;
            }
        } while(answer<=m_zapiekanki_available.size() && answer >=1);
        showOrder();
        return m_n_zapiekanki.size();
    }

    std::optional<Zapiekanka> orderZapiekanka(std::string type) override {
        std::unique_ptr<Zapiekanka> zapiekanka;
        std::optional<std::unique_ptr<Zapiekanka>> zapiekanka_opt
            = ZapiekankaFactory::CreateZapiekanka(type);
        if (!zapiekanka_opt.has_value())
            return std::nullopt;

        //  Here is how the custom zapiekanka is constructed
        if (type == "Custom") {
            std::unique_ptr<CustomZapiekanka> custom_zapiekanka
                = std::unique_ptr<CustomZapiekanka>{static_cast<CustomZapiekanka*>(zapiekanka_opt.value().release())};

            std::cout << "Choose one of the following toppings:\n"
                         "\t 1) Olives\n"
                         "\t 2) Mushrooms\n"
                         "\t 3) Both\n"
                         "Insert the corresponding number: ";
            custom_zapiekanka->setCheese(OscypekCheese());
            custom_zapiekanka->setDough(ThickCrustDough());
            custom_zapiekanka->setSauce(PlumTomatoSauce());
            int n;
            std::cin>>n;
            switch (n) {
            case 1:
                custom_zapiekanka->addTopping(OlivesTopping());
                break;
            case 2:
                custom_zapiekanka->addTopping(MushroomsTopping());
                break;
            case 3:
                custom_zapiekanka->addTopping(OlivesTopping()).addTopping(MushroomsTopping());
                break;
            default:
                std::cout << "You chose no toppings\n";
                break;
            }
            zapiekanka = std::move(custom_zapiekanka);
        }
        else if (type=="Cheese") {
            zapiekanka = std::move(zapiekanka_opt.value());
        }
        else {
            std::cout << "Sorry, we do not have that zapiekanka!\n";
            return std::nullopt;
        }

        //  Check if we already ordered the same type of zapiekanka
        auto pos = std::find(m_zapiekanki.begin(),m_zapiekanki.end(), *zapiekanka);
        if (pos==m_zapiekanki.end()){
            // if not, we add it to the list of different zapiekanki and we add 1 to its number order
            m_zapiekanki.push_back(*zapiekanka);
            m_n_zapiekanki.push_back(1);
        }
        else {
            // else, we add 1 to the order of the same type
            m_n_zapiekanki[std::distance(m_zapiekanki.begin(),pos)]++;
        }
        std::cout << "\n\n"
                     "Ordered\n" << m_zapiekanki.back().info() << "\n\n";
        std::cout << "Total to pay: " << getOrderPrice() << "$ (" << m_delvery_price << " $ delivery).\n\n";
        saveStatusOrder();  // we safe the order, in case we want to cancel this zapiekanka
        return *zapiekanka;
    }
};

#endif // PLACNOWYSTORE_HPP
