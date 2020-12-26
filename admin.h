/// Railway Reservation Management System...
/// This code is written by 19-EE-012, 19-EE-028, 19-EE-044 & 19-EE-105...
#ifndef ADMIN_H
#define ADMIN_H

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <string>
#include <iomanip>
using namespace std;


void superFuncA();


// Creation of ADT for Admin.
class Admin{
public:
    string userName, userPassword, userType;
    Admin* next;
};



// Creation of Linked aList.
class aList:public Admin{
private:
    Admin *first,*last;
public:
    aList(){

        first = NULL;
        last = NULL;
}
    void createaList();
    void deletaList();
    void displayaList();
    void searchaList();
    void loadaList();
    void deleteAllRecord();
    ~aList(){
        delete first;
        first = NULL;
        delete last;
        last = NULL;
}
};



#endif
