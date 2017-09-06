//Created By: Isaac Vander Sluis
//Created On: 9/5/17

/*  ~~~~CointStar Emulator~~~~
    This program receives the number of cents inserted into the machine,
    determines the denominations (assuming the most efficient distribution),
    and returns a cash voucher after taking a 10.9% fee.
*/

#include <iostream>
using namespace std;

int main()
{
    int input_cents = 0;
    int num_quarters = 0;
    int num_dimes = 0;
    int num_nickels = 0;
    int num_pennies = 0;
    
    cout << "Enter total value of coins, in cents: " << endl;
    cin >> input_cents;
    
    double service_fee = input_cents * (0.109);
    int voucher = input_cents - service_fee;
    
    num_quarters = input_cents / 25;
    num_dimes = (input_cents - (num_quarters * 25)) / 10;
    num_nickels = (input_cents - (num_quarters * 25) - (num_dimes * 10)) / 5;
    num_pennies = input_cents % 5;
    
    cout << "You have entered " << input_cents << " cents." << endl;
    cout << "That is, " << num_quarters << " quarters, " << num_dimes << " dimes, " << num_nickels << " nickels, and " << num_pennies << " pennies." << endl;
    cout << "The total is $" << input_cents / 100.0 << ". After the fee you get $" << voucher / 100.0 << "." << endl;
    
    return 0;
}