#include <iostream>
#include <string>
#include <fstream>
#include "catalog.h"
#include <limits>
using namespace std;



/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:allocating memory for wizards to use in later functions
 * ** Input:the amount AKA the int size
 * ** Output:memory will be allocated for wizards
 * ******************************************************/
Wizard * create_wizards(int size){
Wizard * sorcer = new Wizard [size];
return sorcer;
}


/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:allocating memory for spellbooks 
 * ** Input:number of spellbooks which will be read by ifstream
 * ** Output:memory allocated for spellbooks
 * ******************************************************/

Spellbook * create_spellbooks(int size_2){
Spellbook * pages = new Spellbook[size_2];
return pages;
}


/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:allocating memory for spells
 * ** Input:number of spells which will be read from aspellbook
 * ** Output:memory allocated for spellbooks
 * ******************************************************/


Spell * create_spells(int size_2){
Spell * spellz = new Spell[size_2];
return spellz;
}


/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:populating spells using ifstream. will read in spell data so that it can be refrenced later.
 * ** Input:spell array, number of spells which will be read from the file, file from using read using ifstream
 * ** Output:populated spelldata
 * ******************************************************/


void populate_spell_data(Spell * spell_arr,int size_2,ifstream & inputfile_2){
   for (int i = 0; i < size_2; i++)
   {
    inputfile_2 >> spell_arr[i].name >> spell_arr[i].success_rate >> spell_arr[i].effect ;
   }
   
}


/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:populating spellbook data using ifstream inputfile to read in data from the 2 file the user inputs
 * ** Input:the spellbook array, size of the file and the inputfile which
 * ** Output:populated spellbook data
 * ******************************************************/



void populate_spellbook_data(Spellbook* spellbook_arr, int size_2, ifstream & inputfile_2){
    for(int i = 0; i < size_2;i++){
        
        inputfile_2 >> spellbook_arr[i].title >> spellbook_arr[i].author >> spellbook_arr[i].num_pages 
                    >> spellbook_arr[i].edition >> spellbook_arr[i].num_spells;
        
        spellbook_arr[i].s = create_spells(spellbook_arr[i].num_spells); // allocate memory for spells
        
        populate_spell_data(spellbook_arr[i].s,spellbook_arr[i].num_spells,inputfile_2);
    
    }
}




/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:displaying spellbook in the format so that the user can see the title the author ect.
 * ** Input:taking in spellbook array and int i so we know the index at which it is at
 * ** Output:displaying spellbook data in the format so the user can see it.
 * ******************************************************/

void displaying_spellbook(Spellbook * spellbook_arr,int i){

cout << "spellbook title : " << spellbook_arr[i].title << endl;
cout << "spellbook author : " << spellbook_arr[i].author << endl;
cout << "spellbook number of pages : " << spellbook_arr[i].num_pages << endl;
cout << "spellbook edition : " << spellbook_arr[i].edition << endl;
cout << "spellbook num : " << spellbook_arr[i].num_spells<< endl;

for (int j = 0; j < spellbook_arr[i].num_spells; j++) //looping through each spell individually
{
    cout << " Spell Name :" <<  spellbook_arr[i].s[j].name << "Spell Effect :" <<spellbook_arr[i].s[j].effect;
}
}


/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Ayush SIngh
 * ** Date: 01/30/2023
 * ** Description:populating wizard data reading in from the file
 * ** Input:wizard array, the size of the wizards and inputfile
 * ** Output:data will be read so we can use it to display it later
 * ******************************************************/



void populate_wizard(Wizard* wizard_arr, int size, ifstream & inputfile){
for (int i = 0; i < size; i++) //looping through the "size" of the array of wizards created in the main function
{
     inputfile >> wizard_arr[i].name >> wizard_arr[i].id >> wizard_arr[i].password >> wizard_arr[i].position_title >> wizard_arr[i].beard_length;
}
}



/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:displaying wizard data so that the user can read it properly
 * ** Input:takign in wizard array and the index at whih it is at.
 * ** Output:
 * ******************************************************/



void Displaying_wizard(Wizard * wizard_arr,int i){
cout << "wizard name " << wizard_arr[i].name << endl;
cout << "wizard ID " << wizard_arr[i].id << endl;
cout << "wizard Position " << wizard_arr[i].position_title << endl;
cout << "wizard beard " << wizard_arr[i].beard_length << endl;
}



