    #include "order.h"
    #include <string>



    /*********************************************************************
    ** Program Filename:order.cpp
    ** Author:Ayush Singh
    ** Date: 03/03/2023
    ** Description: creating the member functions for order class
    ** Input: member variables
    ** Output: retrieving the variables
    *********************************************************************/  




    /*********************************************************************
    ** Function: Constructors for order class to create order objects to put
    inside of an array of objects to use in the order file 
    ** Description: initalizing the variables for the order private variables
    ** Parameters: for non deafault constructor taking in order number, the coffee name ,char size 
    and quantity to use to create a order object
    ** Pre-Conditions:variables must exist
    ** Post-Conditions:none
    *********************************************************************/

    Order::Order(){
    this->id = 0;
    this->coffee_name = "";
    this->coffee_size = 0;
    this->quantity= 0;
    }

    //non deafult constructor takes user input for there coffee
    Order::Order(int order_num, std::string& coffee_name, char  size, int& quantity) {
        this->id = order_num;
        this->coffee_name = coffee_name;
        this->coffee_size = size;
        this->quantity = quantity;
    }

    
    void Order::add_to_order(string coffee, char num_coffees, int quantity) {
    this->coffee_name = coffee;
    this->coffee_size = num_coffees;
    this->quantity = quantity;
    }





    /*********************************************************************
    ** Function:setters for object variables
    ** Description: allow the variables to be set so a getter can be used to retreive the 
    information from these setter functions.
    ** Parameters: variables of the order function
    ** Pre-Conditions: none
    ** Post-Conditions: none
    *********************************************************************/
	void Order::set_id(const int id){
    this->id = id;
    }

    //using const for string name and all the other variables because the
    //variables should not be changed
    //even accidentally

	void Order::set_coffee_name(const std::string coffee_name){
    this->coffee_name = coffee_name;
    }
	void Order::set_coffee_size(const char coffee_size){
    this->coffee_size = coffee_size;
    }
	void Order::set_quantity(const int quantity){
    this->quantity = quantity;
    }


    //using const for the getters because i dont want the object to be allowed to be modified
    //if they are not being changed

	int Order::get_id()const{
    return id;
    }
	std::string Order::get_coffee_name()const{
    return coffee_name;
    }
	char Order::get_coffee_size()const{
    return coffee_size;
    }
	int Order::get_quantity()const{
    return quantity;
    }


