#ifndef CHEESE_H
#define CHEESE_H

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
