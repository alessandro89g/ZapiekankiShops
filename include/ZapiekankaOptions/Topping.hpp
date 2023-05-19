#ifndef TOPPING_H
#define TOPPING_H

/*  Here we define the subclass Topping and all its subclasses,
 *  i.e. all the different toppings we have as options
 */

#include "ZapiekankaOption.hpp"
#include <string>


class Topping : public ZapiekankaOption {
public:
    Topping () {}
    Topping(const std::string& name, int price) : ZapiekankaOption(name,price) {}
};

class MushroomsTopping : public Topping {public:
    MushroomsTopping() : Topping("Mushrooms", 5) {}
};

class OlivesTopping : public Topping {public:
    OlivesTopping() : Topping("Olives", 2) {}
};

class BoczekTopping : public Topping {public:
    BoczekTopping() : Topping("Boczek", 4) {}
};

class SalamiTopping : public Topping {public:
    SalamiTopping() : Topping("Salami", 2) {}
};

#endif // TOPPING_H

