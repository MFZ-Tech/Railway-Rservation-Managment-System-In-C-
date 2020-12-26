/// Railway Reservation Management System...
/// This code is written by 19-EE-012, 19-EE-028, 19-EE-044 & 19-EE-105...
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <string>
#include <iomanip>
#include<fstream>
#include"main.h"
#include"reservation.h"
#include"reception.h"
#include"control.h"
#include"admin.h"
#include"userlogin.h"
using namespace std;


void userlogin(char op){

    string choice, adminUserName = "Admin", adminPassword = "Admin", adminUser, adminPass;
    string uName, uPassword, s;
    bool login = false;
    fstream myfile;

while(true){
    system("CLS");
switch(op){
    case '1':{
        myfile.open("Credentials.txt",ios::in);

if(!myfile){
        cout<<"\n No Users Created By Admin.";
        return;
}
        cout<<endl;
        cout<<"\t User Login Page";
        cout<<"\n\n Enter User Name: ";
        cin>>uName;
        cout<<" Enter User Password: ";
        cin>>uPassword;

while(!myfile.eof()){
        getline(myfile, s);
if(s == uPassword){
        cout<<"\n Login Successful, Press any key to continue...";
        getch();
        login = true;
        myfile.close();
        superFuncR();
}
}
if(!login){
        cout<<"\n Invalid Credentials, Try Again. \n";
}
        myfile.close();
        break;
}
    case '2':{
        myfile.open("Credentials.txt",ios::in);

if(!myfile){
        cout<<"\n No Users Created By Admin.";
        return;
}
        cout<<endl;
        cout<<"\t User Login Page";
        cout<<"\n\n Enter User Name: ";
        cin>>uName;
        cout<<" Enter User Password: ";
        cin>>uPassword;

while(!myfile.eof()){
        getline(myfile, s);
if(s == uPassword){
        cout<<"\n Login Successful, Press any key to continue...";
        getch();
        login = true;
        myfile.close();
        superFuncP();
}
}
if(!login){
        cout<<"\n Invalid Credentials, Try Again. \n";
}
        myfile.close();
        break;
}
    case '3':{
        myfile.open("Credentials.txt",ios::in);

if(!myfile){
        cout<<"\n No Users Created By Admin.";
        return;
}
        cout<<endl;
        cout<<"\t User Login Page";
        cout<<"\n\n Enter User Name: ";
        cin>>uName;
        cout<<" Enter User Password: ";
        cin>>uPassword;

while(!myfile.eof()){
        getline(myfile, s);
if(s == uPassword){
        cout<<"\n Login Successful, Press any key to continue...";
        getch();
        login = true;
        myfile.close();
        superFuncC();
}
}
if(!login){
        cout<<"\n Invalid Credentials, Try Again. \n";
}
        myfile.close();
        break;
}
    case '4':{
        cout<<"\t Admin Login Page";
        cout<<"\n\n Enter Admin User Name: ";
        cin>>adminUser;
        cout<<" Enter Admin Password: ";
        cin>>adminPass;
if(adminUser == adminUserName && adminPass == adminPassword){
        cout<<"\n Login Successful, Press any key to continue...";
        getch();
        superFuncA();
}
else{
        cout<<"\n Invalid Credentials, Try Again. \n";
}

        break;
}
    default:{
        cout<<"\n Invalid operation entered."<<endl;
        break;
}
}
    cout<<"\n\n----------PRESS X TO GO BACK TO MAIN MENU-----PRESS Y TO RETRY---------- ";
    cin>>choice;
    system("CLS");
    cout<<""<<endl;
    if(choice == "x")
    break;
}
}
