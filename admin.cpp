/// Railway Reservation Management System...
/// This code is written by 19-EE-012, 19-EE-028, 19-EE-044 & 19-EE-105...
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <cstring>
#include <iomanip>
#include<fstream>
#include <thread>
#include"reservation.h"
#include"main.h"
#include"control.h"
#include"admin.h"
using namespace std;



// Function to create Linked aList.
void aList::createaList(){

        Admin *temp;
        temp = new Admin;

        cin.ignore(256, '\n');

        cout<<"\n\t Enter User Name: ";
        getline(cin, temp->userName);

        cout<<"\t Enter User Password: ";
        getline(cin, temp->userPassword);

        cout<<"\t Enter User Type: ";
        getline(cin, temp->userType);

        temp->next = NULL;

if(first==NULL){

    first = temp;
    last = first;

    fstream myfile;

    myfile.open ("Admin.txt",ios::out | ios::app);
    myfile<<"User Name: "<<temp->userName<<" _|_ User Password: "<<temp->userPassword<<" _|_ User Type: "<<temp->userType<<endl;
    myfile.close();

    fstream myfile1;

    myfile1.open ("Credentials.txt",ios::out | ios::app);
    myfile1<<temp->userName<<endl<<temp->userPassword<<endl<<temp->userType<<endl;
    myfile1.close();


    cout<<"\n Data Entered Successfully."<<endl;
}
else{

    last-> next = temp;
    last = temp;

    fstream myfile;

    myfile.open ("Admin.txt",ios::out | ios::app);
    myfile<<"User Name: "<<temp->userName<<" _|_ User Password: "<<temp->userPassword<<" _|_ User Type: "<<temp->userType<<endl;
    myfile.close();

    fstream myfile1;

    myfile1.open ("Credentials.txt",ios::out | ios::app);
    myfile1<<temp->userName<<endl<<temp->userPassword<<endl<<temp->userType<<endl;
    myfile1.close();

    cout<<"\n Data Entered Successfully."<<endl;
}
}


// This function reads the data from file
void aList::loadaList(){
    string s;
    fstream myfile;

    myfile.open("Admin.txt",ios::in);

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




// Function to delete something from Linked aList.
void aList::deletaList(){

    string value;
    bool flag = false;

if(first == NULL){
    cout<<"\n -->No Data Available In Record.<--";
    return;
}
else{

    cin.ignore(256, '\n');

    cout<<"\n\n Enter The User Name: ";
    getline(cin, value);

    Admin *temp, *tempCur;
    temp = new Admin;
    tempCur = new Admin;
    temp = first;
    tempCur = first;

do{

if(value == temp->userName){

    flag=true;

    tempCur->next = temp->next;
    delete temp;

    cout<<"\n User Successfully Deleted. \n";

    return;
}

    tempCur = temp;
    temp = temp->next;

}while(temp != last->next);

if(!flag){
        cout<<"\n User Name: "<<value<<" Not Found In The Records";
}
}
}




void printAdmin(string t, const int& width){

    const char separator    = ' ';

    cout << left << setw(width) << setfill(separator) << t;
}


// Function to display data of Linked aList.
void aList::displayaList(){


if(first == NULL){
    cout<<"\n -->No Data Available In Record.<--";
    return;
}
else{

    const int nameWidth = 17;

    cout<<"\n ---> Displaying Admin Data. <---"<<endl;

    Admin *tempDisp;
    tempDisp = new Admin;
    tempDisp = first;


    int i = 1;

    cout<<endl;

    printAdmin(" Sr.", nameWidth);
    printAdmin("User Name", nameWidth);
    printAdmin("User Password", nameWidth);
    printAdmin("User Type", nameWidth);

    cout<<"\n=====================================================================================================";

do{

    cout<<"\n "<<i;
    printAdmin("", nameWidth);
        printAdmin(tempDisp->userName, nameWidth);
            printAdmin(tempDisp->userPassword, nameWidth);
                printAdmin(tempDisp->userType, nameWidth);

    tempDisp = tempDisp->next;
    i++;
}while(tempDisp != last->next);
}
}




// Function to search something in Linked aList.
void aList::searchaList(){

    string value;
    bool flag = false;
    const int nameWidth = 17;

if(first == NULL){
    cout<<"\n -->No Data Available In Record.<--";
    return;
}
else{
    cin.ignore(256, '\n');

    cout<<"\n Enter The User Name: ";
    getline(cin, value);

    Admin *temp;
    temp = new Admin;
    temp = first;

do{

if(temp->userName == value){

    flag=true;

    cout<<endl;

    printAdmin("User Name", nameWidth);
    printAdmin("User Password", nameWidth);
    printAdmin("User Type", nameWidth);

    cout<<"\n=====================================================================================================\n";

        printAdmin(temp->userName, nameWidth);
            printAdmin(temp->userPassword, nameWidth);
                printAdmin(temp->userType, nameWidth);


    return;
}
    temp = temp->next;
}while(temp != last->next);

if(!flag){
        cout<<"\n User Name: "<<value<<" Not Found In The Records";
}
}
}


void deleteAllRecord(){

    string perm;

    cout<<"\n Are You Sure, You Want To Delete All Record!...(Yes/No).";
    cin>>perm;

if(perm == "Yes" || perm == "yes"){

char filename1[] = "Admin.txt";
/*	Deletes the file if exists */
if (remove(filename1) != 0){
    perror("\n File deletion failed");
}
else{
    cout << "\n File deleted successfully";
}


char filename2[] = "Control.txt";
/*	Deletes the file if exists */
if (remove(filename2) != 0){
    perror("\n File deletion failed");
}
else{
    cout << "\n File deleted successfully";
}



char filename3[] = "Reservation.txt";
/*	Deletes the file if exists */
if (remove(filename3) != 0){
    perror("\n File deletion failed");
}
else{
    cout << "\n File deleted successfully";
}


char filename4[] = "Credentials.txt";
/*	Deletes the file if exists */
if (remove(filename4) != 0){
    perror("\n File deletion failed");
}
else{
    cout << "\n File deleted successfully";
}

}


}



// function to output as if it was being typed
void type_text1(const std::string& text){
    // loop through each character in the text
    for (std::size_t i = 0; i < text.size(); ++i){
        // output one character
        // flush to make sure the output is not delayed
        std::cout << text[i] << std::flush;

        // sleep 60 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
}
}



// Super Function For Admin.
void superFuncA(){

    aList A1;

    pList A2;

    cList A3;

    string choice;

while(true){
    system("CLS");
    char op;
    type_text1("\n-----ADMINISTRATOR CABIN-----\n");
    cout<<"\n\t 1. Create User Accounts.\n\t 2. Delete User Accounts.\n\t 3. Search For User Accounts.\n\t 4. Display User Accounts Record.\n\t 5. Display Recently Entered Data Of User Accounts.\n\t 6. Display Reservations Record.\n\t 7. Display Trains Timetable Record.\n\t 8. Delete All Records.\n\t 9. Go Back To Main Menu.\n\n Enter Your Choice: ";
    cin>>op;

switch(op){
    case '1':{
        A1.createaList();
        break;
}
    case '2':{
        A1.deletaList();
        break;
}
    case '3':{
        A1.searchaList();
        break;
}
    case '4':{
        A1.loadaList();
        break;
}
    case '5':{
        A1.displayaList();
        break;
}
    case '6':{
        A2.loadpList();
        break;
}
    case '7':{
        A3.loadcList();
        break;
}
    case '8':{
        deleteAllRecord();
        break;
}
    case '9':{
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

