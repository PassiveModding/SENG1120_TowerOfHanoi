#include "Node.h"
#include <cstdlib>

template <class value_type>
Node<value_type>::Node(const value_type& initData)
{
    data = initData;
    next = NULL;
    prev = NULL;
}

template <class value_type>
Node<value_type>::~Node()
{
    //sets pointers to null. 
    next = NULL;
    prev = NULL;
}

template <class value_type>
void Node<value_type>::setNext(Node* nextNode)
{
    next = nextNode;
}

template <class value_type>
void Node<value_type>::setPrev(Node* prevNode)
{
    prev = prevNode;
}

template <class value_type>
void Node<value_type>::setData(const value_type& newData)
{
    data = newData;
}

template <class value_type>
Node<value_type>* Node<value_type>::getNext() const
{
    return next;
}

template <class value_type>
Node<value_type>* Node<value_type>::getPrev() const
{
    return prev;
}

template <class value_type>
const value_type Node<value_type>::getData() const
{
    return data;
}