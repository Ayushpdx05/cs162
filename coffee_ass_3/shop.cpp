#include "shop.h"
#include <iostream>
#include <string>
#include <sstream>

/*********************************************************************
** Program Filename:shop.cpp
** Author: Ayush singh
** Date: 03/03/23
** Description: member functions for shop class
*********************************************************************/




/*********************************************************************
** Function: shop deafult constructor
** Description: creating deafult shop object
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/

Shop::Shop(){
    this->phone = "phone";
    this->address = "adress";
    this->revenue = 1.2;
    this->order_arr = NULL;
    this->num_orders = 0;
}


/*********************************************************************
** Function:destructor
** Description:freeing allocated memeory 
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/

Shop::~Shop(){
     if (this->order_arr != NULL)
    {
        delete [] this->order_arr;
        this->order_arr = NULL;
    }
}


/*********************************************************************
** Function:get_coffee_deatils
** Description: if the name and the size is the same as the parameters returning 
the coffee array at that index.
** Parameters:entering the name and size of the coffee
** Pre-Conditions:coffee must exist
** Post-Conditions:
*********************************************************************/


Coffee Shop::get_coffee_details(string name, char size) {
    for (int i = 0; i < this->m.get_num_coffee(); i++) {
        if (this->m.get_coffee_arr()[i].get_name() == name && this->m.get_coffee_arr()[i].get_size() == size) {
            return this->m.get_coffee_arr()[i];
        }
    }
    // Return a default Coffee object if the coffee with the given name and size is not found
    return Coffee();
}


/*********************************************************************
** Function: getrevenue
** Description: calcualting the revenue of the items in the order file which the
user can order
** Parameters:none
** Pre-Conditions:ifstream works file opens correctely
** Post-Conditions: returning the revuenue and throwing and showing 0 if no orders exist
*********************************************************************/
//reason for more than 15 lines is creating alot of caraibles and opening the menu file.
//I was reciving alot more memory leaks if I was using ifstream as a parameter
float Shop::getRevenue() {
    // Load the menu
    ifstream menufile("menu.txt");
    Menu m;
    m.load_menu();
    menufile.close();

    // Read the orders file and calculate the revenue
    ifstream ordersfile("orders.txt");
    int num_orders;
    ordersfile >> num_orders;
    Order* order_arr = new Order[num_orders];
    for (int i = 0; i < num_orders; i++) {
        int amount;
        string name;
        char size;
        int quantity;
        ordersfile >> amount >> name >> size >> quantity;
        order_arr[i] = Order(amount, name, size, quantity);
    }
    ordersfile.close();

    // Calculate the revenue
    float revenue = 0.0;
    for (int i = 0; i < num_orders; i++) {
        for (int j = 0; j < m.get_num_coffee(); j++) {
            if (m.get_coffee_arr()[j].get_name() == order_arr[i].get_coffee_name()) {
                float price;
                if (order_arr[i].get_coffee_size() == 'S') {
                    price = m.get_coffee_arr()[j].get_small_cost();
                } else if (order_arr[i].get_coffee_size() == 'M') {
                    price = m.get_coffee_arr()[j].get_medium_cost();
                } else {
                    price = m.get_coffee_arr()[j].get_large_cost();
                }
                revenue += order_arr[i].get_quantity() * price;
                break;
            }
        }
    }
    cout << "the total shop revuenue is : " << revenue << " $ "<< endl;
}

/*********************************************************************
** Function:order_coffee
** Description:allowing th euser to enter a cofffe they woudl like to order
truncating that information into a file and replacing that file with the menu file. 
then renaming the file to menu.txt
** Parameters:none
** Pre-Conditions:menu must be loaded
** Post-Conditions:appending information
*********************************************************************/
//reason for more than 15 lines for function is because creating varaibles
//and white space. also error handling which is taking up alot of space
void Shop::order_coffee() {
    m.load_menu();

    // Get input from user
    string name;
    char size;
    int quantity;
    bool coffee_found = false;
    Coffee* coffee_arr = m.get_coffee_arr();
    Coffee* coffee_ptr = nullptr;
    cout << "Enter coffee name: ";
    cin >> name;
    for (int i = 0; i < m.get_num_coffee(); i++) {
        if (coffee_arr[i].get_name() == name) {
            cout << "Enter coffee size (S/M/L): ";
            cin >> size;
            if (coffee_arr[i].get_size() == size) {
                coffee_ptr = &coffee_arr[i];
                coffee_found = true;
                break;
            }
        }
    }
    if (!coffee_found) {
        cout << "Coffee not found!" << endl;
        return;
    }
    cout << "Enter quantity: ";
    cin >> quantity;

    // Create a new order
    Order new_order(this->num_orders + 1, name, size, quantity);

    // Add the order to the orders array
    Order* new_arr = new Order[this->num_orders + 1];
    for (int i = 0; i < this->num_orders; i++) {
        new_arr[i] = this->order_arr[i];
    }
    new_arr[this->num_orders] = new_order;
    if (this->order_arr != nullptr) {
        delete[] this->order_arr;
    }
    this->order_arr = new_arr;
    this->num_orders++;

    // Update the orders.txt file
    ofstream outfile("orders.txt", ios::trunc);
    if (outfile.is_open()) {
        outfile << this->num_orders << endl;
        for (int i = 0; i < this->num_orders; i++) {
            Order& order = this->order_arr[i];
            outfile << order.get_id() << " " << order.get_coffee_name() << " " << order.get_coffee_size() << " " << order.get_quantity() << endl;
        }
        cout << "Order added successfully and written to orders.txt file!" << endl;
    } else {
        cout << "Failed to open orders.txt file!" << endl;
    }
}

