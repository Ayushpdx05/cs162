#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Wizard {
 string name;
 int id;
 string password;
 string position_title;
 float beard_length;
};

struct Spellbook {
 string title;
 string author;
 int num_pages;
 int edition;
 int num_spells;
 float avg_success_rate;
 struct Spell *s;
};

struct Spell {
 string name;
 float success_rate;
 string effect;
};

Spellbook * create_spellbooks(int);

Spell * create_spells(int);

Wizard * create_wizards(int size);

void populate_wizard(Wizard* , int size, ifstream &);

void populate_spellbook_data(Spellbook *, int, ifstream &);

void populate_spell_data(Spellbook *, int, ifstream &);

void delete_info(Wizard ** , Spellbook ** , int );

void test_function();

int user_entered_id(Wizard* wizard_arr, int size);

void using_options_nonstudents(Spellbook * spellbook_arr,int size_2,ofstream & outputfile);

void using_options_students(Spellbook * spellbook_arr,int size_2,ofstream & outputfile);


#endif
