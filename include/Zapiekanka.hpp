#ifndef ZAPIEKANKA_H
#define ZAPIEKANKA_H


/*  This is the base class for all the different kind of Zapiekanka.
 *  Each Zapiekanka has
 *      name
 *      basic price
 *      type of dough
 *      type of sauce
 *      type of cheese
 *      list of toppings
 *  The method
 *      info() returns a string with all the info about the Zapiekanka
 *      addToppings() adds a Topping to the list
 *      setCheese, setDough, setSauce are protected as they need to be "hidden"
 *          in the subclasses, since they depend on the type of Zapiekanka
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "ZapiekankaOptions/Dough.hpp"
#include "ZapiekankaOptions/Topping.hpp"
#include "ZapiekankaOptions/Cheese.hpp"
#include "ZapiekankaOptions/Sauce.hpp"

class Zapiekanka {
public:
    Zapiekanka() {}
    Zapiekanka(int price) : m_price(price) {}

    int getPrice() const {return m_price;}
    std::string getName() const {return m_name;}

    std::string info() const {
        std::string s = "!==================================!\n"
            "Zapiekanka:\t" + m_name +"\n";
        s += "\tDough:\t\t" + m_dough.getName() + "\n";
        s += "\tSauce:\t\t" + m_sauce.getName() + "\n";
        s += "\tCheese:\t\t" + m_cheese.getName() + "\n";
        s += "\tToppings:\t";
        for (const Topping& t : m_toppings)
            s +=  t.getName() + "  ";
        s += "\n"
             "Price: " + std::to_string(getPrice()) + "$";
        s += "\n!==================================!";

        return s;
    }

    Zapiekanka&  addTopping(const Topping& topping) {
        m_toppings.push_back(topping);
        m_price += topping.getPrice();
        return *this;
    }

    bool operator == (const Zapiekanka& other) const {
        if (m_dough != other.m_dough)
            return false;
        if (m_sauce != other.m_sauce)
            return false;
        if (m_cheese != other.m_cheese)
            return false;
        if (m_toppings.size()!=other.m_toppings.size())
            return false;
        if (m_toppings.size())
            for (const Topping& t : m_toppings)
                if (std::find(other.m_toppings.begin(),other.m_toppings.end(),t)==other.m_toppings.end())
                    return false;
        return true;
    }

    bool operator != (const Zapiekanka& other) {
        return !(*this==other);
    }

    virtual ~Zapiekanka () {
    }

protected:
    Zapiekanka& setDough(const Dough& dough) {
        m_dough = dough;
        m_price += dough.getPrice();
        return *this;
    }
    Zapiekanka&  setSauce(const Sauce& sauce) {
        m_sauce = sauce;
        m_price += sauce.getPrice();
        return *this;
    }
    Zapiekanka&  setCheese(const Cheese& cheese) {
        m_cheese = cheese;
        m_price += cheese.getPrice();
        return *this;
    }

protected:
    std::string m_name;
    int m_price=15;
    Dough m_dough;
    Sauce m_sauce;
    Cheese m_cheese;
    std::vector<Topping> m_toppings;
};

#endif // ZAPIEKANKA_H
