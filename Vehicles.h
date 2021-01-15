#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_

#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Vehicle
{
public:
    Vehicle(string lp, int y);
    Vehicle(string lp, int y, int c, int u);
    Vehicle() {}
    ~Vehicle();

    string licencePlate_m;
    string licencePlate() {return licencePlate_m;}
    void setLicencePlate(string);

    string type;
    virtual void setType()=0;
    virtual string getType()=0;

    int manufacturingYear_m;
    int manufacturingYear() {return manufacturingYear_m;}
    void setYearOfManufacturing(string y) {manufacturingYear_m = atoi(y.c_str());}

    int usage_m;
    int usage() {return usage_m;}
    void setUsage(string u) {usage_m = atoi(u.c_str());}

    int capacity_m;
    int capacity() {return capacity_m;}
    void setCapacity(string c) {capacity_m = atoi(c.c_str());}

    void setServiceReq(string s);

    int getServiceReq();

    virtual void print()=0;
};

#endif
