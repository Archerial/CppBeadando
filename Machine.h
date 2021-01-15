#ifndef _WORKMACHINE_HPP_
#define _WORKMACHINE_HPP_
#include "Vehicles.h"

class Machine: public Vehicle
{
public:
    Machine(string lp, int y,int c, int u);
    Machine() {
        setType();
    }

    string type;
    string getType(){return type;}
    void setType() {type = "Munkagep";}

    static int service_m;
    static int getServiceReq(){
        return service_m;
    }
    static void setServiceReq(string s){
        service_m = atoi(s.c_str());
    }

    void print();
};
#endif // _WORKMACHINE_HPP_
