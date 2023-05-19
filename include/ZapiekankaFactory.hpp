#ifndef ZAPIEKANKAFACTORY_H
#define ZAPIEKANKAFACTORY_H

// Singleton pattern and Factory pattern
/*  ZapiekankaFactory is a singleton class that has a method to create Zapiekankim, given the
 *  string containing the type of Zapiekanka requested
 */

#include <memory>

#include "Zapiekanka.hpp"
#include "CheeseZapiekanka.hpp"
#include "ZakopaneZapiekanka.hpp"
#include "CustomZapiekanka.hpp"


class ZapiekankaFactory {
public:
    static ZapiekankaFactory& getInstance() {
        static ZapiekankaFactory instance;
        return instance;
    }

    static std::optional<std::unique_ptr<Zapiekanka>> CreateZapiekanka(std::string type) {
        return getInstance().impl_createZapiekanka(type);
    }

private:
    ZapiekankaFactory() {}
    ZapiekankaFactory(ZapiekankaFactory const&) = delete;
    void operator=(ZapiekankaFactory const&) = delete;


private:
    std::optional<std::unique_ptr<Zapiekanka>> impl_createZapiekanka(std::string type) {
        std::optional<std::unique_ptr<Zapiekanka>> zapiekanka;
        if (type == "Cheese") {
            zapiekanka.emplace(std::move(std::make_unique<CheeseZapiekanka>()));
        } else if (type == "Zakopane") {
            zapiekanka.emplace(std::move(std::make_unique<ZakopaneZapiekanka>()));
        } else if (type == "Custom") {
            zapiekanka.emplace(std::move(std::make_unique<CustomZapiekanka>()));
        }
        return zapiekanka;
    }
};



#endif // ZAPIEKANKAFACTORY_H
