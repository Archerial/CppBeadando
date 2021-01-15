#ifndef _VAN_HPP_
#define _VAN_HPP_
#include "Vehicles.h"
class Van: public Vehicle
{
public:
    Van(string lp, int y, int c, int u);
    Van() {
        setType();
    }

    string type;
    string getType(){return type;}
    void setType() {type = "Teherauto";}

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
