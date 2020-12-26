/// Railway Reservation Management System...
/// This code is written by 19-EE-012, 19-EE-028, 19-EE-044 & 19-EE-105...
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <string>
#include <iomanip>
#include<fstream>
#include <thread>
#include"reservation.h"
#include"main.h"
using namespace std;



// Function to create Linked pList.
void pList::createpList(){

        Passenger *temp;

        temp = new Passenger;

        cin.ignore(256, '\n');

        cout<<"\n\t Enter Ticket No: ";
        getline(cin, temp->tNo);

        cout<<"\t Enter Name: ";
        getline(cin, temp->Pname);

        cout<<"\t Enter Destination: ";
        getline(cin, temp->destination);

        cout<<"\t Enter Class: ";
        getline(cin, temp->Pclass);

        cout<<"\t Enter Luggage: ";
        getline(cin, temp->luggage);

        cout<<"\t Enter seat No: ";
        getline(cin, temp->seatNo);

        cout<<"\t Enter Train Name: ";
        getline(cin, temp->trainName);

        cout<<"\t Enter Depo No: ";
        getline(cin, temp->depoNo);

        temp->next = NULL;

if(first==NULL){
        first = temp;
        last = first;

        fstream myfile;

        myfile.open ("Reservation.txt",ios::out | ios::app);

        myfile<<"Ticket No: "<<temp->tNo<<" _|_ Passenger Name: "<<temp->Pname<<" _|_ Destined For: "<<temp->destination
        <<" _|_ Class: "<<temp->Pclass<<" _|_ Luggage: "<<temp->luggage
        <<" _|_ Seat No: "<<temp->seatNo<<" _|_ Train Name: "<<temp->trainName<<" _|_ Depo No: "<<temp->depoNo<<endl;

        myfile.close();


        cout<<"\n Data Entered Successfully."<<endl;
}
else{
        last-> next = temp;
        last = temp;

        fstream myfile;

        myfile.open ("Reservation.txt",ios::out | ios::app);

        myfile<<"Ticket No: "<<temp->tNo<<" _|_ Passenger Name: "<<temp->Pname<<" _|_ Destined For: "<<temp->destination
        <<" _|_ Class: "<<temp->Pclass<<" _|_ Luggage: "<<temp->luggage
        <<" _|_ Seat No: "<<temp->seatNo<<" _|_ Train Name: "<<temp->trainName<<" _|_ Depo No: "<<temp->depoNo<<endl;

        myfile.close();


        cout<<"\n Data Entered Successfully."<<endl;
}
}


// This function reads the data from file
void pList::loadpList(){
    string s;
    fstream myfile;

    myfile.open("Reservation.txt",ios::in);

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




// Function to delete something from Linked pList.
void pList::deletpList(){

    string value;
    bool flag = false;

if(first == NULL){
    cout<<"\n -->No Data Available In Record.<--";
    return;
}
else{

    cin.ignore(256, '\n');

    cout<<"\n\n Enter the Ticket Number / Name: ";
    getline(cin, value);

    Passenger *temp = new Passenger, *tempCur = new Passenger;
    temp = first;
    tempCur = first;

do{

if(temp->Pname == value || temp->tNo == value){

    flag=true;

    tempCur->next = temp->next;
    delete temp;

    cout<<"\n Reservation Successfully Canceled. \n";

    return;
}
    tempCur = temp;
    temp = temp->next;
}while(temp != last->next);
if(!flag){
        cout<<"\n Ticket Number / Name: "<<value<<" Not Found In The Records";
}
}
}




void print(string t, const int& width){

    const char separator    = ' ';

    cout << left << setw(width) << setfill(separator) << t;
}


// Function to display data of Linked pList.
void pList::displaypList(){

if(first == NULL){
    cout<<"\n -->No Data Available In Record.<--";
    return;
}
else{
    const int nameWidth = 17;

    cout<<"\n ---> Displaying Passenger Data. <---"<<endl;

    Passenger *temp = new Passenger;
    temp = first;

    int i = 1;

    cout<<endl;

    print(" Sr.", nameWidth);
    print("Ticket No.", nameWidth);
    print("Passenger", nameWidth);
    print("Destination", nameWidth);
    print("Class", nameWidth);
    print("Luggage", nameWidth);
    print("Seat No.", nameWidth);
    print("Train Name", nameWidth);
    print("Depo No.", nameWidth);

    cout<<"\n======================================================================================================================================================";

while(temp != NULL){

    cout<<"\n "<<i;
    print("", nameWidth);
        print(temp->tNo, nameWidth);
            print(temp->Pname, nameWidth);
                print(temp->destination, nameWidth);
                    print(temp->Pclass, nameWidth);
                        print(temp->luggage, nameWidth);
                            print(temp->seatNo, nameWidth);
                                print(temp->trainName, nameWidth);
                                    print(temp->depoNo, nameWidth);
    temp = temp->next;
    i++;
}
}
}



// Function to search something in Linked pList.
void pList::searchpList(){

    string value;
    bool flag = false;

if(first == NULL){
    cout<<"\n -->No Data Available In Record.<--";
    return;
}
else{
    cin.ignore(256, '\n');

    cout<<"\n Enter the Ticket Number / Name: ";
    getline(cin, value);

    Passenger *temp = new Passenger;
    temp = first;

do{

if(temp->Pname == value || temp->tNo == value){

    flag=true;

    cout<<"\n Seat No: "<<temp->seatNo<<" Is Already Reserved For Ticket Number / Name: "<<value;

    return;
}
    temp = temp->next;
}while(temp != last->next);

if(!flag){
        cout<<"\n Ticket Number / Name: "<<value<<" Not Found In The Records";
}
}
}


// function to output as if it was being typed
void type_text4(const std::string& text){
    // loop through each character in the text
    for (std::size_t i = 0; i < text.size(); ++i){
        // output one character
        // flush to make sure the output is not delayed
        std::cout << text[i] << std::flush;

        // sleep 60 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
}
}




// Super Function For Passenger.
void superFuncP(){

    pList A1;

    string choice;

while(true){
    system("CLS");
    char op;
    type_text4("\n-----RESERVATIONS CABIN-----\n");
    cout<<"\n\t 1. Book A Reservation.\n\t 2. Cancel A Reservation.\n\t 3. Inquire For Reservations.\n\t 4. Display Reservations Record.\n\t 5. Display Recent Reservations.\n\t 6. Go Back To Main Menu.\n\n Enter Your Choice: ";
    cin>>op;

switch(op){
    case '1':{
        A1.createpList();
        break;
}
    case '2':{
        A1.deletpList();
        break;
}
    case '3':{
        A1.searchpList();
        break;
}
    case '4':{
        A1.loadpList();
        break;
}
    case '5':{
        A1.displaypList();
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

