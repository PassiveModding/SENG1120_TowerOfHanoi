#include "LinkedList.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <class value_type>
LinkedList<value_type>::LinkedList()
{
    //Initialize all pointers to null and size to 0
    head = NULL;
    tail = NULL;
    current = NULL;
    size = 0;
}

template <class value_type>
LinkedList<value_type>::~LinkedList()
{
    //iterate through all nodes and delete them
    moveToHead();
    while (current != NULL)
    {
        Node<value_type>* tempNext = current->getNext();
        delete current;
        current = tempNext;
    }

    //Set head and tail to NULL, current is already NULL
    head = NULL;
    tail = NULL;
}

template <class value_type>
void LinkedList<value_type>::addToHead(const value_type &value)
{
    //if size is 0 set everything to point to the new node
    if (size == 0)
    {
        head = new Node<value_type>(value);
        tail = head;
        current = head;
        size = 1;
    }
    else
    {
        //create the new node
        Node<value_type>* newNode = new Node<value_type>(value);
        //set a new head and link the current head to be after the new one
        head->setPrev(newNode);
        newNode->setNext(head);
        head = newNode;

        //increase size
        size++;
        //Avoid memory leak
        newNode = NULL;
    }    
}

template <class value_type>
void LinkedList<value_type>::addToTail(const value_type &value)
{
    //if size is 0 set everything to point to the new node
    if (size == 0)
    {
        tail = new Node<value_type>(value);
        head = tail;
        current = tail;
        size = 1;
    }
    else
    {
        //create the new node
        Node<value_type>* newNode = new Node<value_type>(value);
        //set a new tail and link the current tail to be before the new one
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;

        //increase size
        size++;
        //Avoid memory leak
        newNode = NULL;
    }  
}

template <class value_type>
void LinkedList<value_type>::removeHead()
{
    Node<value_type>* tempNode;
    tempNode = head; 
    //update head to be the second node
    head = head->getNext();

    //There is only a single node so remove both head and tail
    if (head == NULL)
    {
        tail = NULL;
    }
    else
    {
        //remove reference to old head.
        head->setPrev(NULL);
    }
    
    delete tempNode;
    //decrease size
    size--;
    current = head;
}

template <class value_type>
void LinkedList<value_type>::removeTail()
{
    Node<value_type>* tempNode;
    tempNode = tail; 
    //update head to be the second node
    tail = tail->getPrev();

    //There is only a single node so remove both head and tail
    if (tail == NULL)
    {
        head = NULL;
    }
    else
    {
        //remove reference to old tail.
        tail->setNext(NULL);
    }
    
    delete tempNode;
    //decrease size
    size--;
    current = tail;
}

template <class value_type>
void LinkedList<value_type>::moveToHead()
{
    current = head;
}

template <class value_type>
void LinkedList<value_type>::moveNext()
{
    current = current->getNext();
}

template <class value_type>
void LinkedList<value_type>::movePrev()
{
    current = current->getPrev();
}

template <class value_type>
const value_type LinkedList<value_type>::getData() const
{
    return current->getData();
}

template<class value_type>
const int LinkedList<value_type>::getSize() const
{
	return size;
}


template<class value_type>
const string LinkedList<value_type>::print()
{
    string output = string();
    //iterate through all nodes and append them to the string
    //work with a temp node so it doesn't affect 'current' 'head' or 'tail'
    const Node<value_type>* temp = head;
    while (temp != NULL)
    {
        output.append(temp->getData());
        output.append(" ");
        temp = temp->getNext();
    }
    
    temp = NULL;
    return output;
}



template <class value_type>
std::ostream& operator<< (std::ostream& out, LinkedList<value_type>& list)
{
    out << list.print();
    return out;
}