/// Railway Reservation Management System...
/// This code is written by 19-EE-012, 19-EE-028, 19-EE-044 & 19-EE-105...
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <string>
#include <iomanip>
#include <thread>
#include"reservation.h"
#include"reception.h"
#include"main.h"
#include"control.h"
using namespace std;



// function to output as if it was being typed
void type_text3(const std::string& text){
    // loop through each character in the text
    for (std::size_t i = 0; i < text.size(); ++i){
        // output one character
        // flush to make sure the output is not delayed
        std::cout << text[i] << std::flush;

        // sleep 60 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
}
}





// Super Function For Reception.
void superFuncR(){

    pList A1;
    cList B1;
    string choice;

while(true){
    system("CLS");
    char op;
    type_text3("\n-----RECEPTION CABIN-----\n");
    cout<<"\n\t 1. Inquire For Reservations.\n\t 2. Inquire For Trains.\n\t 3. Go Back To Main Menu..\n\n Enter Your Choice: ";
    cin>>op;

switch(op){
    case '1':{
        A1.loadpList();
        break;
}
    case '2':{
        B1.loadcList();
        break;
}
    case '3':{
        enterCounter();
        break;
}
    default:{
        cout<<"\n Invalid operation entered."<<endl;
        break;
}
}
    cout<<"\n\n Press Any Key To Continue...";
    getch();
}
}

