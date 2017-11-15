//Created By: Isaac Vander Sluis
//Created On: 11/14/17

/*
    ~~~~~~USERNAME GENERATOR~~~~~~
    This program uses strings and string tools to generate viable
    usernames to a user based on their first and last name. The first name is
    not allowed to exceed 10 characters, and the last name is not allowed to
    exceed 20. The program prints a warning to the user if the first name and
    last name match. Barring these restrictions, the program creates 3 different
    username options and prints them to the user.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//This function takes a string as input and runs the "tolower()" function on each item
void MakeLower(string& str) {
    for (int i = 0; i < str.length(); i++) {
        str.at(i) = tolower(str.at(i));
    }
    
    return;
}

//This function takes a character array as input and prints each element, sans whitespace
void PrintString(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (isspace(str.at(i)) == 0) {
            cout << str.at(i);
        }
    }
    cout << endl;
    
    return;
}

int main() {
    string first_name = "";      //Initializes character array to store first name
    string last_name  = "";      //Initializes character array to store last name
    
    string option1    = "";      //Initializes character array to store first suggested username
    string option2    = "";      //Initializes character array to store second suggested username
    string option3    = "";      //Initializes character array to store third suggested username
    
    cout << "Enter your first name: " << endl;      //Prompts user for first name
    cin >> first_name;
    
    if (first_name.length() > 10) {                 //Prints warning to user if first name is too long
        cout << "WARNING: exceeds maximum size." << endl;
    }
    
    cin.ignore(1);                                  //Ignores null character left in cache
    cout << "Enter your last name: " << endl;       //Prompts user for last name
    getline(cin, last_name);
    
    if (last_name.length() > 20) {                  //Prints warning to user if last name is too long
        cout << "WARNING: exceeds maximum size." << endl;
    }
    
    if (last_name == first_name) {                  //Prints warning to user if first name matches last name
        cout << "WARNING: first name matches last name." << endl;
    }
    
    option1 = first_name + last_name;               //sets option1 to the first name appended to the last name
    MakeLower(option1);
    
    option2 = first_name.at(0) + last_name;         //sets option2 to the last name appended to the first initial
    MakeLower(option2);
    
    option3 = first_name + last_name.at(0);         //Sets option3 to the first name appended to the last initial
    MakeLower(option3);
    
    cout << endl << "Your username options are: " << endl;  //Prints options to the user
    cout << "• "; PrintString(option1);
    cout << "• "; PrintString(option2);
    cout << "• "; PrintString(option3);
    
    return 0;
}

/*

Enter your first name: 
Isaac
Enter your last name: 
Vander Sluis

Your username options are: 
• isaacvandersluis
• ivandersluis
• isaacv


Enter your first name: 
April Browne
Enter your last name: 

Your username options are: 
• aprilbrowne
• abrowne
• aprilb


Enter your first name: 
AnaElizabeth  
WARNING: exceeds maximum size.
Enter your last name: 
Hazeltine-Smith

Your username options are: 
• anaelizabethhazeltine-smith
• ahazeltine-smith
• anaelizabethh


Enter your first name: 
James 
Enter your last name: 
James
WARNING: first name matches last name.

Your username options are: 
• jamesjames
• jjames
• jamesj

*/