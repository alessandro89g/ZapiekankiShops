#ifndef ZAPIEKANKASTORE_H
#define ZAPIEKANKASTORE_H


/*  This is the abstract class for the ZapiekankaStore.
 *  Here we store some common members and functionalities
 *  and define some functions to be implemented.
 *
 *  The MementoCreator m_savestates manages the status of the order,
 *  it allows to undo the last order and each state is
 *  saved when the class is initialized or a new order is
 *  issued.
 *  The vector m_zapiekanki contains all the DIFFERENT types of
 *  zapiekanki ordered.
 *  The number of each of the UNIQUE zapiekanki is stored in the
 *  vector m_n_zapiekanki.
 *
 *  Each store has a fixed types of zapiekanki it sells, saved in
 *  m_zapiekanki_available.
 *  This is the same for the toppings.
 *
 *  Other info are given in the inline comments.
 */

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

    //  This method creates a loop to order multiple zapiekanka.
    virtual int newOrder() = 0;

    //  This method allows to order a single zapiekanka.
    virtual std::optional<Zapiekanka> orderZapiekanka(std::string type) = 0;

    //  This method calculates the price of the total order by multiplying the number
    //  of the single type of zapiekanka for the price of it. The price is initialized
    //  with the delivery price.
    unsigned int getOrderPrice () const {
        if (m_zapiekanki.size()==0)
            return 0;

        unsigned int price = m_delvery_price;
        for (size_t i=0; i<m_zapiekanki.size(); i++)
            price += m_n_zapiekanki[i]*m_zapiekanki[i].getPrice();
        return price;
    }

    //  This method returns a vector containing all the ordered zapiekanki.
    std::vector<Zapiekanka> getOrderInfo() const {
        std::vector<Zapiekanka> zapiekanki;
        for (size_t i=0; i<m_n_zapiekanki.size(); i++) {
            for (int j=0; j < m_n_zapiekanki[i]; j++)
                zapiekanki.push_back(m_zapiekanki[i]);
        }
        return zapiekanki;
    }

    //  This method allows the user to remove the last zapiekanka ordered
    void cancelLastZapiekanka() {
        loadLastStatusOrder();
    }

    //  This method prints on screen the order with the price and number of
    //  each type of zapiekanka ordered.
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

        for (size_t i=0; i<m_zapiekanki.size(); i++) {
            const Zapiekanka *p = &m_zapiekanki[i];
            int num = m_n_zapiekanki[i];

            std::cout << "\t" << p->getName() << "    \t\t" << num
                      << "*" << p->getPrice()<< "\t" << num*p->getPrice() << "$\n";
        }
        std::cout << "\tDelivery\t\t\t" << m_delvery_price << "$\n";
        std::cout << "_____________________________________________\n";
        std::cout << "Total: \t\t\t\t\t" << getOrderPrice() << "$\n\n";
        std::cout << "!============================================!\n";
    }

    ~ZapiekankaStore () {
        std::cout << "Thanks for having chosen our restaurant!\n"
                     "We hope to see you again!\n\n";
    }

protected:

    //  This method saves the status of the order by constructing a
    //  Memento object with the useful data from the order and
    //  asking the MementoCaretaker m_saveStates to manage it and add
    //  it to its list
    void saveStatusOrder() {
        Memento m(m_zapiekanki, m_n_zapiekanki);
        m_saveStates.saveState(m);
    }

    //  This undo the last order by restoring the last memento,
    //  which is retrieved by the MementoCaretaker.
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
