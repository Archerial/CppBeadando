#include "Vehicles.h"
#include <iostream>
Vehicle::Vehicle(string lp, int y): licencePlate_m(lp), manufacturingYear_m(y){
}
Vehicle::Vehicle(string lp, int y, int c, int u): licencePlate_m(lp), manufacturingYear_m(y),capacity_m(c), usage_m(u){
}
Vehicle::~Vehicle() {}
void Vehicle::setLicencePlate(string lp){licencePlate_m = lp;}
