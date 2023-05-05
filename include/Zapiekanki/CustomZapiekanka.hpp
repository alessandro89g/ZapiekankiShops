#ifndef CUSTOMZAPIEKANKA_H
#define CUSTOMZAPIEKANKA_H

#include "Zapiekanka.hpp"

class CustomZapiekanka : public Zapiekanka {
public:
    CustomZapiekanka() {
        m_name = "Custom";
    }
    CustomZapiekanka& setDough(const Dough &dough) {
        Zapiekanka::setDough(dough);
        regenerateName();
        return *this;
    }
    CustomZapiekanka& setSauce(const Sauce &sauce) {
        Zapiekanka::setSauce(sauce);
        regenerateName();
        return *this;
    }
    CustomZapiekanka& setCheese(const Cheese &cheese) {
        Zapiekanka::setCheese(cheese);
        regenerateName();
        return *this;
    }
    CustomZapiekanka& addTopping(const Topping &topping) {
        Zapiekanka::addTopping(topping);
        regenerateName();
        return *this;
    }

    void regenerateName() {
        m_name = "Custom";
        if (m_cheese.getName()=="" && m_dough.getName()=="" && m_sauce.getName()==""
            && m_toppings.size()==0)
            return ;
        m_name += ": {\n";
        if (m_dough.getName()!="")
            m_name += "\t\t" + m_dough.getName()+"\n";
        if (m_cheese.getName()!="")
            m_name += "\t\t" + m_cheese.getName()+"\n";
        if (m_sauce.getName()!="")
            m_name += "\t\t" + m_sauce.getName()+"\n";
        for (const Topping& t : m_toppings) {
            if (t.getName()!="")
                m_name += "\t\t" + t.getName()+"\n";
        }
        m_name += "\t}      ";
    }

};

#endif //CUSTOMZAPIEKANKA_H
