#ifndef COFFEE_H
#define COFFEE_H

#include <string>
#include <fstream>

using namespace std;

#include <string>


/*********************************************************************
** Program Filename:coffee.h
** Author:Ayush SIngh
** Date:03/02/23
** Description:coffee class
*********************************************************************/



class Coffee {
  private:
    std::string name;
    float small_cost;
    float medium_cost;
    float large_cost;
    
  public:
    Coffee();
    Coffee(string name,double small_price, double medium_price, double large_price);
    Coffee(std::string name, float small_cost, float medium_cost, float large_cost);
    void set_name(const std::string name);
    void set_small_cost(const float small_cost);
    void set_medium_cost(const float medium_cost);
    void set_large_cost(const float large_cost);
    std::string get_name() const;
    float get_small_cost () const;
    float get_medium_cost () const;
    float get_large_cost () const;
    void load_a_single_coffee(ifstream&menufile);
    void display_a_single_coffee();
    char get_size();
    double get_price(char size) const;

};


#endif