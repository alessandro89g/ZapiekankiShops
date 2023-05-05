#ifndef SAUCE_H
#define SAUCE_H

#include "ZapiekankaOption.hpp"

class Sauce : public ZapiekankaOption {
public:
    Sauce() {}
    Sauce(const std::string& name, int price) : ZapiekankaOption(name,price) {}
};

class MarinaraSauce : public Sauce {
public:
    MarinaraSauce() : Sauce("Marinara",1) {}
};

class PlumTomatoSauce : public Sauce {
public:
    PlumTomatoSauce() : Sauce("Plum tomato",2) {}
};

#endif // SAUCE_H
