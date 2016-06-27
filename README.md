# Structures
An implementation of various structures defined in the stl, with custom functions added.

### Updates:

###### 8:53pm 6/26/2016

Singly linked list: Added two base files
These two base files contain information to compile and run a linked list using single, forward links. Soon to come is the reverse() function, swap(), function, and others I currently cannot think off the top of my head. 

The sort functions cannot be implemented in a singly linked list, nor a doubly linked list. The complexity will be too high because swapping distant elements (such as swapping the beginning with the end) is O(n) in itself. Sort functions will become implemented with structures that use random access. 

These .h and .tpp files I just uploaded have not been compiled or ran on my compiler, a g++ v-5.4.0 compiler. I cannot guarantee they are error free. 
