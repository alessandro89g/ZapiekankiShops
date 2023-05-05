#ifndef DOUGH_H
#define DOUGH_H

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
