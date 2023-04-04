#ifndef MENU_H
#define MENU_H 

#include <string>
#include <fstream>
#include "coffee.h"

using namespace std;



/*********************************************************************
** Program Filename: menu.h
** Author: Ayush Singh
** Date:03/03/23
** Description:menu class
** Input:
** Output:
*********************************************************************/


class Menu {
  private:
    int num_coffee;
    Coffee* coffee_arr;
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    //need to use 'const' when appropriate

    // Suggested functions:
    Menu();
    ~Menu(); //destructor
    //aoo
    Menu & operator=(const Menu&);
    //copy constructor
    Menu(const Menu& other);
    void load_menu();
    void add_coffee(Coffee coffee);
    int get_num_coffee() const ;
    Coffee* get_coffee_arr();
    int set_num_coffee(int num_coffee);
    void load_coffee(string filename);
    void display_every_coffee();
    void display_single_coffee(Coffee& coffee);
    Coffee& search_coffee_by_name(string name); 
    Menu& search_coffee_by_price(float upper_bound); 
    void add_to_menu(Coffee& coffee_to_add); //add a coffee object into the Menu
    void remove_from_menu(int index_of_coffee_on_menu); //remove a coffee object from the Menu 
    Coffee search_coffee_by_name_forfile(const std::string& name);
    void update_menu_size();
    void display_menu();
    int get_menu_size() const;
    Coffee get_coffee_at_index(int index) const;
    void set_num_coffees(int n);
    // feel free to add more member functions

};

#endif