#include "vehicle.hpp"
#include <iostream>
Vehicle::Vehicle(string lp, int y, string t): licencePlate_m(lp), manufacturingYear_m(y), type_m(t){
}
Vehicle::Vehicle(string lp, int y, string t, int c, int u): licencePlate_m(lp), manufacturingYear_m(y), type_m(t), capacity_m(c), usage_m(u){
}
Vehicle::~Vehicle() {}
void Vehicle::setLicencePlate(string lp){licencePlate_m = lp;}
