#include <bits/stdc++.h>
using namespace std;

class BasePizza {
    public:
    virtual int cost() = 0;
};

class Margherita: public BasePizza{
    public: 
    int cost() {
        return 100;
    }
};

class FarmHouse: public BasePizza {
    public: 
    int cost() {
        return 150;
    }
};

class ExtraCheese: public BasePizza {
    public: 
    int cost() {
        return 200;
    }
};

class Toppings: public BasePizza {
    public:
    int onion = 10;
};

class Jalapeno: public Toppings {
    public:
    BasePizza *pizza;
    Jalapeno(BasePizza *newPizza) {
        pizza = newPizza;
    }
    int cost() {
        return pizza->cost() + 10;
    }
};

class Mushroom: public Toppings {
    public:
    BasePizza *pizza;
    Mushroom(BasePizza *newPizza) {
        pizza = newPizza;
    }
    int cost() {
        return pizza->cost() + 15;
    }
};

class Paneer: public Toppings {
    public:
    BasePizza *pizza;
    Paneer(BasePizza *newPizza) {
        pizza = newPizza;
    }
    int cost() {
        return pizza->cost() + 15;
    }
};

int main() {
    BasePizza *p = new Mushroom(new Jalapeno(new Margherita()));
    int c = p->cost();
    cout << c << endl;
}