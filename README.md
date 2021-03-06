# Structures
A custom implementation of various structures defined in the stl.

### Updates:

###### 4:05pm 6/29/2016
**Singly linked list: Follow the rule of three** The program's `sLinkedList` class now contains a copy constructor, copy assignment operator, and destructor.

###### 12:59pm 6/29/2016
**Singly linked list: Add a makefile, typical list functions, and `reverse()` function** The makefile will compile the .cpp files and produce object files + an executable. If this is running on a Linux environment such as cygwin, the .exe can be removed.

###### 2:47pm 6/28/2016
**Singly linked list: Scrap and restart** Scrap the old project, implement a simple, non-generic version of a linked list that uses strictly integers, and work from there.

###### 8:53pm 6/26/2016

**Singly linked list: Added two base files** These two base files contain information to compile and run a linked list using single, forward links. Soon to come is the `reverse()` function, `swap()` function, and others I currently cannot think off the top of my head. 

The sort functions cannot be implemented in a singly linked list, nor a doubly linked list. The complexity will be too high because swapping distant elements (such as swapping the beginning with the end) is O(n) in itself. Sort functions will become implemented with structures that use random access. 

These .h and .tpp files I just uploaded have not been compiled or ran on my compiler, a g++ v-5.4.0 compiler. I cannot guarantee they are error free as of yet. Testing will be done soon.
