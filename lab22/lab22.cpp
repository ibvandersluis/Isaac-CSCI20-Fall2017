//Created By: Isaac Vander Sluis
//Created On: 9/21/17

/* ~~~~RANDINT FUNCTION~~~~~
   This program declares a function MakeRandNum that generates a random integer
   between 1 and 100. It then calls that function inside the main and prints
   the output to the user.
*/

#include <iostream>
#include <cstdlib>  //Allows me to use rand() and srand()
#include <ctime>    //Allows me to use the time() function
using namespace std;

void MakeRandNum(){
    srand(time(0)); //Generates a unique seed based on current time
    int rand_num = rand() % 100 + 1; //Generates random number 1-100
    
    cout << "Your random number is " << rand_num << "." << endl; //Outputs result to user
    
    return;
}

int main(){
    MakeRandNum(); //Function call
    
    return 0;
}

//Your random number is 98.