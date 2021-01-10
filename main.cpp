#include <iostream>
#include <stdlib.h>
#include <string>
#include "vehicle.hpp"
#include "bus.hpp"
#include "van.hpp"
#include "workmachine.hpp"
#include "state_machine.hpp"
using namespace std;

#define BUFFSIZE 30
int main()
{
    StateMachine stateMachine;
    while(stateMachine.state() != StateMachine::EXIT) {
        stateMachine.execute();
    }
    stateMachine.print();
    return 0;
}
