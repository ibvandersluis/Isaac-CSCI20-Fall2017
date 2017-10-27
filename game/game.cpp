//Created By: Isaac Vander Sluis
//Created On: 10/26/17

/*
   ~~~~~~~~HI HO! CHERRY-O~~~~~~~~
   This program simulates the Hasbro game Hi Ho! Cherry-O. In this game, the user
   plays against the computer. Each player has a tree with the same random number
   of cherries on it. The players take turns; each turn they spin for a random
   event which alters the number of cherries on the tree. The first player to
   clear all cherries from their tree wins the game.
*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

class Computer {
    public:
        void SetTreeCherries(int num_tree_cherries);       //mutator
        void SetBasketCherries(int num_basket_cherries);   //mutator
        
        int const GetTreeCherries();                       //accessor
        int const GetBasketCherries();                     //accessor
    private:
        int tree_cherries_;                                //class variable
        int basket_cherries_;                              //class variable
};

//This function sets the number of cherries on the computer's tree
void Computer::SetTreeCherries(int num_tree_cherries) {
    tree_cherries_ = num_tree_cherries;
    
    return;
}

//This function sets the number of cherries in the computer's basket
void Computer::SetBasketCherries(int num_basket_cherries) {
    basket_cherries_ = num_basket_cherries;
    
    return;
}

//This function returns the number of cherries on the computer's tree
int const Computer::GetTreeCherries() {
    return tree_cherries_;
}

//This function returns the number of cherries in the computer's basket
int const Computer::GetBasketCherries() {
    return basket_cherries_;
}

int main() {
    Computer computer1;                             //initializes instance of Computer class
    srand(time(0));                                 //seeds rand() with current time
    int start_cherries = rand() % 10 + 1;           //sets initial number of cherries to a random number between 1 and 10
    int player_tree_cherries = start_cherries;      //initializes number of cherries on player's tree
    int player_basket_cherries = 0;                 //initializes number of cherries in player's basket
    computer1.SetTreeCherries(start_cherries);      //initializes number of cherries on computer's tree
    computer1.SetBasketCherries(0);                 //initializes number of cherries in computer's basket
    int spin = 0;                                   //initializes variable used in the game's spinner
    int turn = 0;                                   //initializes variable to track whose turn it is
    char spin_char = ' ';                           //initializes variable for user to spin
    
    cout << "Let's play Hi Ho! Cherry-O." << endl;  //Gives starting information and basic directions to the user
    cout << "You each have " << start_cherries << " cherries on your tree." << endl;
    cout << "Take turns spinning. Whoever removes all the cherries from their tree first wins." << endl;
    
    
    while ((player_tree_cherries > 0) && (computer1.GetTreeCherries() > 0)) {  //This loop repeats until there is a winner
        if (turn % 2 == 0) {  //Determines whose turn it is based on whether the turn variable is odd or even
            cout << "It's your turn!" << endl;
            cout << "Press 'S' to spin!" << endl;  //By pressing a button to proceed, the user has the illusion of being in control :)
            cin >> spin_char;
            while ((spin_char != 's') && (spin_char != 'S')) {
                cout << "Error: enter 'S' to spin." << endl;
                cin >> spin_char;
            }
            spin = rand() % 7 + 1; //Generates a random number between 1..7
            switch (spin) { //random number determines event
                case 1:
                    cout << "Take 1 Cherry" << endl;
                    player_tree_cherries -= 1;
                    player_basket_cherries += 1;
                    break;
                case 2:
                    cout << "Take 2 Cherries" << endl;
                    player_tree_cherries -= 2;
                    player_basket_cherries += 2;
                    break;
                case 3:
                    cout << "Take 3 Cherries" << endl;
                    player_tree_cherries -= 3;
                    player_basket_cherries += 3;
                    break;
                case 4:
                    cout << "Take 4 Cherries" << endl;
                    player_tree_cherries -= 4;
                    player_basket_cherries += 4;
                case 5:
                    cout << "Dog" << endl;
                    if (player_basket_cherries >= 2) {
                        player_tree_cherries += 2;
                        player_basket_cherries -= 2;
                    } else if (player_basket_cherries == 1) {
                        player_tree_cherries += 1;
                        player_basket_cherries -= 1;
                    }
                    break;
                case 6:
                    cout << "Bird" << endl;
                    if (player_basket_cherries >= 2) {
                        player_tree_cherries += 2;
                        player_basket_cherries -= 2;
                    } else if (player_basket_cherries == 1) {
                        player_tree_cherries += 1;
                        player_basket_cherries -= 1;
                    }
                    break;
                case 7:
                    cout << "Spilled Basket" << endl;
                    player_tree_cherries = start_cherries;
                    player_basket_cherries = 0;
                    break;
            }
        } else if (turn % 2 == 1) {
            cout << "It's the computer's turn!" << endl;
            spin = rand() % 7 + 1;
            switch (spin) {
                case 1:
                    cout << "Take 1 Cherry" << endl;
                    computer1.SetTreeCherries(computer1.GetTreeCherries() - 1);
                    computer1.SetBasketCherries(computer1.GetBasketCherries() + 1);
                    break;
                case 2:
                    cout << "Take 2 Cherries" << endl;
                    computer1.SetTreeCherries(computer1.GetTreeCherries() - 2);
                    computer1.SetBasketCherries(computer1.GetBasketCherries() + 2);
                    break;
                case 3:
                    cout << "Take 3 Cherries" << endl;
                    computer1.SetTreeCherries(computer1.GetTreeCherries() - 3);
                    computer1.SetBasketCherries(computer1.GetBasketCherries() + 3);
                    break;
                case 4:
                    cout << "Take 4 Cherries" << endl;
                    computer1.SetTreeCherries(computer1.GetTreeCherries() - 4);
                    computer1.SetBasketCherries(computer1.GetBasketCherries() + 4);
                    break;
                case 5:
                    cout << "Dog" << endl;
                    if (computer1.GetBasketCherries() >= 2) {
                        computer1.SetTreeCherries(computer1.GetTreeCherries() + 2);
                        computer1.SetBasketCherries(computer1.GetBasketCherries() - 2);
                    } else if (computer1.GetBasketCherries() == 1) {
                        computer1.SetTreeCherries(computer1.GetTreeCherries() + 1);
                        computer1.SetBasketCherries(computer1.GetBasketCherries() - 1);
                    }
                    break;
                case 6:
                    cout << "Bird" << endl;
                    if (computer1.GetBasketCherries() >= 2) {
                        computer1.SetTreeCherries(computer1.GetTreeCherries() + 2);
                        computer1.SetBasketCherries(computer1.GetBasketCherries() - 2);
                    } else if (computer1.GetBasketCherries() == 1) {
                        computer1.SetTreeCherries(computer1.GetTreeCherries() + 1);
                        computer1.SetBasketCherries(computer1.GetBasketCherries() - 1);
                    }
                    break;
                case 7:
                    cout << "Spilled Basket" << endl;
                    computer1.SetTreeCherries(start_cherries);
                    computer1.SetBasketCherries(0);
                    break;
            }
        }
        turn++;  //increments turn by one so that the players alternate
    }
    
    if (player_tree_cherries <= 0) { //prints the winner and says good game
        cout << "Good Game! You Won!" << endl;
    } else {
        cout << "The Computer Won. Good Game!" << endl;
    }
    
    
    return 0;
}

/*

Let's play Hi Ho! Cherry-O.
You each have 5 cherries on your tree.
Take turns spinning. Whoever removes all the cherries from their tree first wins.
It's your turn!
Press 'S' to spin!
D
Error: enter 'S' to spin.
D
Error: enter 'S' to spin.
S
Take 4 Cherries
Dog
It's the computer's turn!
Take 4 Cherries
It's your turn!
Press 'S' to spin!
s
Take 2 Cherries
It's the computer's turn!
Bird
It's your turn!
Press 'S' to spin!
S
Take 2 Cherries
Good Game! You Won!

Let's play Hi Ho! Cherry-O.
You each have 9 cherries on your tree.
Take turns spinning. Whoever removes all the cherries from their tree first wins.
It's your turn!
Press 'S' to spin!
s
Bird
It's the computer's turn!
Spilled Basket
It's your turn!
Press 'S' to spin!
s
Take 4 Cherries
Dog
It's the computer's turn!
Take 2 Cherries
It's your turn!
Press 'S' to spin!
s
Dog
It's the computer's turn!
Take 1 Cherry
It's your turn!
Press 'S' to spin!
s
Dog
It's the computer's turn!
Take 3 Cherries
It's your turn!
Press 'S' to spin!
s
Take 1 Cherry
It's the computer's turn!
Spilled Basket
It's your turn!
Press 'S' to spin!
s
Take 1 Cherry
It's the computer's turn!
Take 1 Cherry
It's your turn!
Press 'S' to spin!
s
Bird
It's the computer's turn!
Spilled Basket
It's your turn!
Press 'S' to spin!
s
Spilled Basket
It's the computer's turn!
Take 4 Cherries
It's your turn!
Press 'S' to spin!
s
Take 4 Cherries
Dog
It's the computer's turn!
Take 1 Cherry
It's your turn!
Press 'S' to spin!
s
Take 4 Cherries
Dog
It's the computer's turn!
Dog
It's your turn!
Press 'S' to spin!
s
Dog
It's the computer's turn!
Dog
It's your turn!
Press 'S' to spin!
s
Take 3 Cherries
It's the computer's turn!
Bird
It's your turn!
Press 'S' to spin!
s
Dog
It's the computer's turn!
Take 1 Cherry
It's your turn!
Press 'S' to spin!
s
Bird
It's the computer's turn!
Take 2 Cherries
It's your turn!
Press 'S' to spin!
s
Take 1 Cherry
It's the computer's turn!
Take 1 Cherry
It's your turn!
Press 'S' to spin!
S
Spilled Basket
It's the computer's turn!
Bird
It's your turn!
Press 'S' to spin!
s
Take 1 Cherry
It's the computer's turn!
Take 1 Cherry
It's your turn!
Press 'S' to spin!
s
Take 1 Cherry
It's the computer's turn!
Take 3 Cherries
It's your turn!
Press 'S' to spin!
s
Take 2 Cherries
It's the computer's turn!
Take 3 Cherries
The Computer Won. Good Game!

*/