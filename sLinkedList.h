// sLinkedList.h
// Jossie Calderon
//
// A singly-linked of integers
// v-1.0

#include <iostream>

class sLinkedList
{
  class node
  {
    friend class sLinkedList;
    
    int mData;
    node* next;
    
    public:
    node(int data);
  };
  
  int mSize;
  node* begin;
  
  public:
  sLinkedList();
  void push_front(int);
  void pop_front();
  int length();
  void print();
};