/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:giving the user 3 tries to enter correct user anme and password 
 * ** Input:takign in wizard array and the size of the wizard text
 * ** Output:displaying the options to the user
 * ******************************************************/
//reason for more than 15 lines program requuired specific information to display so i could not use display spellbook
////i also have cout statments which are basic code which i could not modularize just for one or two
////i also neeeded to error handle mannualy to make sure the user could not enter a random letter or number
//
//




int user_entered_id(Wizard* wizard_arr, int size) {
  int id, check = -1;
  string pass;
  int tries = 0;
  while (tries < 3) {
    cout << "Please enter user id and password: ";
    if (!(cin >> id)) {
      cout << "Invalid input. User ID should be an integer." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    cin >> pass;
    for (int i = 0; i < size; i++) {
      if (wizard_arr[i].id == id && wizard_arr[i].password == pass) {
        Displaying_wizard(wizard_arr, i);
        if (wizard_arr[i].position_title == "Student") {
          check = 1;
          break;
        } else {
          check = 0;
          break;
        }
      }
    }
    if (check != -1) {
      break;
    } else {
      cout << "No match found." << endl;
    }
    ++tries;
  }
  return check;
}



/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:giving the user options to enter on how they would like to search through the data
 * ** Input:no input
 * ** Output:returning the option they gave
 * ******************************************************/
//reason for more than 15 lines program requuired specific information to display so i could not use display spellbook
////i also have cout statments which are basic code which i could not modularize just for one or two
////i also neeeded to error handle mannualy to make sure the user could not enter a random letter or number
//
//



int options(){
 int optionz;

 cout << "1. search spellbook by its name" << endl;
 cout << "2. search spellbook by number of pages" << endl;
 cout << "3. search spells by effect" << endl;
 cout << "4. quit program" << endl;


 while (!(cin >> optionz) || optionz < 1 || optionz > 4) {
   cout << "Invalid input. Please enter a number between 1 and 4." << endl;
   cin.clear();
   cin.ignore(numeric_limits<streamsize>::max(), '\n');  //ignoring any characheters entered so the loop doesnt freak out and making sure they enter a number 1-4.
   cin>>optionz;
 }
return optionz;
}





/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:taking in there choice of wheter they want to show the information in the terminal or display it in another file
 * ** Input:no inputs
 * ** Output:returning the value wheter its a 1 or a 22
 * ******************************************************/
//reason for more than 15 lines program requuired specific information to display so i could not use display spellbook
////i also have cout statments which are basic code which i could not modularize just for one or two
////i also neeeded to error handle mannualy to make sure the user could not enter a random letter or number
//
//



int printofile(){
int choice;
cout << " would you like to print (2) to the file or terminal(1)" << endl;
while (!(cin >> choice) || (choice != 1 && choice != 2)) {
   cout << "Invalid input. Please enter either 1 or 2." << endl;
   cin.clear();
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   cin >> choice;
 }
return choice;
}




/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:searching through the data to find if the user enter a correct name
 * ** Input:spellbook array the number of books and ofstream if the user would like to append the information to a file
 * ** Output:displaying results of what the user choose
 * ******************************************************/
//reason for more than 15 lines program requuired specific information to display so i could not use display spellbook
////i also have cout statments which are basic code which i could not modularize just for one or two
////i also neeeded to error handle mannualy to make sure the user could not enter a random letter or number
//
//



void searching_name(Spellbook * spellbook_arr, int numbooks,ofstream & outputfile) { //nonstudents
    int choice = printofile();
    string book,name;
    cout << "please enter valid book name" << endl;
    cin >> book;
    if (choice == 1)//printing to the terminal
    {
    bool found = false;  
    for (int i = 0; i < numbooks; i++) {
        if (spellbook_arr[i].title == book) {
                displaying_spellbook(spellbook_arr, i);
                found = true;            
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
    }
    if (choice == 2) //printing to a file
    {
      cout << "please enter name of file you would like to out put to " << endl;
      cin >> name;
      outputfile.open(name.c_str(),ios::app);
      bool found_2 = false;  
    for (int i = 0; i < numbooks; i++) {
        if (spellbook_arr[i].title == book) {
               
            outputfile << "spellbook title : " << spellbook_arr[i].title << endl;
            outputfile << "spellbook author : " << spellbook_arr[i].author << endl;
            outputfile << "spellbook number of pages : " << spellbook_arr[i].num_pages << endl;
            outputfile << "spellbook edition : " << spellbook_arr[i].edition << endl;
            outputfile << "spellbook num : " << spellbook_arr[i].num_spells<< endl;

            for (int j = 0; j < spellbook_arr[i].num_spells; j++)
            {
              outputfile << " Spell Name :" <<  spellbook_arr[i].s[j].name << "Spell Effect :" <<spellbook_arr[i].s[j].effect;
              }   
                found_2 = true;            
                outputfile.close();
        }
    }
    if (!found_2) {
        cout << "Book not found." << endl;
    }
    }
    
}



/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:searching through the data to find the name of the book if the user is a student
 * ** Input:spellbook array the number of books and ofstream if they would like to append the information to a file
 * ** Output:displaying the name of the book
 * ******************************************************/
//reason for more than 15 lines program requuired specific information to display so i could not use display spellbook
////i also have cout statments which are basic code which i could not modularize just for one or two
////i also neeeded to error handle mannualy to make sure the user could not enter a random letter or number
//
//


void searching_name_students(Spellbook * spellbook_arr, int numbooks,ofstream & outputfile) {
    int choice = printofile();
    string book,name;
    cout << "please enter valid book name" << endl;
    cin >> book;
  if (choice == 1) {
  bool found = false;
  for (int i = 0; i < numbooks; i++) {
      if (spellbook_arr[i].title == book) {
        for ( int j = 0; j < spellbook_arr[i].num_spells; j++)
        {
          if (spellbook_arr[i].s[j].effect.find("death") != std::string::npos || spellbook_arr[i].s[j].effect.find("poison") != std::string::npos)
            {
              cout << "sorry this book contains death or poison" << endl;
              found = true;
              break;
            }
        }
        if (!found) {
          displaying_spellbook(spellbook_arr, i);
          found = true;
        }
        break;
      }
  }
  if (!found) {
    cout << "Book not found." << endl;
  }
} 
else if (choice == 2)
    {
      cout << "please enter name of file you would like to output too" << endl;
      cin >> name;
      outputfile.open(name.c_str(),ios::app);
      bool found_2 = false;  
    for (int i = 0; i < numbooks; i++) {
        for (int j = 0; j < spellbook_arr[i].num_spells; j++){
        if (spellbook_arr[i].title == book) {
                if (spellbook_arr[i].s[j].effect == "death" || spellbook_arr[i].s[j].effect == "poison")
                {
                  cout << "sorry this book contains death or poison" << endl;
                }
                else{
                outputfile << "spellbook title : " << spellbook_arr[i].title << endl;
                outputfile << "spellbook author : " << spellbook_arr[i].author << endl;
                outputfile << "spellbook number of pages : " << spellbook_arr[i].num_pages << endl;
                outputfile << "spellbook edition : " << spellbook_arr[i].edition << endl;
                outputfile << "spellbook num : " << spellbook_arr[i].num_spells<< endl;

                outputfile << " Spell Name : " <<  spellbook_arr[i].s[j].name << "Spell Effect : " <<spellbook_arr[i].s[j].effect;

                found_2 = true;  
                
                }
                outputfile.close();          
        }
    }
    }
    }
}


/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:searching by effect if they are a student only given 3 options and hiding the rest
 * ** Input:the spellbook array the number of books and ofstream if they want to print
 * ** Output:displaying the results wheter they want it in a file or terminal
 * ******************************************************/
//reason for more than 15 lines program requuired specific information to display so i could not use display spellbook
////i also have cout statments which are basic code which i could not modularize just for one or two
////i also neeeded to error handle mannualy to make sure the user could not enter a random letter or number
//
//


void search_by_effect_student(Spellbook *spellbook_arr, int numbook,ofstream & outputfile) {
  int choice = printofile();
  string search_effects,name;
  cout << "Decide which effect you would like to search by: fire , bubble , memory_loss  " << endl;
  cin >> search_effects;
  if (choice == 1)
  {  
    bool found = false;
  for (int i = 0; i < numbook; i++) {
   if (search_effects == "poison" ||search_effects == "death")
      {
        cout << "sorry you cant see that" << endl;
        break;
      }
   for (int j = 0; j < spellbook_arr[i].num_spells; j++)
   { 
    if(spellbook_arr[i].s[j].effect == search_effects) { 
      
      cout << "Spell Name: " << spellbook_arr[i].s[j].name << endl;
      cout << "Spell Effect: " << spellbook_arr[i].s[j].effect << endl;
      found = true;
     }
    }
   }
  if(!found)
   {
    cout << " this spell does not exist " << endl;
   }
  }
  if (choice == 2)
  {
    bool found_2 = false;
    cout << "which file would you like to store the effects to ?" << endl;
    cin >> name;
    outputfile.open(name.c_str(), ios::app);
   for (int i = 0; i < numbook; i++) {
   for (int j = 0; j < spellbook_arr[i].num_spells; j++)
   {
    if (spellbook_arr[i].s[j].effect == search_effects) {
      outputfile << "Spell Name: " << spellbook_arr[i].s[j].name << endl;
      outputfile << "Spell Effect: " << spellbook_arr[i].s[j].effect << endl;
      found_2 = true;
    }
   } 
   outputfile.close();
  }
  if (!found_2) {
    cout << "No spells found with the specified effect." << endl;  
  }
  }
}

/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:searching for the upper limit of pages the user has entered
 * ** Input:the spellbook array, the number of books and ofstream if they want the information appened to a file
 * ** Output:displaying the results
 * ******************************************************/
//reason for more than 15 lines program requuired specific information to display so i could not use display spellbook
////i also have cout statments which are basic code which i could not modularize just for one or two
////i also neeeded to error handle mannualy to make sure the user could not enter a random letter or number
//
//



void searching_num_pages(Spellbook * spellbook_arr,int numbooks,ofstream & outputfile){
int choice = printofile();
int num_pages;
string name;
cout << "please enter upper limit of pages" << endl;
cin >> num_pages;
bool found = false;
if(choice == 1){
for (int i = 0; i < numbooks; i++)
{ 
  if (spellbook_arr[i].num_pages <= num_pages)
  {
    cout << "Title :" << spellbook_arr[i].title << " Pages :  " <<  spellbook_arr[i].num_pages << endl;
    found = true;
  } 
}
if (!found)
  {
    cout << "not found" << endl;
  }
}
if (choice == 2){
{  
  cout << "enter the name of file you would like to add this information to " << endl;
  cin >> name;
  outputfile.open(name.c_str());
  bool found_2 = false;
  for (int i = 0; i < numbooks; i++)
{
  if (spellbook_arr[i].num_pages <= num_pages)
  {
    outputfile << "Title :" << spellbook_arr[i].title ;
    outputfile << " Pages :  " <<  spellbook_arr[i].num_pages << endl;
    found_2 = true;
  } 
}
if (!found_2)
  {
    cout << "not found" << endl;
  }
outputfile.close();
}
}
}


/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:displaying results if they are a student and hiding the books with death adn poison
 * ** Input:taking in spellbook array, number of books and ofstream to appened info to a file
 * ** Output:displaying the info how the user decides
 * ******************************************************/
//reason for more than 15 lines program requuired specific information to display so i could not use display spellbook
////i also have cout statments which are basic code which i could not modularize just for one or two
////i also neeeded to error handle mannualy to make sure the user could not enter a random letter or number
//
//



void searching_num_pages_students(Spellbook * spellbook_arr,int numbooks,ofstream & outputfile){
int choice = printofile();
int num_pages;
string name;
cout << "please enter upper limit of pages" << endl;
cin >> num_pages;
if(choice == 1){
bool found = false;
for (int i = 0; i < numbooks; i++)
{  
  for ( int j = 0; j < spellbook_arr[i].num_spells; j++)
  {
    if (spellbook_arr[i].num_pages <= num_pages)  {
        if (spellbook_arr[i].s[j].effect.find("death") != std::string::npos || spellbook_arr[i].s[j].effect.find("poison") != std::string::npos)
        {
          cout << " sorry this book contains posion or death " << endl;
          found = true;
          break;
        } 
        
  }
}
if (!found)
{
  cout << " Title : " << spellbook_arr[i].title << " pages : " << spellbook_arr[i].num_pages;
  found = true;
}
break;
}
if (!found)
{
  cout << " sorry book not found" << endl;
}
}
if (choice == 2)
{
  cout << " please enter name of file "  << endl;
  cin >> name;
  outputfile.open(name.c_str(),ios::app);
  bool found_2 = false;
for (int i = 0; i < numbooks; i++)
{  
  for ( int j = 0; j < spellbook_arr[i].num_spells; j++)
  {
    if (spellbook_arr[i].num_pages <= num_pages)  {
        if (spellbook_arr[i].s[j].effect.find("death") != std::string::npos || spellbook_arr[i].s[j].effect.find("poison") != std::string::npos)
        {
          cout << "sorry this book contains death or poison " << endl;
          found_2 = true;
          break;
        } 
        
  }
}
if (!found_2)
{
  outputfile << " Title : " << spellbook_arr[i].title << " pages : " << spellbook_arr[i].num_pages;
  found_2 = true;
  outputfile.close();
}
break;
}
if (!found_2)
{
  cout << " sorry book not found" << endl;
}


}
}

/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:searching by effects for a non student
 * ** Input:spellbook array, number of books and ofstream file
 * ** Output:displaying the effects 
 * ******************************************************/
//reason for more than 15 lines program requuired specific information to display so i could not use display spellbook
//i also have cout statments which are basic code which i could not modularize just for one or two
//i also neeeded to error handle mannualy to make sure the user could not enter a random letter or number


void search_by_effect_nonstudent(Spellbook *spellbook_arr, int numbook,ofstream & outputfile) {
  int choice = printofile();
  string search_effects,name;
  cout << "Decide which effect you would like to search by: fire , bubble , memory_loss , death , or poison : " << endl;
  cin >> search_effects; 
  if (choice == 1)
  {  
  bool found = false;
  for (int i = 0; i < numbook; i++) {
   for (int j = 0; j < spellbook_arr[i].num_spells; j++)
   {
    if (spellbook_arr[i].s[j].effect == search_effects) {
      cout << "Spell Name :  " << spellbook_arr[i].s[j].name << endl;
      cout << "spell effect : " << spellbook_arr[i].s[j].effect << endl;
      found = true;
    }
   } 
  }
  if (!found) {
    cout << "No spells found with the specified effect." << endl;
  }
  }
  if (choice == 2)
  {
    bool found_2 = false;
    cout << "which file would you like to store the effects to ?" << endl;
    cin >> name;
    outputfile.open(name.c_str(), ios::app);
   for (int i = 0; i < numbook; i++) {
   for (int j = 0; j < spellbook_arr[i].num_spells; j++)
   {
    if (spellbook_arr[i].s[j].effect == search_effects) {
      outputfile << "Spell Name: " << spellbook_arr[i].s[j].name << endl;
      outputfile << "spell effect: " << spellbook_arr[i].s[j].effect << endl;
      found_2 = true;
    }
   } 
  }
  if (!found_2) {
    cout << "No spells found with the specified effect." << endl;
  }
  outputfile.close(); 
  }
}

/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:deleting info so i dont have mem leaks
 * ** Input:wizard array and spellbook array
 * ** Output:deleting memeory
 * ******************************************************/

void delete_info(Wizard** wizard_arr, Spellbook** spellbook_arr, int size_2) {

for(int i = 0; i < size_2; i++ ){
    delete [] (*spellbook_arr)[i].s;
    (*spellbook_arr)[i].s = NULL;
}

delete [] *spellbook_arr;
*spellbook_arr = NULL;

delete [] *wizard_arr;
*wizard_arr = NULL;
}





/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:doing what the user decides wheter its a 1-4
 * ** Input:spellbook array the size of the books and ofstrema
 * ** Output:displaying it to the user
 * ******************************************************/


void using_options_nonstudents(Spellbook * spellbook_arr,int size_2,ofstream & outputfile){
int optionz;
while (true)
{
    optionz = options();
    if (optionz == 1)
    {
        searching_name(spellbook_arr,size_2,outputfile);
    }
    if (optionz == 2)
    {
        searching_num_pages(spellbook_arr,size_2,outputfile);
    }    
    if (optionz == 3)
    {
      
    search_by_effect_nonstudent(spellbook_arr,size_2,outputfile);
      
    }
    if (optionz == 4) {
        break;
    }
}
}

/******************************************************
 * ** Program: wizard_catalog.cpp
 * ** Author: Your Name
 * ** Date: 01/30/2023
 * ** Description:displaying the user options wheter its a 1-4
 * ** Input:spellbook array the size of the books and the ofstream file
 * ** Output:displaying the results
 * ******************************************************/
void using_options_students(Spellbook * spellbook_arr,int size_2,ofstream & outputfile){
int optionz;
while (true)
{
    optionz = options();
    if (optionz == 1)
    {
        searching_name_students(spellbook_arr,size_2,outputfile);
    }
    if (optionz == 2)
    {
        searching_num_pages_students(spellbook_arr,size_2,outputfile);
    }    
    if (optionz == 3)
    {
          search_by_effect_student(spellbook_arr,size_2,outputfile);
    }
    if (optionz == 4) {
        break;
    }
} 
}





