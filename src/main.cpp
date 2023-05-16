#include <iostream>
#include <memory>

#include "WolnicaStore.hpp"
#include "PlacNowyStore.hpp"
#include "Zapiekantopia.hpp"


/*    The main function asks which restaurant we want to use to order
 *    our Zapiekanka. The first two restaurants have one fixed option
 *    and a "custom" option, in which the dough, the sauce and the cheese
 *    are fized, but you can choose between some toppings.
 *    The Zapiekantopia restaurant on the other side has a director who
 *    allows you to build your own zapiekanka from scratch.
 *
 *    The method newOrder() asks you to order zapiekanki until you decide
 *    your order is ready.
 */

int main() {

    std::cout << "Hello!\nFrom which restaurant do you want to order?\n"
                 "\t 1) Plac Nowy Zapiekanka\n"
                 "\t 2) Wolnica Zapiekanka\n"
                 "\t 3) Zapiekankatopia (build your own Zapiekanka from scratch!)\n"
                 "Insert the number of choice: ";
    int n_restaurant;
    std::cin >> n_restaurant;

    std::unique_ptr<ZapiekankaStore> store;
    switch (n_restaurant) {
    case 1:
        store = std::make_unique<PlacNowyStore>();
        break;
    case 2:
        store = std::make_unique<WolnicaStore>();
        break;
    case 3:
        store = std::make_unique<Zapiekankatopia>();
        break;
    default:
        std::cout << "\n\nNot hungry anymore? :( \n\n";
        return 1;
    }

    store->newOrder();

    return 0;
}
