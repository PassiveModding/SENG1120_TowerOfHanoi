#ifndef LJ_NODE
#define LJ_NODE
template <class value_type>
class Node
{
    public:
        //constructor
        Node(const value_type& initData = value_type());
        //destructor
        ~Node();

        /*
         * Member Function: sets the pointer to the next node
         * Precondition: a valid pointer to a node or NULL is provided
         * Postcondition: the 'next' pointer is set to the provided pointer
         */
        void setNext(Node<value_type>* nextNode);

        /*
         * Member Function: sets the pointer to the previous node
         * Precondition: a valid pointer to a node or NULL is provided
         * Postcondition: the 'prev' pointer is set to the provided pointer
         */
        void setPrev(Node<value_type>* prevNode);

        /*
         * Member Function: sets the data
         * Precondition: valid data is provided
         * Postcondition: previous data is overwritten with new data
         */
        void setData(const value_type& newData);
        
        /*
         * Member Function: returns the data
         */
        const value_type getData() const;
        
        /*
         * Member Function: returns a pointer to the next node or NULL
         */
        Node<value_type>* getNext() const;
        
        /*
         * Member Function: returns a pointer to the previous node or NULL
         */
        Node<value_type>* getPrev() const;        
    private:
        Node<value_type>* next;
        Node<value_type>* prev;
        value_type data;
};

#include "Node.hpp"
#endif