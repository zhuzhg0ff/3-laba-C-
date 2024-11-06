#include "House.h"

House::House(int f) : floors(f) {}

string House::toString() const {
    string suffix = "этажами";
    if (floors % 10 == 1 && floors % 100 != 11) {
        suffix = "этажом";
    } 
    return "Дом с " + to_string(floors) + " " + suffix;
}

void House::print() const {
    cout << toString() << endl;
}
