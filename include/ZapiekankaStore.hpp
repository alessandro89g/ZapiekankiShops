#ifndef ZAPIEKANKASTORE_H
#define ZAPIEKANKASTORE_H

#include <algorithm>
#include <memory>
#include "Zapiekanka.hpp"
#include "ZapiekankaFactory.hpp"
#include "MementoCaretaker.hpp"

class ZapiekankaStore {
public:
    ZapiekankaStore() {
        std::cout << "\n\nHi! Thanks for choosing our restaurant ";
        saveStatusOrder();
    }
    virtual int newOrder() = 0;
    virtual std::optional<Zapiekanka> orderZapiekanka(std::string type) = 0;

    unsigned int getOrderPrice () const {
        if (m_zapiekanki.size()==0)
            return 0;

        unsigned int price = m_delvery_price;
        for (int i=0; i<m_zapiekanki.size(); i++)
            price += m_n_zapiekanki[i]*m_zapiekanki[i].getPrice();
        return price;
    }

    std::vector<Zapiekanka> getOrderInfo() const {
        std::vector<Zapiekanka> zapiekanki;
        for (int i=0; i<m_n_zapiekanki.size(); i++) {
            for (int j=0; j < m_n_zapiekanki[i]; j++)
                zapiekanki.push_back(m_zapiekanki[i]);
        }
        return zapiekanki;
    }

    void cancelLastZapiekanka() {
        loadLastStatusOrder();
    }

    ~ZapiekankaStore () {}

protected:
    void showOrder() const {
        if (m_zapiekanki.size()==0) {
            std::cout << "\n\n"
                         "You did not order anything. Hope to see you again!"
                         "\n\n";
            return;
        }
        std::cout << "\n\n!============================================!\n";
        std::cout << "Your order:\n";
        std::cout << "\tName      \t\tPrice\n"
                     "_____________________________________________\n";

        for (int i=0; i<m_zapiekanki.size(); i++) {
            const Zapiekanka *p = &m_zapiekanki[i];
            int num = m_n_zapiekanki[i];

            std::cout << "\t" << p->getName() << "    \t\t" << num
                      << "*" << p->getPrice()<< "\t" << num*p->getPrice() << "$\n";
        }
        std::cout << "\tDelivery\t\t\t" << m_delvery_price << "$\n";
        std::cout << "_____________________________________________\n";
        std::cout << "Total: \t\t\t\t\t" << getOrderPrice() << "$\n\n";
        std::cout << "!============================================!\n"
                     "Thanks for having chosen our restaurant!\n"
                     "We hope to see you again!\n\n";
    }

    void saveStatusOrder() {
        Memento m(m_zapiekanki, m_n_zapiekanki);
        m_saveStates.saveState(m);
    }

    void loadLastStatusOrder() {
        std::optional<Memento> m = m_saveStates.loadLastState();
        if (m.has_value()){
            m_zapiekanki = m.value().get_Zapiekankas();
            m_n_zapiekanki = m.value().get_NumberZapiekankas();
            std::cout << "\n\n"
                         "State loaded to : " << m.value().getTimeStamp() << "\n\n";
        }
    }

protected:
    unsigned int m_delvery_price = 0;
    std::vector<Zapiekanka> m_zapiekanki;
    std::vector<int> m_n_zapiekanki;
    MomentoCaretaker m_saveStates;
    size_t m_state_number = 0;
    std::vector<std::string> m_zapiekanki_available;
    std::vector<std::string> m_toppings_available;
};






#endif // ZAPIEKANKASTORE_H
