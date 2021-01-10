#include "workmachine.hpp"
#include <iostream>

WorkMachine::WorkMachine(string lp, int y, string t, int c, int u): Vehicle(lp,y,t,c,u){
        setKind();
}
void WorkMachine::print(){
    cout << this->licencePlate() << " " << this->manufacturingYear() << " " << this->type() << " Performance(KW): " << this->capacity() << " Weekly work(h): " << this->usage() << endl;
}
int WorkMachine::service_m = 0;
