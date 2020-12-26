/// Railway Reservation Management System...
/// This code is written by 19-EE-012, 19-EE-028, 19-EE-044 & 19-EE-105...
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <string>
#include <iomanip>
#include<fstream>
#include <thread>
#include"control.h"
#include"main.h"
using namespace std;



// Function to create Linked cList.
void cList::createcList(){

        Control *temp;

        temp = new Control;

        cin.ignore(256, '\n');

        cout<<"\n\t Enter Train No: ";
        getline(cin, temp->Tnum);

        cout<<"\t Enter Train Name: ";
        getline(cin, temp->Tname);

        cout<<"\t Train Is Coming From: ";
        getline(cin, temp->Tfrom);

        cout<<"\t Enter Destination: ";
        getline(cin, temp->Tdest);

        cout<<"\t Enter Arrival Time: ";
        getline(cin, temp->TcTime);

        cout<<"\t Enter Departure Time: ";
        getline(cin, temp->TdTime);

        cout<<"\t Enter Depo No: ";
        getline(cin, temp->Depo);

        temp->next = NULL;

if(first==NULL){
        first = temp;
        last = first;

        fstream myfile;

        myfile.open ("Control.txt",ios::out | ios::app);

        myfile<<"Train Number: "<<temp->Tnum<<" _|_ Train Name: "<<temp->Tname<<" _|_ Arriving From: "<<temp->Tfrom
        <<" _|_ Destined To: "<<temp->Tdest<<" _|_ Arriving Time: "<<temp->TcTime
        <<" _|_ Departure Time: "<<temp->TdTime<<" _|_ Depo No: "<<temp->Depo<<endl;

        myfile.close();


        cout<<"\n Data Entered Successfully."<<endl;
}
else{
        last-> next = temp;
        last = temp;

        fstream myfile;

        myfile.open ("Control.txt",ios::out | ios::app);

        myfile<<"Train Number: "<<temp->Tnum<<" _|_ Train Name: "<<temp->Tname<<" _|_ Arriving From: "<<temp->Tfrom
        <<" _|_ Destined To: "<<temp->Tdest<<" _|_ Arriving Time: "<<temp->TcTime
        <<" _|_ Departure Time: "<<temp->TdTime<<" _|_ Depo No: "<<temp->Depo<<endl;

        myfile.close();


        cout<<"\n Data Entered Successfully."<<endl;
}
}


// This function reads the data from file
void cList::loadcList(){
    string s;
    fstream myfile;

    myfile.open("Control.txt",ios::in);

if(!myfile){
    cout<<"\n Record Doesn't Exists...";
    return;
}

    cout<<endl;

while(!myfile.eof()){
    getline(myfile, s);
    cout<<s<<endl;
}
    cout<<endl;
    myfile.close();
}



// Function to delete something from Linked cList.
void cList::deletcList(){

    string value;
    bool flag = false;

if(first == NULL){
    cout<<"\n -->No Data Available In Record.<--";
    return;
}
else{

    cin.ignore(256, '\n');

    cout<<"\n\n Enter The Train Number / Name: ";
    getline(cin, value);

    Control *temp = new Control, *tempCur = new Control;
    temp = first;
    tempCur = first;

do{

if(temp->Tname == value || temp->Tnum == value){

    flag=true;

    tempCur->next = temp->next;

    delete temp;

    cout<<"\n Train Record Successfully Removed. \n";

    return;
}
    tempCur = temp;
    temp = temp->next;
}while(temp != last->next);
if(!flag){
        cout<<"\n Train Number / Name: "<<value<<" Not Found In The Records";
}
}
}




void printElement(string t, const int& width){

    const char separator    = ' ';

    cout << left << setw(width) << setfill(separator) << t;
}


// Function to display data of Linked cList.
void cList::displaycList(){

if(first == NULL){
    cout<<"\n -->No Data Available In Record.<--";
    return;
}
else{
    const int nameWidth = 17;

    cout<<"\n ---> Displaying Control Room Data. <---"<<endl;

    Control *temp = new Control;

    temp = first;

    int i = 1;

    cout<<endl;

    printElement(" Sr.", nameWidth);
    printElement("Train No.", nameWidth);
    printElement("Name", nameWidth);
    printElement("Arrival From", nameWidth);
    printElement("Destination", nameWidth);
    printElement("Arrival Time", nameWidth);
    printElement("Departure time", nameWidth);
    printElement("Depo No.", nameWidth);

    cout<<"\n======================================================================================================================================================";

while(temp != NULL){

    cout<<"\n "<<i;
    printElement("", nameWidth);
        printElement(temp->Tnum, nameWidth);
            printElement(temp->Tname, nameWidth);
                printElement(temp->Tfrom, nameWidth);
                    printElement(temp->Tdest, nameWidth);
                        printElement(temp->TcTime, nameWidth);
                            printElement(temp->TdTime, nameWidth);
                                printElement(temp->Depo, nameWidth);

    temp = temp->next;
    i++;
}
}
}



// Function to search something in Linked cList.
void cList::searchcList(){

    string value;
    bool flag = false;

if(first == NULL){
    cout<<"\n -->No Data Available In Records.<--";
    return;
}
else{
    cin.ignore(256, '\n');

    cout<<"\n Enter The Train Number / Name: ";
    getline(cin, value);

    Control *temp = new Control;
    temp = first;

do{

if(temp->Tname == value || temp->Tnum == value){

    flag=true;

    cout<<"\n Arrival Time Of Train No: "<<temp->Tnum<<" Is: "<<temp->TcTime<<" At Depo: "<<temp->Depo;

    return;
}
    temp = temp->next;
}while(temp != last->next);

if(!flag){
        cout<<"\n Train Number / Name: "<<value<<" Not Found In The Records";
}
}
}

// function to output as if it was being typed
void type_text2(const std::string& text){
    // loop through each character in the text
    for (std::size_t i = 0; i < text.size(); ++i){
        // output one character
        // flush to make sure the output is not delayed
        std::cout << text[i] << std::flush;

        // sleep 60 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
}
}


// Super Function For Control.
void superFuncC(){

    cList A1;

    string choice;

while(true){
    system("CLS");
    char op;
    type_text2("\n-----CONTROL ROOM-----\n");
    cout<<"\n\t 1. Enter Incoming Train In Timetable.\n\t 2. Delete A Train From Timetable.\n\t 3. Inquire For A Train.\n\t 4. Load Data From Database.\n\t 5. Display Train Timetable.\n\t 6. Go Back To Main Menu.\n\n Enter Your Choice: ";
    cin>>op;

switch(op){
    case '1':{
        A1.createcList();
        break;
}
    case '2':{
        A1.deletcList();
        break;
}
    case '3':{
        A1.searchcList();
        break;
}
    case '4':{
        A1.loadcList();
        break;
}
    case '5':{
        A1.displaycList();
        break;
}
    case '6':{
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

