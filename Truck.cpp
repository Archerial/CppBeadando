#include "Truck.h"
#include <iostream>

Van::Van(string lp, int y, int c, int u): Vehicle(lp,y,c,u){
        setType();
}
void Van::print(){
     cout << "Tipus: " << this->getType() <<  " | " << "Rendszam: "<< this->licencePlate() <<  " | "<< "Gyartasi ev: " << this->manufacturingYear() << " | " << "Tehebiras(T): " << this->capacity()<<" | "<< "Megtett tav(km): " << this->usage() << endl;
}
int Van::service_m = 0;

