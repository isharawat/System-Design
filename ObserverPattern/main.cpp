#include <bits/stdc++.h>
#include "Observer.cpp"
#include "Observable.cpp"
using namespace std;
int main() {
    Observer Isha;
    Observer Sachin;
    Observable Iphone;
    Iphone.addObserver(&Isha);
    Iphone.addObserver(&Sachin);
    Iphone.setData(2);
    Iphone.setData(0);
}