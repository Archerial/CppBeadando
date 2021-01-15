#include "Menu.h"
#include "Vehicles.h"
#include "Truck.h"
#include <stdlib.h>
#include "Autobus.h"
#include <fstream>
#include "Machine.h"
#include <sstream>
#include <iostream>

#include <vector>
using namespace std;

void Menu::execute()
{
    switch(sm_act_state) {
        case READ_FROM_FILE:{
            read_From_File();
            sm_act_state = MAIN_MENU;
            break;
        }
    case MAIN_MENU:{

    system("CLS");
        cout << "(1) Ujabb jarmu adatainak tarolasa" << endl;
        cout << "(2) Gepek adatainak teljes listazasa" << endl;
        cout << "(3) Gep adatainak kiiratasa billentyuzetrol bekert rendszam alapjan" << endl;
        cout << "(4) Igenybevetel osszesitese kategoriankent" << endl;
        cout << "(5) Kategoriankent szerviz igenybeveteli hatar beallitasa" << endl;
        cout << "(6) Azoknak a jarmuveknek a listazasa, melyek a szerviz igenybeveteli hatart tulleptek" << endl;
        cout << "(7) Kilepes" << endl;

            cin >> sm_buffer;
            if (sm_buffer[0] == '1')
                sm_act_state = LICENCE_PLATE;
            else if(sm_buffer[0] == '2'){
                sm_act_state = LIST_ALL_VEHICLE;
            }
            else if(sm_buffer[0] == '3'){
                sm_act_state = SEARCH_BY_LICENCEPLATE;
            }
            else if(sm_buffer[0] == '4'){
                sm_act_state = LIST_VEHICLE_BY_USAGE;
            }
            else if(sm_buffer[0] == '5'){
                sm_act_state = SET_SERVICE_REQUIREMENT;
            }
            else if(sm_buffer[0] == '6'){
                sm_act_state = LIST_SERVICE;
            }
            else if(sm_buffer[0] == '7'){
                sm_act_state = SAVE_INTO_FILE;
            }
            break;
    }
    case SEARCH_BY_LICENCEPLATE:{
        system("CLS");
        cout << endl << "Rendszam: ";
        cin >> sm_buffer;
        for (int i = 0; i < sm_vector.size(); i++) {
            if(sm_vector.at(i)->licencePlate() == sm_buffer){
                sm_vector.at(i)->print();
            }
        }
            cout << "New search: n, Back: b" << endl;
            char s;
            cin >> s;
            if(s == 'n') {
                sm_act_state = SEARCH_BY_LICENCEPLATE;
                break;
            }
            else if(s == 'b'){
                sm_act_state = MAIN_MENU;
                break;
            }
            else{
                sm_act_state = SEARCH_BY_LICENCEPLATE;
                break;
            }
    }
    case LIST_VEHICLE_BY_USAGE:{
    system("CLS");
    int v_usage(0);
    int b_usage(0);
    int w_usage(0);
        for (int i = 0; i < sm_vector.size(); i++) {
            if(sm_vector.at(i)->getType() == "Teherauto"){
                v_usage = v_usage + sm_vector.at(i)->usage();
            }
            if(sm_vector.at(i)->getType() == "Busz"){
                b_usage = b_usage + sm_vector.at(i)->usage();
            }
            if(sm_vector.at(i)->getType() == "Munkagep"){
                w_usage = w_usage + sm_vector.at(i)->usage();
            }
        }
        cout << "Igenybevetelek" << endl;
        cout << endl;
        cout << "Teherautok igenybevetele: " << v_usage << " km" << endl;
        cout << "Buszok igenybevetele: " << b_usage << " km" << endl;
        cout << "Munkagepek igenybevetele: " << w_usage << " ora" << endl;
        cout << endl;
        cout << "Back: b" << endl;

        char s;
        cin >> s;
            if(s == 'b'){
                sm_act_state = MAIN_MENU;
                break;
            }
            else{
                sm_act_state = LIST_VEHICLE_BY_USAGE;
                break;
            }
    }
    case SET_SERVICE_REQUIREMENT:{

    system("CLS");
    cout << "Kategoriankent szerviz igenybeveteli hatar beallitasa: " << endl;
        cout << "(1) Teherauto" << endl;
        cout << "(2) Busz" << endl;
        cout << "(3) Munkagép" << endl;
        cout << "(4) Vissza" << endl;
    char s;
    cin >> s;
            if(s == '1'){
        cout << endl << "Teherauto: ";
            cin >> sm_buffer;
                Van::setServiceReq(sm_buffer);
                sm_act_state = SET_SERVICE_REQUIREMENT;
                break;
            }
            else if(s == '2'){
        cout << endl << "Busz: ";
            cin >> sm_buffer;
                Bus::setServiceReq(sm_buffer);;
                sm_act_state = SET_SERVICE_REQUIREMENT;
                break;
            }
            else if(s == '3'){
        cout << endl << "Munkagep: ";
            cin >> sm_buffer;
                Machine::setServiceReq(sm_buffer);;
                sm_act_state = SET_SERVICE_REQUIREMENT;
                break;
            }
            else if(s == '4'){
                sm_act_state = MAIN_MENU;
                break;
            }
            else{
                sm_act_state = SET_SERVICE_REQUIREMENT;
                break;
            }
    }
    case LIST_SERVICE:{
        system("CLS");
        cout << "Service required: " << endl;
        for (int i = 0; i < sm_vector.size(); i++) {
            if(sm_vector.at(i)->getType()=="Teherauto"){
                if(((Van*)sm_vector.at(i))->getServiceReq() < sm_vector.at(i)->usage()){
                    sm_vector.at(i)->print();
                }
            }
            if(sm_vector.at(i)->getType()=="Busz"){
                if(((Bus*)sm_vector.at(i))->getServiceReq() < sm_vector.at(i)->usage()){
                    sm_vector.at(i)->print();
                }
            }
            if(sm_vector.at(i)->getType()=="Munkagep"){
                if(((Machine*)sm_vector.at(i))->getServiceReq() < sm_vector.at(i)->usage()){
                    sm_vector.at(i)->print();
                }
            }
        }
        cout << "(1) Szerviz igenybeveteli hatar beallitasa" << endl;
        cout << "(2) Back" << endl;
        char s;
        cin >> s;
            if(s == '1'){
                sm_act_state = SET_SERVICE_REQUIREMENT;
                break;
            }
            else if(s == '2'){
                sm_act_state = MAIN_MENU;
                break;
            }
            else{
                sm_act_state = LIST_SERVICE;
                break;
            }
    }

    case LICENCE_PLATE:
    {
    system("CLS");
    cout << endl << "Gep tipusa(teherauto(t),busz(b),munkagep(m)): ";
    char v;
    cin >> v;
    switch(v) {
    case 'b':{
        sm_vector.push_back(new Bus);
        break;}
    case 't':{
        sm_vector.push_back(new Van);
        break;}
    case 'm':{
        sm_vector.push_back(new Machine);
        break;}
    default:{
        cout << endl << "Rossz tipus";
        break;
    }
    }
            cout << endl << "Rendszam: ";
            cin >> sm_buffer;
            if (sm_buffer[0] == '<')
                sm_act_state = LICENCE_PLATE;
            else {
                sm_vector.at(sm_index)->setLicencePlate(sm_buffer);
                sm_act_state = YEAR;
            }
            break;
        }
        /*
        case TYPE:
            cout << endl << "Tipus";
            cin >> sm_buffer;
            if (sm_buffer[0] == '<')
                sm_act_state = LICENCE_PLATE;
            else {
                //sm_vector.at(sm_index)->setType(sm_buffer);
                sm_act_state = YEAR;
            }
            break;*/
        case YEAR:
            cout << endl << "Gyartasi ev: ";
            cin >> sm_buffer;
            if (sm_buffer[0] == '<')
                sm_act_state = LICENCE_PLATE;
            else {
                sm_vector.at(sm_index)->setYearOfManufacturing(sm_buffer);
                sm_act_state = CAPACITY;
            }
            break;
        case CAPACITY:
            cout << endl << "Kapacitas: ";
            cin >> sm_buffer;
            if (sm_buffer[0] == '<')
                sm_act_state = YEAR;
            else {
                sm_vector.at(sm_index)->setCapacity(sm_buffer);
                sm_act_state = USAGE;
            }
            break;
        case USAGE:
            cout << endl << "Igenybevetel: ";
            cin >> sm_buffer;
            if (sm_buffer[0] == '<')
                sm_act_state = CAPACITY;
            else {
                sm_vector.at(sm_index)->setUsage(sm_buffer);
                sm_act_state = LIST_A_VEHICLE;
            }
            break;
        case LIST_A_VEHICLE:

            system("CLS");

            sm_vector.at(sm_index)->print();
            ++sm_index;

            cout << "Uj jarmu hozzaadasa: n, Javitas: <, Kilepes: x" << endl;
            char c;
            cin >> c;
            switch(c) {
            case 'n':
                cout << "Uj jarmu hozzaadasa:" << endl;
                sm_act_state = LICENCE_PLATE;
                break;
            case '<':
                sm_act_state = USAGE;
                break;
            case 'x':
                sm_act_state = MAIN_MENU;
                break;
            }
            break;
        case LIST_ALL_VEHICLE:

            system("CLS");

            print();

            cout << "Uj jarmu hozzadasa: n, Vissza: b" << endl;
            cin >> c;
            switch(c) {
            case 'n':
                sm_act_state = LICENCE_PLATE;
                break;
            case 'b':
                sm_act_state = MAIN_MENU;
                break;
            }
            break;
    case SAVE_INTO_FILE:{
        write_To_File();
        sm_act_state = EXIT;
        break;
    }
        default:
            break;
        }
    }

