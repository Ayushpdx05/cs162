#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"
#include <iostream>
#include <cmath>
using namespace std;

/******************************************************
** Program: linked_list.h
** Author: Ayush Singh
** Date: 3/10/2023
** Description: Linked List class with all the functions implemented
** Input: none
** Output: none
******************************************************/

class Linked_List {
private:
	unsigned int length; // the number of nodes contained in the list
	Node* head; // a pointer to the first node in the list
	// anything else you need...
    void split(Node* source, Node** front, Node** back);

/*********************************************************************
** Function: merge_sort
** Description: sorting by splitting linked list in 2 halfs and recurssively
sorting each half and then merging the sorted halfs back toghter
** Parameters: pointer to an node obj
** Pre-Conditions: linked list is accessible
** Post-Conditions: none
*********************************************************************/

    Node* merge_sort(Node* node) {  //merge sort 
    if (node == NULL || node->next == NULL) {
        return node;
    }

    Node* middle = get_middle_node(node);
    Node* right = middle->next;
    middle->next = NULL;

    Node* left = merge_sort(node);
    right = merge_sort(right);

    return merge(left, right);
}
public:

/*********************************************************************
** Function: Linked List constructor
** Description: creating a linked lit obj
** Parameters: none deafult constructor
** Pre-Conditions: Linked list exists
** Post-Conditions: none
*********************************************************************/

    Linked_List() {
        this->length = 0;
        this->head = NULL;
    }

/*********************************************************************
** Function: get_lenght
** Description: getting the lenght
** Parameters: none
** Pre-Conditions: lenght is a var
** Post-Conditions: lenght is retreived
*********************************************************************/
    unsigned int get_length() {
        return length;
    }
/*********************************************************************
** Function:Print
** Description: printing the elements of a linked list 
** Parameters: none
** Pre-Conditions: exists
** Post-Conditions: none
*********************************************************************/
    void print() {
        Node *curr = head;
        while (curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
/*********************************************************************
** Function: clear
** Description: clearning the linked list
** Parameters: none
** Pre-Conditions: exists
** Post-Conditions: none
*********************************************************************/
    void clear() {
        Node *curr = head;
        while (curr != NULL) {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        length = 0;
        head = NULL;
    }
/*********************************************************************
** Function:push front
** Description: inserts a new node with a value into the front of the list
** Parameters: val
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
    void push_front(int val) {
        Node *node = new Node(val);
        node->next = head;
        head = node;
        length++;
    }
/*********************************************************************
** Function: push back
** Description: inserts a new node with a value into the back of the list
** Parameters: val
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
    void push_back(int val) {
        Node *node = new Node(val);
        if (head == NULL) {
            head = node;
        } else {
            Node *curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = node;
        }
        length++;
    }
/*********************************************************************
** Function: insert
** Description: inserting a with a given value at a specific index
** Parameters: val and index
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
    void insert(int val, unsigned int index) {
        if (index > length) {
            cout << "Index out of range" << endl;
            return;
        }

        Node *node = new Node(val);

        if (index == 0) {
            node->next = head;
            head = node;
        } else {
            Node *curr = head;
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            node->next = curr->next;
            curr->next = node;
        }

        length++;
    }

    Node* get_head(){
    return head;
  }
/*********************************************************************
** Function: sort descending
** Description: sorts the list in a desending order
** Parameters: none
** Pre-Conditions: list exist
** Post-Conditions: none
*********************************************************************/
    void sort_descending() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node* dummy = new Node(-1);
    dummy->next = head;
    Node* prev = dummy;
    Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        Node* max_node = curr;
        Node* prev_max = prev;
        Node* search_node = curr->next;
        Node* prev_search = curr;

        while (search_node != NULL) {
            if (search_node->val > max_node->val) {
                max_node = search_node;
                prev_max = prev_search;
            }
            prev_search = search_node;
            search_node = search_node->next;
        }

        if (max_node != curr) {
            prev->next = max_node;
            prev_max->next = curr;
            Node* temp = max_node->next;
            max_node->next = curr->next;
            curr->next = temp;

            if (curr == head) {
                head = max_node;
            }
        }

        prev = max_node;
        curr = max_node->next;
    }

    delete dummy;
}



/*********************************************************************
** Function: merge
** Description: merging 2 sorted lists
** Parameters: 2 pointers
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

	Node* merge(Node* left, Node* right) {
    Node *result = NULL;

    if (left == NULL) {
        return right;
    }

    if (right == NULL) {
        return left;
    }

    if (left->val <= right->val) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}	
/*********************************************************************
** Function: sort assending 
** Description: sorting the list in asending order
** Parameters: none
** Pre-Conditions: exists
** Post-Conditions: none
*********************************************************************/
void sort_ascending() {
    if (head != NULL) {
        head = merge_sort(head);
    }
}
/*********************************************************************
** Function: get_midddle_node
** Description: retreiving the middle node
** Parameters: pointer to node
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Node* get_middle_node(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}


};

/*********************************************************************
** Function: is_prime
** Description: checking wheter the number is prime or not 
** Parameters: interger value
** Pre-Conditions: none
** Post-Conditions:none
*********************************************************************/
bool is_prime(int num) {
    if(num < 2) {
        return false;
    }
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}
/*********************************************************************
** Function: count prime
** Description: checks the amount of primes in a list
** Parameters: refrence to the list
** Pre-Conditions: exists
** Post-Conditions: none
*********************************************************************/
unsigned int count_prime(Linked_List& list) {
    unsigned int count = 0;
    Node* current = list.get_head();
    while(current != NULL) {
        if(is_prime(current->val)) {
            count++;
        }
        current = current->next;
    }
    return count;
}


#endif
