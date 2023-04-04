#include <string>
#include "coffee.h"
#include <iostream>


using namespace std;


/*********************************************************************
** Program Filename:coffee.cpp
** Author:Ayush SIngh
** Date:03/02/23
** Description:creating member functions for coffee class
*********************************************************************/


/*********************************************************************
** Function: coffee constructors
** Description: creating coffeee objects
** Parameters: name,price,mprice,lprince
** Pre-Conditions:  coffee must have these variables
** Post-Conditions: creating coffe obj
*********************************************************************/


Coffee::Coffee(){
  this->name = "";
  this->small_cost = 0.0;
  this->medium_cost = 0.0;
  this->large_cost = 0.0;
}

Coffee::Coffee(string name,double small_price, double medium_price, double large_price) {
    this->name = name;   
    this->small_cost = small_price;
    this->medium_cost = medium_price;
    this->large_cost = large_price;
}


Coffee::Coffee(std::string name, float small_cost, float medium_cost, float large_cost) {
    this->name = name;
    this->small_cost = small_cost;
    this->medium_cost = medium_cost;
    this->large_cost = large_cost;
}


/*********************************************************************
** Function: get size
** Description: getting the size of the coffee wheter its s/ml
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/


char Coffee::get_size() {
    char size_input;
    cout << "Enter coffee size (S/M/L): ";
    cin >> size_input;

    switch (tolower(size_input)) {
        case 's':
            return 'S';
        case 'm':
            return 'M';
        case 'l':
            return 'L';
        default:
            cout << "Invalid size input. Please enter 'S', 'M', or 'L'." << endl;
            return '\0';
    }
}

/*********************************************************************
** Function:get_price
** Description:get the price wheter its s/m/l
** Parameters:char size
*********************************************************************/
double Coffee::get_price(char size) const {
    switch(size) {
        case 'S':
            return small_cost;
        case 'M':
            return medium_cost;
        case 'L':
            return large_cost;
        default:
            return 0.0; // or throw an exception
    }
}


/*********************************************************************
** Function:setter 
** Description:setting functions for coffee obj 
** Parameters:variables in the coffee class
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/

//using const for the getters because i dont want the object to be allowed to be modified
    //if they are not being changed
void Coffee::set_name(const std::string name) {
  this->name = name;
}


void Coffee::set_small_cost(const float small_cost) {
  this->small_cost = small_cost;
}

void Coffee::set_medium_cost(const float medium_cost) {
  this->medium_cost = medium_cost;
}

void Coffee::set_large_cost(const float large_cost) {
  this->large_cost = large_cost;
}

/*********************************************************************
** Function:getter 
** Description: using const for the getters because i dont want the object to be allowed to be modified
if they are not being changed
** Parameters:the variables
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/

std::string Coffee::get_name() const {
  return name;
}

float Coffee::get_small_cost() const {
  return small_cost;
}

float Coffee::get_medium_cost() const {
  return medium_cost;
}

float Coffee::get_large_cost() const {
  return large_cost;
}

/*********************************************************************
** Function:load_a_single_coffee
** Description: loading a coffee
** Parameters:ifstream
** Pre-Conditions:file opens
** Post-Conditions:none
*********************************************************************/

void Coffee::load_a_single_coffee(ifstream & menufile) {
    menufile >> this->name >> this->small_cost >> this->medium_cost >> this->large_cost;
}

void Coffee::display_a_single_coffee() {
    cout << "-------------------" << endl;
    cout << "Name: " << this->name << endl;
    cout << "small cost: " << this->small_cost << endl;
    cout << "Medium cost: " << this->medium_cost << endl;
    cout << "Large cost: " << this->large_cost << endl;
    cout << "-------------------" << endl;
}




