#ifndef LJ_LL
#define LJ_LL
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;
template <class value_type>
class LinkedList
{
    public:
        //Constructor
        LinkedList();
        //Destructor
        ~LinkedList();

        /*
         * Member Function: adds a new node to the head of the list
         * Postcondition: stack size is increased and head pointer is updated to new head
         */
        void addToHead(const value_type& value);

        /*
         * Member Function: adds a new node to the tail of the list
         * Postcondition: stack size is increased and tail pointer is updated to new tail
         */
        void addToTail(const value_type& value);

        /*
         * Member Function: removes the head node
         * Precondition: there is at least one node in the list
         * Postcondition: head node is removed. current and tail are updated accordingly
         */
        void removeHead();

        /*
         * Member Function: removes the tail node
         * Precondition: there is at least one node in the list
         * Postcondition: tail node is removed. current and head are updated accordingly
         */
        void removeTail();

        /*
         * Member Function: updates current to point to the head node
         * Postcondition: current is the same as the head pointer
         */
        void moveToHead();

        /*
         * Member Function: current points to the node at current->getNext()
         * Precondition: current is not NULL
         * Postcondition: current points to the node after it
         */
        void moveNext();

        
        /*
         * Member Function: current points to the node at current->getPrev()
         * Precondition: current is not NULL
         * Postcondition: current points to the node before it
         */
        void movePrev();
        
        /*
         * Member Function: returns the data contained in the current node
         * Precondition: current is not NULL
         */
        const value_type getData() const;

        /*
         * Member Function: returns a string representation of the list
         */
        const string print();

        /*
         * Member Function: exposes the size variable
         */
		const int getSize() const;
    private:
        Node<value_type>* current;
        Node<value_type>* head;
        Node<value_type>* tail;
        int size;
};

template <class value_type>
std::ostream& operator<< (std::ostream& stream, LinkedList<value_type>& list);

#include "LinkedList.hpp"
#endif