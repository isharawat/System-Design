#include <iostream>
#include "DriveStrategy.cpp"
class SportsStrategy: public DriveStrategy{
    public:
    void drive() {
        std::cout << "Sports Drive" << std::endl;
    }
};