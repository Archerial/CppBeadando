#include <iostream>
#include <stdlib.h>
#include <string>
#include "Vehicles.h"
#include "Autobus.h"
#include "Truck.h"
#include "menu.h"
using namespace std;

#define BUFFSIZE 30
int main()
{
    Menu menu;
    while(menu.state() != Menu::EXIT) {
        menu.execute();
    }
    menu.print();
    return 0;
}
