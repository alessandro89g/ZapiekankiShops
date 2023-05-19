#ifndef DOUGH_H
#define DOUGH_H

/*  Here we define the subclass Dough and all its subclasses,
 *  i.e. all the different doughs we have as options
 */

#include "ZapiekankaOption.hpp"

class Dough : public ZapiekankaOption {
public:
    Dough() {}
    Dough(const std::string& name, unsigned int price) : ZapiekankaOption(name,price) { }
};

class ThinCrustDough : public Dough {
public:
    ThinCrustDough() : Dough("thin crust",0) {}
};

class ThickCrustDough : public Dough {
public:
    ThickCrustDough() : Dough("thick crust",3) {}
};

#endif // DOUGH_H
