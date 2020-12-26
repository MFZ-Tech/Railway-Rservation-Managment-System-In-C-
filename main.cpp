/// Railway Reservation Management System...
/// This code is written by 19-EE-012, 19-EE-028, 19-EE-044 & 19-EE-105...
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <string>
#include <iomanip>
#include <thread>
#include"main.h"
#include"userlogin.h"
using namespace std;


// function to output as if it was being typed
void type_text(const std::string& text){
    // loop through each character in the text
    for (std::size_t i = 0; i < text.size(); ++i){
        // output one character
        // flush to make sure the output is not delayed
        std::cout << text[i] << std::flush;

        // sleep 60 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
}
}


void about_Dev(){
    cout<<"\n The Code For This Project Is Developed By Following Developers. \n";
    type_text("\n-----Group Members-----\n");
    cout<<"\n\t 1. Muhammad Umer (19-EE-012).\n\t 2. Anas Zahid (19-EE-028).\n\t 3. Muhammad Nabeel Tahir (19-EE-044).\n\t 4. Mirza Fahad Baig (19-EE-105).";
}

void enterCounter(){

    string choice, keyP;

while(true){
    system("CLS");
    char op;
    type_text("\n-----MAIN MENU-----\n");
    cout<<"\n\t 1. Reception Cabin.\n\t 2. Reservation Cabin.\n\t 3. Control Room.\n\t 4. Administrator Cabin.\n\t 5. About Developer.\n\t 6. Exit Program.\n\n Enter Your Choice: ";
    cin>>op;

switch(op){
    case '1':{
        userlogin('1');
        break;
}
    case '2':{
        userlogin('2');
        break;
}
    case '3':{
        userlogin('3');
        break;
}
    case '4':{
        userlogin('4');
        break;
}
    case '5':{
        about_Dev();
        break;
}
    case '6':{
        cout<<"\n Are You Sure, You Want To Exit Program!...(Yes, No).";
        cin>>keyP;
        if(keyP == "Yes" || keyP == "yes"){
        type_text("\n\t\t -->Good Bye.<--\n");
        type_text("\n Press any key to Exit...");
        getch();
        cout<<endl;
        exit(0);
}
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



void welcome(){
    type_text("\n\t -->Railway Reservation Management System.<--");
    type_text("\n\n\t\t -->WELCOME.<--");
    type_text("\n\n Press any key to Continue...");
    getch();
    system("CLS");
    enterCounter();
}



// Main Method.
int main(){
    system("Color F3");
    type_text("\t\t -->DSA LAB Project<--\n");
    welcome();
	return 0;
}
