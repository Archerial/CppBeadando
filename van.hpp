#ifndef _VAN_HPP_
#define _VAN_HPP_
#include "vehicle.hpp"
class Van: public Vehicle
{
public:
    Van(string lp, int y, string t, int c, int u);
    Van() {
        setKind();
    }

    string kind;
    string getKind(){return kind;}
    void setKind() {kind = "Van";}

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
