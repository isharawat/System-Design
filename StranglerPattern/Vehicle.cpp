#ifndef XYZA
#define XYZA
#include "DriveStrategy.cpp"
class Vehicle {
    public:
    DriveStrategy *d;
    Vehicle(DriveStrategy *obj) {
        this->d = obj;
    }
    void drive() {
        d->drive();
    }
};
#endif