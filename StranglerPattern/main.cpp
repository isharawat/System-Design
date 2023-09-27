#include "PassengerVehicle.cpp"
#include "OffRoadVehicle.cpp"
#include "SportsStrategy.cpp"
#include "NormalStrategy.cpp"
int main() {
    PassengerVehicle Isha = PassengerVehicle(new SportsStrategy());
    OffRoadVehicle Sachin = OffRoadVehicle(new NormalStrategy());
    Isha.drive();
    Sachin.drive();
}