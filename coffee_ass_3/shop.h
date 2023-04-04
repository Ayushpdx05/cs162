#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>
#include "menu.h"
#include "order.h"

using namespace std;


/*********************************************************************
** Program Filename: shop.h
** Author: Ayush Singh
** Date: 03/03/23
** Description: shop class
** Input: none
** Output: none
*********************************************************************/

class Shop {
  private:
    Menu m;
    string phone;
    string address;
    float revenue;
    Order *order_arr;
    int num_orders;
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

    //Suggested functions
    Shop();
    ~Shop();
    float getRevenue();
    void order_coffee();
    void load_data_shop_addy(ifstream &shopinfo); //reads from files to correctly populate coffee, menu, etc.
    void load_data_orders(ifstream & ordersfile);
    void view_menu();
    void view_address();
    void view_phone();
    void search_by_price();
    void search_by_name();
    void place_order(string coffee_name, char num_coffees,int quantity);
    void add_coffee_to_menu();
    void remove_from_menu();
    void view_orders();
    float calculate_price(string nameofcoffee, string sizeofcoffee, int quantity) const;
    void display_shop_addy();
    void display_shop_number();
    Coffee get_coffee_details(string name, char size);
    void remove_coffee_from_menu();
    void display_orders();
};

#endif