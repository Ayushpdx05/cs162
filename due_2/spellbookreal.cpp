#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <limits>
#include "catalog.h"

using namespace std;







/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:takign in all the functions to that the program works
 * ** Input:
 * ** Output: displaying the resutls wheter the user is a wizard or not 
 * ******************************************************/


//reason for more than 15 lines program requuired specific information to display so i could not use display spellbook
////i also have cout statments which are basic code which i could not modularize just for one or two
////i also neeeded to error handle mannualy to make sure the user could not enter a random letter or number
//
//
int main(){
string filename,filename_2;
ofstream outputfile;
ifstream inputfile;
ifstream inputfile_2;
cout << "please enter the name of your wizard info file and Spellbook file . " << endl;
cin >> filename; //wizard file
cin >> filename_2; //spells file
inputfile.open(filename.c_str());
inputfile_2.open(filename_2.c_str());
if (!inputfile){
    cout << "Not a Valid file Program will terminate . ";
    exit(1);
}
if (!inputfile_2){
    cout << "Not a Valid file Program will terminate . ";
    exit(1);
}
int size,size_2;
inputfile >> size;  //number of wizards
inputfile_2 >> size_2; //number of spellbooks
Wizard* wizard_arr = create_wizards(size); //creating a array of wizards
Spellbook* spellbook_arr = create_spellbooks(size_2);//creating a array of spellbooks
populate_spellbook_data(spellbook_arr,size_2, inputfile_2);    //populating both the wizards and the spellbooks
populate_wizard(wizard_arr,size,inputfile);
int check = user_entered_id(wizard_arr,size);
if ( check == 1) //if the user is a student the program will hide certain information
{
    cout << "your a student" << endl;
    using_options_students(spellbook_arr,size_2,outputfile);
}
else if (check == 0) //if the user is a non student it will show all the information
{
    cout << "your not a student" << endl;
    using_options_nonstudents(spellbook_arr,size_2,outputfile);
}
delete_info(&wizard_arr,&spellbook_arr,size_2);
}
