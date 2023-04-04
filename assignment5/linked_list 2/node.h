#ifndef NODE_H
#define NODE_H


/******************************************************
** Program: node.h
** Author: Ayush Singh
** Date: 3/10/2023
** Description: node class with a constructor and a destructor
** Input: none
** Output: none
******************************************************/

class Node{
public:
	int val; // the value that this node stores
	Node *next; // a pointer to the next node in the list
	// you can add constructors or other functionality if you find it useful or necessary
	Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
	~Node(){};	
};

#endif