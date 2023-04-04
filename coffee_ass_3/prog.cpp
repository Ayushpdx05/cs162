#include <iostream>
#include "shop.h"
#include <string>
#include <fstream>
#include <limits>
#include "stdlib.h"



/******************************************************
** Program: prog.cpp
** Author: Ayush Singh
** Date: 03/01/2023
** Description: simulating a coffee shop giving the user
a option to either interact with this shop as a employee or a customer
each having there own functionalities.
** Input: options they choose as either a customer or employee
** Output: proper output of information or adding or removing of items based 
on request.
******************************************************/








/*********************************************************************
** Function: customer options 
** Description: displaying the options the customer has 
** Parameters: option which is the option that is returned to the program
as the request of the user
** Pre-Conditions: none
** Post-Conditions: return option
*********************************************************************/

int customer_options(int option) {
do {
cout << "Welcome customer how can I help you?" << endl;
cout << "1. View coffee menu " << endl;
cout << "2. Search by price" << endl;
cout << "3. Search by coffee name" << endl;
cout << "4. Place an order" << endl;
cout << "5. View address" << endl;
cout << "6. View phone" << endl;
cout << "7. Log out" << endl;
cin >> option;
if (cin.fail() || option < 1 || option > 7) {
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Invalid input. Please enter a number between 1-7." << endl;
continue;
}
break;
} while (true);
return option;
}

/*********************************************************************
** Function: employee options
** Description: displaying the options the employee has
** Parameters: option which will be returned to the program
** Pre-Conditions: none
** Post-Conditions: return the option
*********************************************************************/

int employee_options(int option) {
do {
cout << "Welcome employee how can I help you?" << endl;
cout << " 1. View shop revenue :" << endl;
cout << "2. View orders :" << endl;
cout << " 3. Add an item to coffee menu :" << endl;
cout << "4. Remove an item from coffee menu :" << endl;
cout << " 5. View coffee menu :" << endl;
cout << " 6. View address :" << endl;
cout << "7. view phone number :" << endl;
cout << " 8. log out :" << endl;
cin >> option;
if (cin.fail() || option < 1 || option > 8) {
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Invalid input. Please enter a number between 1-7." << endl;
continue;
}
break;
} while (true);
return option;
}





/*********************************************************************
** Function: main function
** Description: used in the program to actually interact with the shop
** Parameters: none
** Pre-Conditions: opening of the files
** Post-Conditions: files must exist
*********************************************************************/
//reason for more than 15 lines is creating variables and making sure
//that the program can run properly
//also switch statements
int main()
{
    ifstream menufile, shopinfo, ordersfile;
    ofstream order_out;
    Menu menu;
    Coffee c;
    Shop s;
    float cost, cost_2, budget;
    char input;
    int optionz, option, quantity, order_2,option_2;
    string coffee_name, name, order, size;
    //your main function lives here	  
    menu.load_coffee("menu.txt");   
    while (true) {  
    ordersfile.close(); 
    menufile.close();
    cout << "Are you a Customer (c) or a Employee (e) or would you like to quit the program (Q)" << endl;
    cin >> input; 
    if (input == 'c')
    {             
        do {
            optionz = customer_options(option);
            if (optionz == 1)
            {
                menu.display_every_coffee();
            }
            else if (optionz == 2)
            {
                cout << "Please enter your budget and I will display every coffee available " << endl;
                cin >> budget;
                menu.search_coffee_by_price(budget);

            }
            else if (optionz == 3)
            {
                string coffee_name;
                cout << "Please enter the name of the coffee you would like to search for:" << endl;
                cin >> coffee_name;
                menu.search_coffee_by_name(coffee_name);

            }
            else if (optionz == 4)
            {
            s.order_coffee(); //placing an order
            }
            else if (optionz == 5)
            {
                s.display_shop_addy();
            }
            else if (optionz == 6)
            {
                s.display_shop_number();
            }
            if (optionz == 7)
            {
                break;
            }
        } while (true);
    }
    else if (input == 'e')
    {
      while (true) {
        int optionz_2 = employee_options(option_2); 
        if (optionz_2 == 1) {
            // view shop revenue
            s.getRevenue();
        } else if (optionz_2 == 2) {
            // view orders
            s.display_orders();
        } else if (optionz_2 == 3) {
            s.add_coffee_to_menu();
            //add to coffee menu
        } else if (optionz_2 == 4) {
            //  Remove an item from coffee menu
            s.remove_coffee_from_menu();
        } else if (optionz_2 == 5) {
            menu.display_every_coffee();
            //view every coffee
        } else if (optionz_2 == 6) {
            //view adress
            s.display_shop_addy();
        } else if (optionz_2 == 7) {
            //view phone number
            s.display_shop_number();
        } else if (optionz_2 == 8) {
            break;  // exit loop
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }  
      } 
    }
else if (input == 'Q')
{
    exit(-1); 
} 
}  
    return 0;
}

