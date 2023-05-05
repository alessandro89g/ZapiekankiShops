#include <iostream>
#include <memory>
#include "Director.hpp"
#include "Zapiekanka.hpp"
#include "WolnicaStore.hpp"
#include "PlacNowyStore.hpp"

using namespace std;

int main() {
    std::unique_ptr<ZapiekankaStore> store;

    std::cout << "Hello!\nFrom which restaurant do you want to order?\n"
                 "\t 1) Plac Nowy Zapiekanka\n"
                 "\t 2) Wolnica Zapiekanka\n"
                 "Insert the number of choice: ";
    int n_restaurant;
    std::cin >> n_restaurant;
    switch (n_restaurant) {
    case 1:
        store = std::make_unique<PlacNowyStore>();
        break;
    case 2:
        store = std::make_unique<WolnicaStore>();
        break;
    default:
        std::cout << "\n\nNot hungry anymore? :( \n\n";
        return 1;
    }
    store.get()->newOrder();

    return 0;
}
