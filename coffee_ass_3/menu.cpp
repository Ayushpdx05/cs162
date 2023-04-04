#include "menu.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;







/*********************************************************************
** Program Filename: menu.cpp
** Author: Ayush Singh
** Date: 03/03/23
** Description: member functions for menu class
*********************************************************************/



/*********************************************************************
** Function: menu construtor
** Description: creating deafult menu constructor
** Parameters:none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/

Menu::Menu(){
    this->num_coffee = 0;
    this->coffee_arr = NULL;
}


/*********************************************************************
** Function: menu destructor
** Description:freeing memory allocated
** Parameters:none
** Pre-Conditions:memoery is allocated
** Post-Conditions: freeing memory allocated
*********************************************************************/

Menu::~Menu(){
    if (this->coffee_arr != NULL)
    {
        delete [] this->coffee_arr;
        this->coffee_arr = NULL;
    }
}


//Aoo
Menu& Menu::operator=(const Menu& other) {
        if (this != &other) {
            if (coffee_arr != NULL) {
                delete[] coffee_arr;
                coffee_arr = NULL;
            }
            num_coffee = other.num_coffee;
            if (num_coffee > 0) {
                coffee_arr = new Coffee[num_coffee];
                for (int i = 0; i < num_coffee; i++) {
                    coffee_arr[i] = other.coffee_arr[i];
                }
            } else {
                coffee_arr = nullptr;
            }
        }
        return *this;
    }



    //copy constructor
    Menu::Menu(const Menu& other) {
        this->num_coffee = other.num_coffee;
        if (num_coffee > 0) {
            coffee_arr = new Coffee[num_coffee];
            for (int i = 0; i < num_coffee; i++) {
                coffee_arr[i] = other.coffee_arr[i];
            }
        } else {
            coffee_arr = nullptr;
        }
    }


/*********************************************************************
** Function: load_coffee
** Description: loading coffeee from the menu text file
** Parameters: taking in the filename of the coffee that is being loaded
** Pre-Conditions: file must exist
** Post-Conditions: loading coffee information
*********************************************************************/
void Menu::load_coffee(string filename){
    ifstream menufile(filename);
    if (!menufile.is_open()){
        cout << "Failed to open menu file" << endl;
        return;
    }
    
    if (this->coffee_arr != NULL) {
        delete [] this->coffee_arr;
        this->coffee_arr = NULL;
    }
    
    menufile >> this->num_coffee;
    this->coffee_arr = new Coffee[num_coffee];
    for (int i = 0; i < this->num_coffee; i++)
    {
        this->coffee_arr[i].load_a_single_coffee(menufile);
    }
    menufile.close();
}
 
/*********************************************************************
** Function:displaying menu
** Description: displaying every coffee in the menu
** Parameters:none
** Pre-Conditions:coffee array
** Post-Conditions:
*********************************************************************/
void Menu::display_menu() {
   for (int i = 0; i < this->num_coffee; i++)
   {
    this->coffee_arr[i].display_a_single_coffee();
   }
}

void Menu::display_every_coffee() {
    for (int i = 0; i < this->num_coffee; i++)
    {
        this->coffee_arr[i].display_a_single_coffee();
    }
}



/*********************************************************************
** Function:add_coffee
** Description:adding coffee into the coffee array
** Parameters: the coffee object
** Pre-Conditions: obj must exist
** Post-Conditions: none
*********************************************************************/
void Menu::add_coffee(Coffee coffee) {
    Coffee* new_arr = new Coffee[this->num_coffee + 1];
    for (int i = 0; i < this->num_coffee; i++) {
        new_arr[i] = this->coffee_arr[i];
    }
    new_arr[this->num_coffee] = coffee;
    if (this->coffee_arr != NULL) {
        delete[] this->coffee_arr;
    }
    this->coffee_arr = new_arr;
    this->num_coffee++;
}

/*********************************************************************
** Function: load_menu
** Description:loading in menu so that it can be used to either remove or add coffees
** Parameters: none
** Pre-Conditions: menu file must open
** Post-Conditions:
*********************************************************************/
//not more than 15 lines not including white space and brackets
void Menu::load_menu() {
    ifstream infile("menu.txt");
    if (!infile) {
        cout << "Failed to open menu.txt file!" << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string name;
        float small_cost, medium_cost, large_cost;
        if (ss >> name >> small_cost >> medium_cost >> large_cost) {
            Coffee coffee(name, small_cost, medium_cost, large_cost);
            this->add_coffee(coffee);
        }
    } 
    cout << "Menu loaded successfully from menu.txt file!" << endl;
}

/*********************************************************************
** Function: setters and getters to retrieve the information from the private variabels
** Description: setting and getting the varaibles
** Parameters: the variable
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int Menu::set_num_coffee(int num_coffee){
    this->num_coffee = num_coffee;
}

int Menu::get_num_coffee() const {
        return num_coffee;
    }

Coffee* Menu::get_coffee_arr() {
    return this->coffee_arr;
}
/*********************************************************************
** Function:displaying single coffee
** Description: displaying a single coffee 
** Parameters:the coffee to display
** Pre-Conditions:coffee obj must exist
** Post-Conditions:
*********************************************************************/
void Menu::display_single_coffee(Coffee& coffee){
     cout << "Coffee name: " << coffee.get_name() << endl;
    cout << "small price: " << coffee.get_small_cost() << endl;
    cout << "medium price: " << coffee.get_medium_cost() << endl;
    cout << "large price: " << coffee.get_large_cost() << endl;
}


