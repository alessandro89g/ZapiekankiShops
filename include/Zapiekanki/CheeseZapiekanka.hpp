#ifndef CHEESEZAPIEKANKA_H
#define CHEESEZAPIEKANKA_H

#include "../Zapiekanka.hpp"

class CheeseZapiekanka : public Zapiekanka {
public:
    CheeseZapiekanka() {
        setDough(ThickCrustDough());
        setCheese(GoudaCheese());
        setSauce(MarinaraSauce());
        m_name = "Cheese";
    }
};
#endif // CHEESEZAPIEKANKA_H
