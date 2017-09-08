//Created By: April Browne
//Created On: 8/22/2016               (This is the header)
 
 #include <iostream>                //(These are the preprocessor directives)
 using namespace std;
 
 int main()                         //(This is the main code)
 {
     int studentID = 0;                             //Declares the variable studentID and initializes it to 0
     cout<<"Please enter a student ID number: ";    //Prompts the user for input and gives user direction
     cin >> studentID;                              //User inputs the requested information
                                                    //Whitespace....
     cout<<"Hello World! "<<studentID<<endl;        //Prints "Hello World!" followed by the student ID number provided by the user
 }
 
//Identify with a //* 2-3 items that seem important
//Identify with a //? 2-3 items that seem incorrect, unclear or where you have questions
//Identify the different parts of the program.
//Create comments that show the algorithm of the program.

/*************************************************/
//* Specified what is required from the user
//* studentID initialiezed to zero because we will get the value from the user
//? Add whitespace between elements for readability
//? Does there need to be whitespace on line 12?