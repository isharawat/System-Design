#include <bits/stdc++.h>
using namespace std;

class DriveStrategy {
    public:
    virtual void drive() = 0;
};
class NormalStrategy: public DriveStrategy {
    public:
    void drive() {
        cout << "Normal drive" << endl;
    }
};
class SportsStrategy: public DriveStrategy {
    public:
    void drive() {
        cout << "Sports drive" << endl;
    }
};
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
class PassengerVehicle: public Vehicle{
    public:
    PassengerVehicle(DriveStrategy *p): Vehicle(p){}
    
   
};
class OffRoadVehicle: public Vehicle {
    public:
    OffRoadVehicle(DriveStrategy *q): Vehicle(q){}

};

int main() {
    DriveStrategy *p = new NormalStrategy();
    DriveStrategy *q = new SportsStrategy();
    PassengerVehicle Isha = PassengerVehicle(p);
    OffRoadVehicle Sachin = OffRoadVehicle(q);
    Isha.drive();
    Sachin.drive();
}