#ifndef XYX
#define XYX

#include <bits/stdc++.h>
#include "Observer.cpp"

class Observable {
    public:
    int data;
    map<Observer*, int>Obj;
    void addObserver(Observer* single) {
        Obj[single]++;
    }
    void remove(Observer* single) {
        Obj.erase(single);
    }
    void notifyAll() {
        for(auto it: Obj) {
            it.first->update();
        }
    }
    int setData(int t) {
        data = t;
        if(data == 0) {
            notifyAll();
        }
    }
};
#endif