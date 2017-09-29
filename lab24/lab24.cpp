//Created By: Isaac Vander Sluis
//Created On: 9/28/17

/* ~~~~FUNCTION RETURN GAUNTLET~~~~
   This program gets a number range from the user, then generates a random
   number within that range. That number is then converted into kilograms
   and back into pounds (the original number).
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//--Function declarations--
void Swap(int& num1, int& num2);
int SwapRand(int num1, int num2);
double LbsToKgs(double pounds);
double KgsToLbs(double kilos);

//--Global variables--
const double LBS_PER_KG = 2.20462262;
const double KGS_PER_LB = 0.45359237;

int main() {
    double rand_min = 0; //Initializing local variables
    double rand_max = 0;
    double user_num = 0;
    
    cout << "Enter minimum of random number range: " << endl; //Getting information from user
    cin >> rand_min;
    cout << "Enter maximum of random number range: " << endl;
    cin >> rand_max;
    
    user_num = SwapRand(rand_min, rand_max);                  //Doing math and printing results
    
    cout << endl << endl << "Your random number is " << user_num << "." << endl;
    
    user_num = LbsToKgs(user_num);
    
    cout << endl << "That would be " << user_num << " kgs!" << endl;
    
    user_num = KgsToLbs(user_num);
    
    cout << "...Or, that would be " << user_num << " pounds."<< endl;
    
    return 0;
}


//--Function definitions--
/*Swaps the values stored in two integer variables.
  Input: takes two integers
  Output: none*/
void Swap(int& num1, int& num2) {
    int num2a = num2;
    num2 = num1;
    num1 = num2a;
    
    return;
}

/*Calls the Swap() function on two numbers, then determines a random number between the two values.
  Input: takes two integers
  Output: returns a random number between the two integers*/
int SwapRand(int num1, int num2) {
    srand(time(0));                              //Generates unique seed based on current time
    Swap(num1, num2);                            //Swaps the values stored in SwapRand() input
    int difference = (num2 - num1) + 1;          //Determines the difference between the two input numbers, inclusive
    int rand_int = rand() % difference + num2;   //Generates random number
    
    return rand_int;
}

/*Converts Pounds to Kilograms.
  Input: takes one double, representing pounds
  Output: returns a double that is the equivalent value in Kgs*/
double LbsToKgs(double pounds) {
    return pounds * KGS_PER_LB;
}

/*Converts Kilograms to Pounds.
  Input: takes one double, representing kilograms
  Output: returns a double that is the equivalent value in Lbs*/
double KgsToLbs(double kilos) {
    return kilos * LBS_PER_KG;
}

/*

Enter minimum of random number range: 
15
Enter maximum of random number range: 
145


Your random number is 85.

That would be 38.5554 kgs!
...Or, that would be 85 pounds.

*/