// sLinkedList.h
// Singly Linked List: Definitions and Declarations

// Author: Jossie Calderon
// with references to Chris Lacher's List<T> implementation
// particularly the addition of friend classes to his Node structure
// such as his Iterator structure which helps traverse the list.
// Also the use of the push_back function.

template typename<T>
class sLinkedList
{
  node* begin;
  node* end;
  int size;
  class sll_iterator;

  class node
  {
    friend class sll_iterator;  // sll_iterators that need access to node's private data
    friend class sLinkedList<T>; // list that needs access to node's pointers
    
    T data;
    node* next;
    
    public:
    node<T>(const T& data);
    T& operator();
    // to be implemented: a destructor.
    // to be implemented: a copy constructor.
    // to be implemented: a copy assignment operator.
  };
  
public:
  sLinkedList<T>();
  void push_front(const T& obj);
  void push_back(const T& obj);
  void insert(const T& obj, int loc = 1);
  void remove(const T& obj);
  void remove(int loc);
  int size();
  // to be implemented: a destructor.
  // to be implemented: a copy constructor.
  // to be implemented: a copy assignment operator.  
  // to be implemented: sort functions.
};

template typename<T>
class sll_iterator // declarations for the friend class for node
{ // an iterator for a singly linked list
  node* curr;
  
  public:
  sll_iterator(node* nodeptr);
  T& operator*();
  sll_iterator operator++();
  sll_iterator operator++(int);
  // still needs implementation of:
  // a copy constructor
  // a destructor
  // a copy assignment operator.
};

#include "sLinkedList.tpp"