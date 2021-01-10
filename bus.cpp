#include "bus.hpp"
#include <iostream>

Bus::Bus(string lp, int y, string t, int c, int u): Vehicle(lp,y,t, c, u){
        setKind();
}
void Bus::print(){
    cout << this->licencePlate() <<  " " << this->manufacturingYear() << " " << this->type() << " Seats: " << this->capacity() << " Weekly distance(km): " << this->usage() << endl;
}
int Bus::service_m = 0;
