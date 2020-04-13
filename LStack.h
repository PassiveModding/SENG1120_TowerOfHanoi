#ifndef LJ_STACK
#define LJ_STACK
#include "LinkedList.h"
#include <iostream>

using namespace std;

template <class value_type>
class LStack 
{
    public:
        //Constructor
        LStack();
        //Destructor
        ~LStack();
        
        /*
         * Member Function: adds a new node to the head of the stack
         * Precondition: valid data is provided
         * Postcondition: a new node is added to the head of the stack, the previous head is now the second item in the stack
         */
        void push(const value_type& data);
        
        /*
         * Member Function: removes the head node and returns it's value
         * Precondition: stack size is at least 1
         * Postcondition: stack size is decreased and head node is removed. value of head node is returned
         */
        const value_type pop();

        /*
         * Member Function: exposes the size of the underlying linked list
         * Precondition: linked list exists
         * Postcondition: stack size is decreased and head node is removed. value of head node is returned
         */
        const int size() const;

        /*
         * Member Function: returns true if stack size is 0
         */
        const bool isEmpty() const;
        
        /*
         * Member Function: returns the value at the head of the stack
         * Precondition: stack size is at least 1 and current node is at the head
         */
        const value_type peek() const;
    private:
       LinkedList<value_type> ll_stack;
};

template <class value_type>
ostream& operator<< (ostream& stream, LStack<value_type>& list);

#include "LStack.hpp"
#endif
