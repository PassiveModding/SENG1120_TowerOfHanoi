#include <iostream>
#include <cstdlib>

#include "LinkedList.h"
#include "Node.h"
#include "LStack.h"

using namespace std;

template<class value_type>
LStack<value_type>::LStack()
{
    //ll_stack is automatically created
    //ll_stack = LinkedList<value_type>();
}

template<class value_type>
LStack<value_type>::~LStack()
{
    //Nothing deleted here as ll_stack is local to the class
}


template<class value_type>
void LStack<value_type>::push(const value_type& data)
{
    ll_stack.addToHead(data);
    ll_stack.moveToHead();
}

template<class value_type>
const value_type LStack<value_type>::pop()
{
    //gets the data at the head node
    value_type data = ll_stack.getData();
    //remove the head
    ll_stack.removeHead();

    //move to head not necessary as the removehead function already does this
    //ll_stack.moveToHead();

    return data;
}

template <class value_type>
const bool LStack<value_type>::isEmpty() const
{
    //compare whether the size of the underlying list is 0
    return ll_stack.getSize() == 0;
}

template<class value_type>
const int LStack<value_type>::size() const
{
    return ll_stack.getSize();
}

template<class value_type>
const value_type LStack<value_type>::peek() const
{
    return ll_stack.getData();
}

template <class value_type>
ostream& operator<< (ostream& out, LStack<value_type>& stack)
{
    //Create a temp storage for all values as they must be removed from the stack to be read.
    LStack<value_type> tempStack;
    while (!stack.isEmpty())
    {
        out << stack.peek() << " ";
        tempStack.push(stack.pop());
    }

    //add all values back to stack
    while (!tempStack.isEmpty())
    {
        stack.push(tempStack.pop());
    }

    return out;
}