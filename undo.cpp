#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
class AirConditioner {
    public:
    int turnOffAC() {
        cout << "Turn Off" << endl;
    }
    int turnOnnAC() {
        cout << "Turn On" << endl; 
    }
};

class Operation {
    public: 
    virtual int execute() {

    }
};

class TurnOff: public Operation {
    public:
    AirConditioner* ac;
    TurnOff(AirConditioner* ac) {
        ac = ac;
    }
    int execute(){
        ac->turnOffAC();
    }
};
class TurnOn: public Operation {
    public:
    AirConditioner* ac;
    TurnOn(AirConditioner* ac) {
        ac = ac;
    }
    int execute() {
        ac->turnOnnAC(); 
    }
};

class RemoteControl {
    public:
    stack<Operation*>s;
    RemoteControl() {
        s = stack<Operation*>();
    }
    int control(Operation* o) {
        o->execute();
        s.push(o);
    }
    int undo() {
        s.top()->execute();
        s.pop();
    }
};
int main() {
    RemoteControl *remote = new RemoteControl;
    AirConditioner* ac = new AirConditioner();
    remote->control(new TurnOff(ac));
    remote->control(new TurnOn(ac));git remote add origin https://github.com/isharawat/System-Design.git
git branch -M main
git push -u origin main
    remote->undo();
}