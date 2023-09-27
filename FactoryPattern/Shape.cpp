#include <bits/stdc++.h>
using namespace std;

class Shape {
    public: 
    virtual void draw() = 0;
};

class Circle: public Shape {
    public:
    void draw() {
        cout << "Draw Circle" << endl;
    }
};

class Rectangle: public Shape {
    public:
    void draw() {
        cout << "Draw Rectangle" << endl;
    }
};

class Square: public Shape {
    public:
    void draw() {
        cout << "Draw Square" << endl;
    }
};

enum Sha {
    CIRCLE, RECTANGLE, SQUARE
};

class ShapeInventory {
    public:
    Shape* getShape(Sha sh) {
        switch(sh) {
            case CIRCLE:
                return new Circle();
            case RECTANGLE:
                return new Rectangle();
            case SQUARE:
                return new Square();
        }
    }
};

int main() {
    ShapeInventory sI;
    Shape *p = sI.getShape(SQUARE);
    p->draw();
}