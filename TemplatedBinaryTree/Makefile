OBJS = dist/obj/Driver.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
MKDIR_P = mkdir -p

all: dist/obj dist/BinaryTree

dist/BinaryTree : $(OBJS)
	    $(CC) $(LFLAGS) $(OBJS) -o $@

dist/obj : 
	$(MKDIR_P) $@

dist/obj/Driver.o : src/AbstractBinarySearchTree.h src/BinarySearchTreeImpl.h src/Driver.cpp
	    $(CC) $(CFLAGS) src/Driver.cpp -o $@
clean:
	    \rm -rf dist
