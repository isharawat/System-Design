#include <iostream>
#include "DriveStrategy.cpp"
class NormalStrategy: public DriveStrategy {
    void drive() {
        std::cout << "Normal Drive" << std::endl;
    }
};