/*********************************************************************
** Function: removing coffee from menu
** Description: allowing the user to remove coffee from menu
** Parameters:none
** Pre-Conditions:menu loads
** Post-Conditions:none
*********************************************************************/
//reason for more than 15 lines is because creating varaibles and error handlign which takes alot of
//lines
void Shop::remove_coffee_from_menu() {
    m.load_menu();
    int index_to_remove;
    cout << "Enter the index of the coffee to remove: ";
    cin >> index_to_remove;
    index_to_remove--; // subtract 1 to adjust for 0-based indexing

    cout << "Index to remove: " << index_to_remove << endl;

    // create a temporary file
    ofstream temp_file("temp.txt");

    // open the original file in input mode
    ifstream menu_file("menu.txt");
    int num_coffees;
    if (menu_file.is_open() && temp_file.is_open()) {
        string line;
        int line_number = 1;

        // read the first line which contains the total number of coffees
        getline(menu_file, line);
        std::istringstream iss(line);
        iss >> num_coffees;

        // write the modified value of num_coffees to the temp file
        temp_file << num_coffees - 1 << endl;

        // read the rest of the file line by line
        while (getline(menu_file, line)) {
            // skip the line to be removed
            if (line_number == index_to_remove) {
                line_number++;
                continue;
            }
            temp_file << line << endl;
            line_number++;
        }

        // close the files
        menu_file.close();
        temp_file.close();

        // delete the original file
        remove("menu.txt");

        // rename the temporary file to the original filename
        rename("temp.txt", "menu.txt");

        cout << "Coffee successfully removed from the menu!" << endl;

    } else {
        cout << "Unable to open file" << endl;
    }

    // update the menu size
    m.set_num_coffees(num_coffees - 1);

}







/*********************************************************************
** Function:add coffee to menu
** Description:adding coffee to menu that the user requests. appending that information into the
menu.txt file
** Parameters: none
** Pre-Conditions:coffee array
** Post-Conditions:returning the coffee to the menu.txt
*********************************************************************/
//reason for more than 15 lines is because 
//of creating variables and statements which take up space.
void Shop::add_coffee_to_menu(){
    std::string name;
    double s_price,m_price,l_price;

    // Prompt the user to enter the coffee details
    cout << "Enter the name of the coffee: ";
    cin >> name;
    cout << "Enter the small of the coffee: ";
    cin >> s_price;
    cout << "Enter the medium of the coffee: ";
    cin >> m_price;
    cout << "enter the large price";
    cin >> l_price;

    // Create a new coffee object with the user's input
    Coffee new_coffee(name,s_price,m_price,l_price);

    // Add the new coffee object to the menu
    this->m.add_to_menu(new_coffee);

    // Append the new coffee details to the menu.txt file
    ofstream menu_file("menu.txt", ios::app);
    if(menu_file.is_open()){
        menu_file << new_coffee.get_name() << " " << new_coffee.get_small_cost() << " " 
                  << new_coffee.get_medium_cost() << " " << new_coffee.get_large_cost() << endl;
        menu_file.close();
    }
    else{
        cout << "Unable to open file" << endl;
    }   
    m.update_menu_size();
}


/*********************************************************************
** Function:displayorders 
** Description: displaying orders from the text file
** Parameters:none
** Pre-Conditions:text file must load
** Post-Conditions:displaying array of orders clearly
*********************************************************************/

void Shop::display_orders() {
    ifstream infile("orders.txt");
    if (!infile) {
        cout << "Failed to open orders.txt file!" << endl;
        return;
    }

    int num_orders;
    infile >> num_orders;
    cout << "Number of orders: " << num_orders << endl;

    for (int i = 0; i < num_orders; i++) {
        int order_num;
        string coffee_name;
        char coffee_size;
        int quantity;
        infile >> order_num >> coffee_name >> coffee_size >> quantity;

        // Create a new Order object with the read-in information
        Order order(order_num);
        order.add_to_order(coffee_name, coffee_size, quantity);

        // Display the order details using the getters
        cout << "Order " << order.get_id() << ": " << order.get_coffee_name() << " "
             << order.get_coffee_size() << " " << order.get_quantity() << " "
             << endl;
    }

    infile.close();
}



/*********************************************************************
** Function: loading address and shop number
** Description:taking in information from the file and then displaying it
** Parameters:ifstream for shop information
** Pre-Conditions: file loads
** Post-Conditions: 
*********************************************************************/


void Shop::load_data_shop_addy(ifstream &shopinfo){
    shopinfo >> this->phone;
    shopinfo.ignore(); // ignore the newline character left by >> 
    getline(shopinfo, this->address);
    shopinfo.close();
}


void Shop::display_shop_addy(){
    ifstream shopinfo("shop_info.txt");
    load_data_shop_addy(shopinfo);
    cout << "shop Adress : " << this->address << endl;
    shopinfo.close();
}

void Shop::display_shop_number(){
    ifstream shopinfo("shop_info.txt");
    load_data_shop_addy(shopinfo);
    cout << "shop number :" << this->phone << endl;
    shopinfo.close();
}
