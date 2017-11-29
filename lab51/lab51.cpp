#include <iostream> 
#include <iostream> 
#include <cstring> 
using namespace std;   

int main() {
    int nameLength = 0;                                         //initializes variable nameLength of type int to zero
    char * name = new char[];                                   //initializes pointer variable name to indicate a new array of type char

    cout << "Please enter a 10 letter word or less" << endl;    //prompts user for a word of 10 letters or less
    cin >> name;                                                //assigns user input to the new char array designated on line 8

    char * head  = name;                                        //initializes pointer variable head to the variable name, also a pointer
    char * tail = name;                                         //initializes pointer variable tail to the variable name. Now two pointers are pointing to the pointer name
    nameLength = strlen(*name);                                 //sets nameLength to the length of the word stored in the memory location that name points to

    cout << "Your word is " << firststr << endl;                //supposed to print the word to the user, but the variable firststr has not been declared

    if (nameLength<10)                                          //runs this code if the word is 9 characters or shorter (conflicts with instructions in line 10)
    {
         while (*head != '\0')                                  //while the end of the string has not been reached...
         {                                                      // *head refers to the value that head points to, which is the value stored in name, which is the character array
                cout << *head;                                  //starts iterating through the char array pointed to by name, starting at index 0
                head++;                                         //increments the memory location
         }
     }
     else
     {
          cout << "WARNING WORD TOO BIG TO DISPLAY!!" << endl;  //prints warning if word is larger than 9 characters
     }

     cout << endl;

     tail = &name[strlen(name) - 1];                            //assigns tail to the memory location of the last element in the array pointed to by name

     if (nameLength < 10)                                       //prints array backwards
     {
          while (tail != name)                                  //loop continues until the end of the char array
          {
                 cout << *tail;                                 //outputs the value stored at the end of the array
                 tail--;                                        //decrement the variable marking the end of the array
          }
     }
     cout << endl;

     head = name;                                               //head now stores the memory location stored in name
     tail = &name[strlen(name) - 1];                            //assigns tail to the memory location of the last element in the array pointed to by name

     head++;                                                    //increments head
     tail--;                                                    //decrements tail

     if (*head == *tail)                                        //if the value stored in the variable pointed to by head is equivalent to that of tail,
     {                                                          //prints that the word is a palindrome
         cout << "It is an palindrome!" << endl;
     }
     else
     {                                                          //else prints that it's not a palindrome
         cout << "It is not an palindrome" << endl;
     }

     return 0; 
}