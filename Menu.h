#ifndef _STATE_MACHINE_HPP_
#define _STATE_MACHINE_HPP_

#include <string>
#include "Vehicles.h"
#include "Autobus.h"
#include "Truck.h"
#include "Machine.h"
#include <iostream>
#include <vector>

#define STORAGESIZE 100
using namespace std;

class Menu
{
public:
    Menu(): sm_act_state(READ_FROM_FILE), sm_index(0){}
    ~Menu();

    void read_From_File();
    void write_To_File();
    void execute();
    void print();

     enum State {
        READ_FROM_FILE,
        MAIN_MENU,
        SEARCH_BY_LICENCEPLATE,
        LIST_VEHICLE_BY_USAGE,
        SET_SERVICE_REQUIREMENT,
        LIST_SERVICE,
        LICENCE_PLATE,
        YEAR,
        CAPACITY,
        USAGE,
        LIST_A_VEHICLE,
        LIST_ALL_VEHICLE,
        SAVE_INTO_FILE,
        EXIT
    };
     State state() {return sm_act_state;}


private:
    string sm_buffer;
    State sm_act_state;
    vector<Vehicle*> sm_vector;
    int sm_index;
};

#endif
