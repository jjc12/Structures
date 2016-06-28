// sLinkedList.cpp
// Jossie Calderon

#include "sLinkedList.h"

sLinkedList::node::node(int data) : mData(data), next(nullptr)
{
  
}

sLinkedList::sLinkedList() : mSize(0), begin(nullptr)
{
  
}

void sLinkedList::push_front(int data)
{
  node* newNode = new node(data);
  
  if(newNode == nullptr)
  {
    std::cerr << "Memory for a node could not be allocated." << std::endl;
    std::cerr << "Ceasing operations..." << std::endl;
    return;
  }
  
  if(begin == nullptr)
  {
    begin = newNode;
  }
  else
  {
    newNode->next = begin;
    begin = newNode;
  }
  
  ++mSize;
}

void sLinkedList::pop_front()
{

  if(begin == nullptr)
  {
    std::cerr << "There is nothing to pop." << std::endl;
  }
  else
  {
    node* nodeToDelete = begin;
    begin = nodeToDelete->next;
    delete nodeToDelete;
    --mSize;
  }
  
}

int sLinkedList::length()
{
  return mSize;
}

void sLinkedList::print()
{
  
  if(begin == nullptr)
  {
    std::cerr << "The list is empty." << std::endl;
  }
  else
  {
    for(node* iter = begin; iter != nullptr; iter = iter->next)
    {
      std::cout << iter->mData;
      
      if(iter->next != nullptr)
      {
        std::cout << " -> ";
      }
      else
      {
        std::cout << std::endl;
      }
      
    }
  }
  
}
