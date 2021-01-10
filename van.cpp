#include "van.hpp"
#include <iostream>

Van::Van(string lp, int y, string t, int c, int u): Vehicle(lp,y,t,c,u){
        setKind();
}
void Van::print(){
    cout << this->licencePlate() << " " << this->manufacturingYear() << " " << this->type() << " Load capacity(T): " << this->capacity() << " Weekly distance(km): " << this->usage() << endl;
}
int Van::service_m = 0;
