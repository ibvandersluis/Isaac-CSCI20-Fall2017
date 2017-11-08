//Created By: Isaac Vander Sluis
//Created On: 11/2/17

/*
    ~~~~~~~~~SHOPPING CART 0~~~~~~~~~
    This program replicates (in a very simple, simple way) the online shopping
    experience at a computer hardware and accessories website. Parallel arrays
    are used to keep track of the items, price, and quantity that are in the
    store's inventory, and another set of parallel arrays are used to keep track
    of each item that the user adds to their cart. Loops are used to keep asking
    the user to add items to their cart until they elect to check out. After
    they are done shopping, their cart is printed out in an itemizes list,
    showing individual prices followed by the total.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    const int NUM_PRODUCTS = 10;                        //These variable initialize the inventory of the store
    string products[NUM_PRODUCTS];
    double prices[NUM_PRODUCTS];
    int quantity[NUM_PRODUCTS];
    
    string cart_products[NUM_PRODUCTS * 20];            //These variable initialize the shopping cart
    double cart_prices[NUM_PRODUCTS * 20];
    int cart_count = 0;
    
    char keep_shopping = 'Y';                           //Initializes a variable that allows the user to keep shopping
    int user_command   = 0;                             //Initializes a variable for the user to prompt outcomes
    
    products[0] = " Mouse        ";     prices[0] = 14.99;     quantity[0] = 50;        //These variables initialize the inventory arrays
    products[1] = " Keyboard     ";     prices[1] = 39.99;     quantity[1] = 45;
    products[2] = " Case         ";     prices[2] = 74.99;     quantity[2] = 35;
    products[3] = " Motherboard  ";     prices[3] = 94.99;     quantity[3] = 30;
    products[4] = " Processor    ";     prices[4] = 99.99;     quantity[4] = 45;
    products[5] = " Graphics Card";     prices[5] = 94.99;     quantity[5] = 40;
    products[6] = " Memory       ";     prices[6] = 89.99;     quantity[6] = 60;
    products[7] = " Power Supply ";     prices[7] = 69.99;     quantity[7] = 40;
    products[8] = " Hard Drive   ";     prices[8] = 64.99;     quantity[8] = 30;
    products[9] = "Monitor      ";      prices[9] = 99.99;     quantity[9] = 15;
    
    
    
    while ((keep_shopping == 'Y') || (keep_shopping == 'y')) {
        for (int i = 0; i < NUM_PRODUCTS; i++) {        //Prints the inventory to the user
            cout << i+1 << ". " << products[i] << "         $" << prices[i] << "        x " << quantity[i] << endl;
        }
        
        cout << endl << endl << "Enter an item number to add to cart, or '0' to check out:" << endl;
        cin >> user_command;    //Prompts user for input
        
        int i = user_command - 1;
        
        if (user_command == 0) {    //Searches for user's desire to check out
            keep_shopping = 'N';
        } else {
            if (quantity[i] > 0) {      //Adds item to cart
                quantity[i] = quantity[i] - 1;
                cart_products[cart_count] = products[i];
                cart_prices[cart_count] = prices[i];
                cart_count++;
                
                cout << products[i] << " was added to your cart." << endl;
            } else {
                cout << "ERROR: Out of Stock" << endl;
            }
            
            cout << "Keep shopping? (Y/N)" << endl;
            cin >> keep_shopping;
        }
    }
    
    cout << "Your shopping cart: " << endl << endl;
    
    double total = 0.00;
    for (int i = 0; i < cart_count; i++) {  //Prints shopping cart
        if (cart_prices[i] > 0.0001) {
            cout << cart_products[i] << "         $" << cart_prices[i] << endl;
            total += cart_prices[i];
        }
    }
    
    cout << endl << endl << "TOTAL: $" << total;    //prints total
    
    return 0;
}

/*

    1.  Mouse                 $14.99        x 50
    2.  Keyboard              $39.99        x 45
    3.  Case                  $74.99        x 35
    4.  Motherboard           $94.99        x 30
    5.  Processor             $99.99        x 45
    6.  Graphics Card         $94.99        x 40
    7.  Memory                $89.99        x 60
    8.  Power Supply          $69.99        x 40
    9.  Hard Drive            $64.99        x 30
    10. Monitor               $99.99        x 15
    
    
    Enter an item number to add to cart, or '0' to check out:
    5
     Processor     was added to your cart.
    Keep shopping? (Y/N)
    y
    1.  Mouse                 $14.99        x 50
    2.  Keyboard              $39.99        x 45
    3.  Case                  $74.99        x 35
    4.  Motherboard           $94.99        x 30
    5.  Processor             $99.99        x 44
    6.  Graphics Card         $94.99        x 40
    7.  Memory                $89.99        x 60
    8.  Power Supply          $69.99        x 40
    9.  Hard Drive            $64.99        x 30
    10. Monitor               $99.99        x 15
    
    
    Enter an item number to add to cart, or '0' to check out:
    8
     Power Supply  was added to your cart.
    Keep shopping? (Y/N)
    y
    1.  Mouse                 $14.99        x 50
    2.  Keyboard              $39.99        x 45
    3.  Case                  $74.99        x 35
    4.  Motherboard           $94.99        x 30
    5.  Processor             $99.99        x 44
    6.  Graphics Card         $94.99        x 40
    7.  Memory                $89.99        x 60
    8.  Power Supply          $69.99        x 39
    9.  Hard Drive            $64.99        x 30
    10. Monitor               $99.99        x 15
    
    
    Enter an item number to add to cart, or '0' to check out:
    2
     Keyboard      was added to your cart.
    Keep shopping? (Y/N)
    y
    1.  Mouse                 $14.99        x 50
    2.  Keyboard              $39.99        x 44
    3.  Case                  $74.99        x 35
    4.  Motherboard           $94.99        x 30
    5.  Processor             $99.99        x 44
    6.  Graphics Card         $94.99        x 40
    7.  Memory                $89.99        x 60
    8.  Power Supply          $69.99        x 39
    9.  Hard Drive            $64.99        x 30
    10. Monitor               $99.99        x 15
    
    
    Enter an item number to add to cart, or '0' to check out:
    1
     Mouse         was added to your cart.
    Keep shopping? (Y/N)
    n
    Your shopping cart: 
    
     Processor             $99.99
     Power Supply          $69.99
     Keyboard              $39.99
     Mouse                 $14.99
    
    
    TOTAL: $224.96

*/