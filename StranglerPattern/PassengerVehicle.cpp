#include <iostream>
#include "Vehicle.cpp"

class PassengerVehicle: public Vehicle {
    public: 
    PassengerVehicle(DriveStrategy *p) : Vehicle(p){};
};