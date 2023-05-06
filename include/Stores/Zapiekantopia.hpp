#ifndef PLACNOWYSTORE_HPP
#define PLACNOWYSTORE_HPP

#include "ZapiekankaStore.hpp"

class PlacNowyStore : public ZapiekankaStore {
public:
    PlacNowyStore() {
        m_zapiekanki_available = {"Cheese", "Custom"};
        std::cout << "Plac Nowy Zapiekanka.\n\n";
        std::cout << "Here you can order the best cheese zapiekanka or create your own zapiekanka.\n";
        m_delvery_price = 4;
    }

    int newOrder () override {
        m_zapiekanki.clear();
        m_n_zapiekanki.clear();
        int answer;
        do {
            std::cout << "Choose your zapiekanka:\n";
            for (int i=0; i<m_zapiekanki_available.size(); i++) {
                std::cout << "\t " << std::to_string(i+1) << ") " << m_zapiekanki_available[i] << "\n";
            }
            std::cout << "Insert the number or press 0 to finish your order: ";
            std::cin >> answer;
            switch (answer) {
            case 1:
                orderZapiekanka("Cheese");
                break;
            case 2:
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
};

#endif // PLACNOWYSTORE_HPP