void Menu::read_From_File(){
    string line, l;
    vector<vector<string>> input;
    ifstream SaveFile("VehiclesList.txt");
    while(getline(SaveFile, line)){
        vector<string> strings;

        stringstream input_stream(line);
        while(getline(input_stream, l, ';')){
            strings.push_back(l);
        }
        input.push_back(strings);
    }
    SaveFile.close();

    for(int i = 0; i < input.size(); i++){
        string tempLP = input.at(i).at(0);
        int tempYear = stoi(input.at(i).at(1));
        int tempCap = stoi(input.at(i).at(2));
        int tempUsage = stoi(input.at(i).at(3));
        string tempType = input.at(i).at(4);

        if(input.at(i).at(4) == "Munkagep"){
            sm_vector.push_back(new Machine(tempLP, tempYear, tempCap, tempUsage));
        }
        if(input.at(i).at(4) == "Teherauto"){
            sm_vector.push_back(new Van(tempLP, tempYear, tempCap, tempUsage));
        }
        if(input.at(i).at(4) == "Busz"){
            sm_vector.push_back(new Bus(tempLP, tempYear, tempCap, tempUsage));
        }
    }
    sm_index = sm_vector.size();
}
void Menu::write_To_File(){
  ofstream SaveFile("VehiclesList.txt", ofstream::trunc);
  if (SaveFile.is_open())
  {
    for(int i = 0; i < sm_vector.size(); i++){
        SaveFile << sm_vector.at(i)->licencePlate() << ';' << sm_vector.at(i)->manufacturingYear() << ';' << sm_vector.at(i)->capacity() << ';' << sm_vector.at(i)->usage() << ';' << sm_vector.at(i)->getType() << endl;
    }
    SaveFile.close();
  }
  else cout << "A fajlt nem lehetett megnyitni";
}
void Menu::print(){
    for(long i = 0; i < sm_vector.size(); ++i) {
        sm_vector.at(i)->print();
    }
}
Menu::~Menu(){
    sm_vector.clear();
}