/*********************************************************************
** Function:add_to_menu
** Description:adding the coffe to the menu
** Parameters: coffee object
** Pre-Conditions: coffee obj must exist
** Post-Conditions:
*********************************************************************/
//reason for more than 15 lines it naming variables + white space
//also error handling and creating bool expressions to make sure 
//program works
void Menu::add_to_menu(Coffee& coffee_to_add){
    Coffee* new_arr = new Coffee[this->num_coffee + 1];

    for (int i = 0; i < this->num_coffee; i++){
        new_arr[i] = coffee_arr[i];
    }

    new_arr[this->num_coffee] = coffee_to_add;

    if (this->coffee_arr != NULL){
        delete [] this->coffee_arr;
    }

    this->coffee_arr = new_arr;
    this->num_coffee++;

    // Check if the coffee is added to the menu or not
    bool added = false;
    for (int i = 0; i < this->num_coffee; i++){
        if (coffee_arr[i].get_name() == coffee_to_add.get_name()){
            added = true;
            break;
        }
    }

    if (added){
        cout << "Coffee added to the menu successfully!" << endl;
    }
    else{
        cout << "Failed to add coffee to the menu!" << endl;
    }
}
/*********************************************************************
** Function:updating menu size
** Description:updating menu size
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/
void Menu::update_menu_size() {
    ifstream menufile("menu.txt");
    string file_contents((istreambuf_iterator<char>(menufile)), istreambuf_iterator<char>());
    menufile.close();

    int num_coffee = stoi(file_contents);
    num_coffee++;

    string updated_contents = to_string(num_coffee) + file_contents.substr(file_contents.find('\n'));
    ofstream outfile("menu.txt");
    outfile << updated_contents;
    outfile.close();
}

void Menu::set_num_coffees(int n){
    this->num_coffee = n;
}

Coffee& Menu::search_coffee_by_name(std::string name){
    bool found = false;
    for (int i = 0; i < this->num_coffee; i++) {
        if (name == this->coffee_arr[i].get_name()) {
           cout << this->coffee_arr[i].get_name() << " - ";
            cout << "Small: $" << this->coffee_arr[i].get_small_cost() << ", ";
            cout << "Medium: $" << this->coffee_arr[i].get_medium_cost() << ", ";
            cout << "Large: $" << this->coffee_arr[i].get_large_cost() << endl; 
            found = true;
        }
    }
    if (!found)
    {
       cout << "sorry such a coffee does not exist in this menu " << endl;
    }
}
/*********************************************************************
** Function:search_coffe_by_name_forfile
** Description:searing coffee by name for file
** Parameters:the name for the coffee
*********************************************************************/
Coffee Menu::search_coffee_by_name_forfile(const std::string& name){
    for (int i = 0; i < this->num_coffee; i++)
    {
        if (this->coffee_arr[i].get_name() == name)
        {
            return this->coffee_arr[i];
        }
    }
    return Coffee(); // Return an empty coffee object if not found
}

/*********************************************************************
** Function:search_coffee_by_pringe
** Description:searing the coffees to find the coffe which is less than the upper bound
** Parameters: upper bound 
*********************************************************************/

Menu& Menu::search_coffee_by_price(float upper_bound) {
    bool found = true;
    for (int i = 0; i < this->num_coffee; i++) {
        if (this->coffee_arr[i].get_large_cost() <= upper_bound) {
            cout << this->coffee_arr[i].get_name() << " - ";
            cout << "Small: $" << this->coffee_arr[i].get_small_cost() << ", ";
            cout << "Medium: $" << this->coffee_arr[i].get_medium_cost() << ", ";
            cout << "Large: $" << this->coffee_arr[i].get_large_cost() << endl;
        }
        else{
            found = false;
        }
    } 
    if (found == false)
    {
        cout << "sorry coffe with that budget does not exist " << endl;
    } 
}

/*********************************************************************
** Function:remove_from_menu
** Description: removing coffe from menu 
** Parameters: index of coffee on the menu
*********************************************************************/
void Menu::remove_from_menu(int index_of_coffee_on_menu) {
    if (index_of_coffee_on_menu < 0 || index_of_coffee_on_menu >= this->num_coffee) {
        // invalid index, do nothing
        return;
    }

    Coffee* new_arr = new Coffee[this->num_coffee - 1];
    int new_arr_index = 0;
    for (int i = 0; i < this->num_coffee; i++) {
        if (i != index_of_coffee_on_menu) {
            new_arr[new_arr_index] = coffee_arr[i];
            new_arr_index++;
        }
    }

    delete[] this->coffee_arr;
    this->coffee_arr = new_arr;
    this->num_coffee--;
}

// Menu class

int Menu::get_menu_size() const {
    return num_coffee;
}

Coffee Menu::get_coffee_at_index(int index) const {
    if (index >= 0 && index < num_coffee) {
        return coffee_arr[index];
    }
    // handle error - return a default coffee object or throw an exception
}

