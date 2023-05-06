#ifndef ZAPIEKANKABUILDER_H
#define ZAPIEKANKABUILDER_H

#include "Zapiekanka.hpp"
#include "ZakopaneZapiekanka.hpp"
#include "CheeseZapiekanka.hpp"
#include "CustomZapiekanka.hpp"
#include "ZapiekankaFactory.hpp"

#include <memory>

class ZapiekankaBuilder {
public:
    virtual void buildZapiekanka(const std::vector<std::unique_ptr<ZapiekankaOption>>& ) = 0;
    std::unique_ptr<Zapiekanka> getZapiekanka() {
        return std::make_unique<Zapiekanka>(*zapiekanka);
    }
    virtual ~ZapiekankaBuilder () {
    }

protected:
    virtual void buildDough(const Dough& d) = 0;
    virtual void buildSauce(const Sauce& s) = 0;
    virtual void buildCheese(const Cheese& c) = 0;
    virtual void buildTopping(const Topping& t) = 0;
    std::unique_ptr<Zapiekanka> zapiekanka;
};

class CustomZapiekankaBuilder : public ZapiekankaBuilder {
public:
    CustomZapiekankaBuilder() {
        zapiekanka = std::move(ZapiekankaFactory::CreateZapiekanka("Custom").value());
    }

    void buildZapiekanka(const std::vector<std::unique_ptr<ZapiekankaOption>>& ingredients) override
    {
        for (const std::unique_ptr<ZapiekankaOption>& opt : ingredients) {
            ZapiekankaOption *o = opt.get();
            if (dynamic_cast<Dough *>(o))
                buildDough(*dynamic_cast<Dough *>(o));
            else if (dynamic_cast<Sauce *>(o))
                buildSauce(*dynamic_cast<Sauce *>(o));
            else if (dynamic_cast<Cheese *>(o))
                buildCheese(*dynamic_cast<Cheese *>(o));
            else if (dynamic_cast<Topping *>(o))
                buildTopping(*dynamic_cast<Topping *>(o));
            else {
                std::cout << "The director could not find the ingredient: " << o->getName() << "\n";
            }
        }
    }

protected:
    void buildDough(const Dough& d) override {
        dynamic_cast<CustomZapiekanka *>(zapiekanka.get())->setDough(d);
    }
    void buildSauce(const Sauce& s) override {
        dynamic_cast<CustomZapiekanka *>(zapiekanka.get())->setSauce(s);
    }
    void buildCheese(const Cheese& c) override {
        dynamic_cast<CustomZapiekanka *>(zapiekanka.get())->setCheese(c);
    }
    void buildTopping(const Topping& t) override {
        dynamic_cast<CustomZapiekanka *>(zapiekanka.get())->addTopping(t);
    }
};


#endif // ZAPIEKANKABUILDER_H
