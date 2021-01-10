#ifndef _WORKMACHINE_HPP_
#define _WORKMACHINE_HPP_
#include "vehicle.hpp"

class WorkMachine: public Vehicle
{
public:
    WorkMachine(string lp, int y, string t, int c, int u);
    WorkMachine() {
        setKind();
    }

    string kind;
    string getKind(){return kind;}
    void setKind() {kind = "WorkMachine";}

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
