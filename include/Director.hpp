#ifndef DIRECTOR_H
#define DIRECTOR_H

/* Director for the Builder pattern
 *
 * The director uses the builder object and a list of ingredients to create a Zapiekanka
 */


#include "ZapiekankaBuilder.hpp"

class Director {
public:
    std::unique_ptr<Zapiekanka> makeCustomZapiekanka(CustomZapiekankaBuilder& builder,
                                     const std::vector<std::unique_ptr<ZapiekankaOption>>& ingredients) {
        builder.buildZapiekanka(ingredients);
        return builder.getZapiekanka();
    }
};

#endif // DIRECTOR_H
