/// Railway Reservation Management System...
/// This code is written by 19-EE-012, 19-EE-028, 19-EE-044 & 19-EE-105...
#ifndef RESERVATION_H
#define RESERVATION_H

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <string>
#include <iomanip>
using namespace std;


void superFuncP();


// Creation of ADT for Passenger.
class Passenger{
public:
    string tNo, Pname, destination, Pclass, luggage, seatNo, trainName, depoNo;
    Passenger* next;
};



// Creation of Linked pList.
class pList:public Passenger{
private:
    Passenger *first,*last;
public:
    pList(){

        first = NULL;
        last = NULL;
}
    void createpList();
    void deletpList();
    void displaypList();
    void searchpList();
    void loadpList();
    ~pList(){
        delete first;
        first = NULL;
        delete last;
        last = NULL;
}
};



#endif
