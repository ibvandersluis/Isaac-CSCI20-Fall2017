# makefile example for CSCI 20

#name of the executable file
all: execute

#creates the executable from both the object files
execute: main.o myclass.o 
	g++ -Wall -g -o execute main.o myclass.o

#creates the main object file
exampleObj: main.cpp  
	g++ -Wall -g -c main.cpp

# creates the class object file
exampleClassObj: myclass.cpp 
	g++ -Wall -g -c myclass.cpp	
	
	
# to run the make file, type in make.