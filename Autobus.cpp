#include "Autobus.h"
#include <iostream>

Bus::Bus(string lp, int y,int c, int u): Vehicle(lp,y,c, u){
        setType();
}
void Bus::print(){
    cout << "Tipus: " << this->getType() <<  " | " << "Rendszam: "<< this->licencePlate() <<  " | "<< "Gyartasi ev: " << this->manufacturingYear() << " | " << "Ulesek szama: " << this->capacity() << " | "<< "Megtett tav(km): " << this->usage() << endl;
}
int Bus::service_m = 0;
