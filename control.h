/// Railway Reservation Management System...
/// This code is written by 19-EE-012, 19-EE-028, 19-EE-044 & 19-EE-105...
#ifndef CONTROL_H
#define CONTROL_H

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <string>
#include <iomanip>
using namespace std;


void superFuncC();


// Creation of ADT for Control.
class Control{
public:
    string Tnum, Tname, Tfrom, Tdest, TcTime, TdTime, Depo;
    Control* next;
};



// Creation of Linked cList.
class cList:public Control{
private:
    Control *first,*last;
public:
    cList(){

        first = NULL;
        last = NULL;
}
    void createcList();
    void deletcList();
    void displaycList();
    void searchcList();
    void loadcList();
    ~cList(){
        delete first;
        first = NULL;
        delete last;
        last = NULL;
}
};



#endif
