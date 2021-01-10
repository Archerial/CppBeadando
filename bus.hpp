#ifndef _BUS_HPP_
#define _BUS_HPP_
#include "vehicle.hpp"
class Bus: public Vehicle
{
public:
    Bus(string lp, int y, string t, int c, int u);
    Bus() {
        setKind();
    }

    string kind;
    string getKind(){return kind;}
    void setKind() {kind = "Bus";}

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
