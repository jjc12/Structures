CC = g++
FLAGS = -std=c++0x
OBJ = main.o sLinkedList.o
EXEC = main.exe

$(EXEC): $(OBJ)
	$(CC) $(FLAGS) -o $(EXEC) $(OBJ)

main.o: main.cpp
	$(CC) $(FLAGS) -c -o main.o main.cpp
  
sLinkedList.o : sLinkedList.cpp sLinkedList.h
	$(CC) $(FLAGS) -c -o sLinkedList.o sLinkedList.cpp
  
.PHONY: clean

clean:
	rm *.o $(EXEC)