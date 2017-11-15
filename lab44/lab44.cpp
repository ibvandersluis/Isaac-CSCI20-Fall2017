//Created By: Isaac Vander Sluis
//Created On: 11/9/17

/*
    ~~~~~~USERNAME GENERATOR~~~~~~
    This program uses C-string and character manipulation to generate viable
    usernames to a user based on their first and last name. The first name is
    not allowed to exceed 10 characters, and the last name is not allowed to
    exceed 20. The program prints a warning to the user if the first name and
    last name match. Barring these restrictions, the program creates 3 different
    username options and prints them to the user.
*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//This function takes a character array as input and runs the "tolower()" function on each item
void MakeLower(char string[]) {
    for (int i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }
    
    return;
}

//This function takes a character array as input and prints each element, sans whitespace
void PrintString(char string[]) {
    for (int i = 0; i < strlen(string); i++) {
        if (isspace(string[i]) == 0) {
            cout << string[i];
        }
    }
    cout << endl;
    
    return;
}

int main() {
    const int STR_MAX = 30;             //Character arrays are hard-coded to allow 29 characters, but if-else branches will functionally limit this further.
    char first_name[STR_MAX] = "";      //Initializes character array to store first name
    char last_name[STR_MAX] = "";       //Initializes character array to store last name
    
    char option1[STR_MAX] = "";         //Initializes character array to store first suggested username
    char option2[STR_MAX] = "";         //Initializes character array to store second suggested username
    char option3[STR_MAX] = "";         //Initializes character array to store third suggested username
    
    cout << "Enter your first name: " << endl;      //Prompts user for first name
    cin >> first_name;
    
    if (strlen(first_name) > 10) {                  //Prints warning if first name is too long
        cout << "WARNING: exceeds maximum size." << endl;
    }
    
    cin.ignore(1);
    cout << "Enter your last name: " << endl;       //Prompts user for last name
    cin.getline(last_name, STR_MAX);
    
    if (strlen(last_name) > 20) {                   //Prints warning if last name is too long
        cout << "WARNING: excees maximum size." << endl;
    }
    
    if (strcmp(first_name, last_name) == 0) {       //Prints warning to user if first name matches last name
        cout << "WARNING: first name matches last name." << endl;
    }
    
    strcpy(option1, first_name);                    //sets option1 to the first name appended to the last name
    strcat(option1, last_name);
    MakeLower(option1);
    
    strncpy(option2, first_name, 1);                //sets option2 to the first initial appended to the last name
    strcat(option2, last_name);
    MakeLower(option2);
    
    strcpy(option3, first_name);                    //Sets option3 to the first name appended to the last initial
    strncat(option3, last_name, 1);
    MakeLower(option3);
    
    cout << endl << "Your username options are: " << endl;  //Prints options to the user
    PrintString(option1);
    PrintString(option2);
    PrintString(option3);
    
    return 0;
}

/*

Enter your first name: 
Isaac
Enter your last name: 
Vander Sluis

Your username options are: 
isaacvandersluis
ivandersluis
isaacv


Enter your first name: 
April       
Enter your last name: 
Browne

Your username options are: 
aprilbrowne
abrowne
aprilb


Enter your first name: 
AnaElizabeth
WARNING: exceeds maximum size.
Enter your last name: 
Hazeltine-Smith

Your username options are: 
anaelizabethhazeltine-smith
ahazeltine-smith
anaelizabethh 


Enter your first name: 
James 
Enter your last name: 
James
WARNING: first name matches last name.

Your username options are: 
jamesjames
jjames
jamesj

*/