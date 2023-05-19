#ifndef CHEESE_H
#define CHEESE_H

/*  Here we define the subclass Cheese and all its subclasses,
 *  i.e. all the different cheese we have as options
 */

#include "ZapiekankaOption.hpp"

class Cheese : public ZapiekankaOption {
public:
    Cheese() {}
    Cheese(const std::string& name, unsigned int price) : ZapiekankaOption(name,price) {}
};

class GoudaCheese : public Cheese {
public:
    GoudaCheese() : Cheese("Gouda", 4) {}
};


class OscypekCheese : public Cheese {
public:
    OscypekCheese() : Cheese("Oscypek", 3) {}
};

class MozzarellaCheese : public Cheese {
public:
    MozzarellaCheese() : Cheese("Mozzarella", 5) {}
};


#endif // CHEESE_H
