// sLinkedList.tpp
// Singly Linked List: Template Implementations and function definitions
// (function definitions soon to be moved to sLinkedList.cpp)

// Author: Jossie Calderon
// with references to Chris Lacher's List<T> implementation
// particularly the addition of friend classes to his Node structure
// such as his Iterator structure which helps traverse the list.
// Also the use (but not declaration or definition) of the push_back function.

T& node::operator*()
{
  return data;
}

template typename<T>
sLinkedList<T>::sLinkedList() : begin(nullptr), end(nullptr), size(0)
{
  
}

template typename<T>
node<T>::node(const T& data) : data(data), curr(this), next(nullptr)
{

}

// This method inserts at the beginning of the list.
// Soon, this method will insert and keep the list sorted. 
//(It will be named and implemented differently)
template typename<T>
void sLinkedList<T>::push_front(const T& obj)
{
  node* newNode = new node(obj); // initialize the node to insert. it has to be
  // dynamically allocated or the node will disappear once it's out of scope.
  if(begin == nullptr) // if the list is empty
  {
    begin = newNode; // the current node, which was just initialized
    end = newNode->next; // the next node, which is nothing
  }
  else // else the list has one or more elements
  { // we sandwich the node between before the beginning and the beginning.
    newNode->next = begin; // assign the newly initialized node newNode to
    // point to the beginning because that's the node we will be following.
    begin = newNode; // the current node, added to the beginning.
    // Notice how the beginning is changed to newNode.
    // The end does not get changed because another node points to the end.
  }
  ++size; // increase the list size.
}

// Note: This operation is not efficient in singly linked lists, unlike
// doubly linked lists.
void sLinkedList<T>::push_back(const T& obj)
{
  // executing the below function has the same effect.
  insert(obj, size() + 1);
}

// This method inserts a node at a specified (loc) location in the list.
// if no integer is specified, it inserts it at the beginning.
template typename<T>
void sLinkedList<T>::insert(const T& obj, int loc)
{
  if(loc == 1) // if we want to add it to the beginning
  { // don't create a new node just yet to save efficiency.
    push_front(obj);
    return;
  }
  
  if(loc < 1 || loc > size + 1) // invalid entry
  {
    std::cerr << "Usage: Point of entry must be between 1 and " << size() + 1 <<
      std::endl;
  }
  else // else the list has one or more elements
  {
    node* newNode = new node(obj); // initialize the node to insert. it has to
    // be dynamically allocated or the node will disappear when out of scope.    
    int nodesTouched = 1; // nodes we have touched, starting from the beginning
    for(sll_iterator iter = begin; iter != end; ++iter)
    {
      if(nodesTouched + 1 == loc) // We're inserting the node in front of the
      // current node.
      {
        newNode->next = iter->curr->next; // set newNode to follow what the
        // current node is following.
        iter->curr->next = newNode; // set the current node to follow newNode.
        ++size; // increase the list size.
        break;
      }
      ++nodesTouched; // we are touching the next node.
    }
  }
}

void sLinkedList<T>::remove(const T& obj) // Remove based on linear search for
// object
{
  // if the size of the list is 1
  if(*begin == obj)
  {
    delete begin;
    begin = nullptr;
    --size;
    return;
  }
  for(sll_iterator iter = begin; iter != end; ++iter)
  {
    if(*iter.curr->next == obj) // The next node contains this data!
    {
      node* be_gone = iter.curr->next; // address of node we're 'delete'ing
      iter.curr->next = be_gone->next;
      delete be_gone;
      be_gone = nullptr;
      --size;
      return;
    }
  }
  std::cerr << "No node containing object found; no node removed." << endl;
}

void sLinkedList<T>::remove(const T& obj) // Remove based on position
{
  if(loc == 1) 
  {
    delete begin;
    begin = nullptr;
    --size;
    return;
  }
  
  if(loc < 1 || loc > size + 1) // invalid entry
  {
    std::cerr << "Usage: Point of entry must be between 1 and " << size() + 1 <<
      std::endl;
  }
  else // else the list has one or more elements
  {  
    int nodesTouched = 1; // nodes we have touched, starting from the beginning
    for(sll_iterator iter = begin; iter != end; ++iter)
    {
      if(nodesTouched + 1 == loc)
      {
        node* be_gone = iter.curr->next; // address of node we're 'delete'ing
        iter.curr->next = be_gone->next;
        delete be_gone;
        be_gone = nullptr;
        --size;
        return;
      }
      ++nodesTouched; // we are touching the next node.
    }
  }
}

template typename<T>
int sLinkedList<T>::size()
{
  return size;
}

//conversion constructor for node pointer to sll_iterator
sll_iterator::sll_iterator(node* nodeptr)
{
  curr = nodeptr; // the current node the iterator is at.
  // see why we need to have iterator as a friend of node? To access the next
  // node, which is data stored in class node.
}

// De-reference operator
template typename<T>
T& sll_iterator::operator*()
{
  return curr->data;
}

// Pre-increment overload meant for sll_iterators.
sll_iterator sll_iterator::operator++()
{
  curr = curr->next;
  if(curr->next != nullptr)
    curr->next = curr->next->next;
  return *this;
}

// Post-increment overload meant for sll_iterators.
sll_iterator sll_iterator::operator++(int)
{
  sll_iterator past_life = *this; // copy constructor
  curr = curr->next;
  if(curr->next != nullptr)
    curr->next = curr->next->next;
  return past_life;
}













