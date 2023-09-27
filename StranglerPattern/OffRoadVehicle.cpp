#include <iostream>
#include "Vehicle.cpp"
class OffRoadVehicle: public Vehicle {
    public: 
    OffRoadVehicle(DriveStrategy *p) : Vehicle(p){};
};