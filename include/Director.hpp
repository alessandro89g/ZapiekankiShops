#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "ZapiekankaBuilder.hpp"

class Director {
public:
    Zapiekanka *makeCustomZapiekanka(CustomZapiekankaBuilder& builder,
                                     const std::vector<std::unique_ptr<ZapiekankaOption>>& ingredients) {
        builder.buildZapiekanka(ingredients);
        return builder.getZapiekanka();
    }
};

#endif // DIRECTOR_H
