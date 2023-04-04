#ifndef ORDER_H
#define ORDER_H 

#include <string>

using namespace std;



/*********************************************************************
** Program Filename:order.h
** Author:Ayush Singh
** Date:03/03/2023
** Description: order class
** Input: none
** Output: member functions
*********************************************************************/

class Order
{
private:
	int id;
	string coffee_name;
	char coffee_size;
	int quantity;

public:
	//need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate
	Order();
	Order(int order_num, std::string& coffee_name, char size, int& quantity);
	void set_id(const int id);
	void set_coffee_name(const std::string coffee_name);
	void set_coffee_size(const char coffee_size);
	void set_quantity(const int quantity);
	int get_id()const;
	 Order(int order_id) : id(order_id) {}
	std::string get_coffee_name()const;
	char get_coffee_size()const;
	int get_quantity()const;
	void add_to_order(string coffee, char num_coffees, int quantity);
	double calculate_cost() const;
};
#endif