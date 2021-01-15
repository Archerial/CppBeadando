#ifndef _BUS_HPP_
#define _BUS_HPP_
#include "Vehicles.h"
class Bus: public Vehicle
{
public:
    Bus(string lp, int y,int c, int u);
    Bus() {
        setType();
    }

    string type;
    string getType(){return type;}
    void setType() {type = "Busz";}

    static int service_m;
    static int getServiceReq(){
        return service_m;
    }
    static void setServiceReq(string s){
        service_m = atoi(s.c_str());
    }

    void print();

};
#endif
