#include "Machine.h"
#include <iostream>

Machine::Machine(string lp, int y, int c, int u): Vehicle(lp,y,c,u){
        setType();
}
void Machine::print(){
     cout << "Tipus: " << this->getType() <<  " | " << "Rendszam: "<< this->licencePlate() <<  " | "<< "Gyartasi ev: " << this->manufacturingYear() << " | " << "Teljesitmeny(KW): " << this->capacity() <<" | "<< "Munka ora: " << this->usage() << endl;
}
int Machine::service_m = 0;
