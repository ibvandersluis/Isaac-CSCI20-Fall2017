//Created By: Isaac Vander Sluis
//Created On: 9/26/2017

/* ~~~~SWAPRAND~~~~
   This program takes two integers from the user, swaps the values stored
   in those memory locations, and generates a random number between those
   two numbers. The random number is returned to the user. Occam's razor
   would cut away the Swap() part of this function, but alas, we keep it in
   for the learning.
*/

#include <iostream>
#include <cstdlib>  //Gives us rand() and srand()
#include <ctime>    //Gives us time() for giving rand() a unique seed
using namespace std;

/*Swaps the values stored in two integer variables.
  Input: takes two integers
  Output: none*/
void Swap(int& num1, int& num2){
    int num2a = num2;
    num2 = num1;
    num1 = num2a;
    
    return;
}

/*Calls the Swap() function on two numbers, then determines a random number between the two values.
  Input: takes two integers
  Output: returns a random number between the two integers*/
int SwapRand(int num1, int num2){
    srand(time(0));                              //Generates unique seed based on current time
    Swap(num1, num2);                            //Swaps the values stored in SwapRand() input
    int difference = (num2 - num1) + 1;          //Determines the difference between the two input numbers, inclusive
    int rand_int = rand() % difference + num2;   //Generates random number
    
    return rand_int;
}

int main() {
    int min = 0;
    int max = 0;
    
    cout << "Enter the minimum range of the random number: " << endl; //Gets input from the user
    cin >> min;
    cout << "Enter the maximum range of the random number: " << endl;
    cin >> max;
    
    cout << SwapRand(min, max);                                       //Runs SwapRand() using values from the user
    
    return 0;
}

/*

Enter the minimum range of the random number: 
1
Enter the maximum range of the random number: 
10
5

Enter the minimum range of the random number: 
5
Enter the maximum range of the random number: 
82
58

Enter the minimum range of the random number: 
22
Enter the maximum range of the random number: 
73
29

*/

