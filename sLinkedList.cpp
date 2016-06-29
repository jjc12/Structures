// sLinkedList.cpp
// Jossie Calderon

#include "sLinkedList.h"

sLinkedList::node::node(int data) : mData(data), next(nullptr)
{
  
}

sLinkedList::sLinkedList() : mSize(0), begin(nullptr)
{
  
}

sLinkedList::sLinkedList(const sLinkedList& someList) : mSize(0),
  begin(nullptr)
{
  node* iter = someList.begin;
  while(iter != nullptr)
  {
    push_back(iter->mData);    
    iter = iter->next;
  }
}

sLinkedList& sLinkedList::operator=(const sLinkedList& someList)
{
  
  if(this != &someList)
  {
    
    clear();
    for(node* iter = someList.begin; iter != nullptr; iter = iter->next)
    {
      push_back(iter->mData);
    }
  }

}

sLinkedList::~sLinkedList()
{
  clear();
}

void sLinkedList::clear()
{
  if(length() > 0)
  {
    while(length() != 1)
    {
      pop_front();
    }
    
    delete begin;
    --mSize;
  }
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

void sLinkedList::push_back(int data)
{
  
  if(begin == nullptr)
  {
    push_front(data);
  }
  else
  {
    node* newNode = new node(data);
    
    if(newNode == nullptr)
    {
      std::cerr << "Memory for a node could not be allocated." << std::endl;
      std::cerr << "Ceasing operations..." << std::endl;
      return;
    }
    
    node* nodeBeforeNew = begin;
    while(nodeBeforeNew->next != nullptr)
    {
      nodeBeforeNew = nodeBeforeNew->next;
    }
    nodeBeforeNew->next = newNode;
    newNode->next = nullptr;
    ++mSize;
  }
  
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

void sLinkedList::pop_back()
{

  if(begin == nullptr)
  {
    std::cerr << "There is nothing to pop." << std::endl;
  }
  else if (begin->next == nullptr)
  {
    pop_front();
  }
  else
  {
    node* nodeToDelete = begin;
    while(nodeToDelete->next->next != nullptr)
    {
      nodeToDelete = nodeToDelete->next;
    }
    delete nodeToDelete->next;
    nodeToDelete->next = nullptr;
    --mSize;
  }
  
}

void sLinkedList::insert(int data, int loc)
{
  
  if(loc < 1 || loc > length() + 1)
  {
    std::cout << "Usage: Enter a position between 1 and " << length() + 1
      << std::endl;
  }
  else if(loc == 1)
  {
    push_front(data);
  }
  else
  {
    node* newNode = new node(data);
    
    if(newNode == nullptr)
    {
      std::cerr << "Memory for a node could not be allocated." << std::endl;
      std::cerr << "Ceasing operations..." << std::endl;
      return;
    }
    
    int count = 1;
    for(node* iter = begin; ; iter = iter->next)
    {
      
      if(count + 1 == loc)
      {
        newNode->next = iter->next;
        iter->next = newNode;
        break;
      }
      
      ++count;
    }
    ++mSize;
  }
  
}

/* void sLinkedList::remove(int data)
{
  
} */

void sLinkedList::remove(int loc)
{

  if(loc < 1 || loc > length())
  {
    
    if(length() == 0)
    {
      std::cerr << "The list is empty." << std::endl;
    }
    else
    {
    std::cerr << "Usage: Enter a position between 1 and " << length()
      << std::endl;
    }
    
  }
  else if(loc == 1)
  {
    pop_front();
  }  
  else
  {   
    int count = 1;
    for(node* nodeBeforeDeleted = begin; ;
      nodeBeforeDeleted = nodeBeforeDeleted->next)
    {
      
      if(count + 1 == loc)
      {
        node* deletedNode = nodeBeforeDeleted->next;
        nodeBeforeDeleted->next = deletedNode->next;
        delete deletedNode;
        deletedNode = nullptr;
        break;
      }
      
      ++count;
    }
    --mSize;
  }
  
}

int& sLinkedList::retrieve(int loc)
{
  if(begin == nullptr)
  {
    std::cerr << "The list is empty: Undefined behavior" << std::endl;
    return begin->mData;
  }
  int count = 1;
  for(node* iter = begin; count <= length(); iter = iter->next, ++count)
  {
    if(count == loc)
    {
      return iter->mData;
    }
  }
}

void sLinkedList::reverse()
{
  if(length() <  2)
  {
    std::cerr << "There is nothing to reverse." << std::endl;
  }
  else
  {
    
    node** nodesPastBeginning = new node*[length() - 1];
    node* iter = begin->next;
    for(int i = 0; i < length() - 1;
      ++i, iter = iter->next)
    {
      nodesPastBeginning[i] = iter;
    }
    for(int i = 0; i < length() - 1; ++i)
    {
      iter = nodesPastBeginning[i];
      iter->next = begin;
      if(i == 0)
      {
        begin->next = nullptr;
      }
      begin = iter;
    }
    
    // Delete the array but not what the array's pointers point to!
    delete[] nodesPastBeginning;
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
