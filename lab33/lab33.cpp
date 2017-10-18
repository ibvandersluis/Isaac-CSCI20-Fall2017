//Created By: Isaac Vander Sluis
//Created On: 10/17/17

/* ~~~~NUMBER GUESSING LOOP~~~~
   This program generates a random number between 1..50 and asks the user to
   guess what it is. The program notifies the user if the number is too high,
   too low, or outside the acceptable range, and asks them to guess again. The
   loop repeats until the number has been guessed.
*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int guess_num = rand() % 50 + 1;    //generates a random number between 1..50
    int user_num = 0;
    int i = 0;

    cout << "Are you ready, human?" << endl;
    
    for (i = 10; i > 0; --i) {          //counts down from 10..1
        cout << i << "..." << endl;
    }
    
    cout << "Guess a number between 1 and 50: " << endl; //prompting user for input
    cin >> user_num;
    
    while (user_num != guess_num) {                      //if initial guess isn't correct...
        if ((user_num > 0) && (user_num < guess_num)) {  //notifies user if guess is too low, gets new guess
            cout << "Too Low" << endl;
            cout << "Guess again: " << endl;
            cin >> user_num;
        } else if ((user_num < 51) && (user_num > guess_num)) {  //notifies user if guess is too high, gets new guess
            cout << "Too High" << endl;
            cout << "Guess again: " << endl;
            cin >> user_num;
        } else {                                         //error message if guess is outside of range
            cout << "ERROR: Invalid value" << endl;
            cout << "Guess again: " << endl;
            cin >> user_num;
        }
    }
    
    cout << "Just Right" << endl;                        //Notifies user that they have guessed correctly and the game is over
    cout << "GAME OVER";
    
    return 0;
}

/*

Are you ready, human?
10...
9...
8...
7...
6...
5...
4...
3...
2...
1...
Guess a number between 1 and 50: 
25
Too Low
Guess again: 
42
Too Low
Guess again: 
45
Too Low
Guess again: 
48
Too Low
Guess again: 
50
Just Right
GAME OVER

*/