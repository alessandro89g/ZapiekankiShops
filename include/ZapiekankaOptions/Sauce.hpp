#ifndef SAUCE_H
#define SAUCE_H

/*  Here we define the subclass Sauce and all its subclasses,
 *  i.e. all the different sauces we have as options
 */

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
