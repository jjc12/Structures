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
  void push_back(int);
  void pop_front();
  void pop_back();
  void insert(int data, int loc);
  // void remove(int data); To be implemented with generics.
  void remove(int loc);
  void reverse();
  int length();
  void print();
};
