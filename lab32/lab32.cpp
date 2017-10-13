//Created By: Isaac Vander Sluis
//Created On: 10/12/17

/* ~~~~~TAX CALCULATOR~~~~~
   This program takes the user's name, filing status, gross income, and
   tax withheld. Using this information, the program determines how much they
   owe in taxes, and if they are entitled to a refund or will need to pay.
   This information is printed to the user.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Purpose: uses if-else/switch case logic to determine the formula for
   calculating taxes.
   Input: this program takes two arguments- the filing status as type char,
   and the gross income as type int.
   Output: this program returns taxes owed, not accounting for taxes withheld.
*/
double CalculateTaxes(char status, int gross) {
    double tax_due = 0;
    switch (status) {
        case 's':                                                  //If single...
        case 'S':
            if (gross <= 9325) {
                tax_due = 0.10 * gross;
            } else if (gross <= 37950) {
                tax_due = 932.50 + (0.15 * (gross - 9325));
            } else if (gross <= 91900) {
                tax_due = 5226.25 + (0.25 * (gross - 37950));
            } else if (gross <= 191650) {
                tax_due = 18713.75 + (0.28 * (gross - 91900));
            } else if (gross <= 416700) {
                tax_due = 46643 + (0.33 * (gross - 191650));
            } else {
                tax_due = 120910.25 + (0.396 * (gross - 416700));
            }
            break;
        case 'm':                                                   //If married...
        case 'M':
            if (gross <= 18650) {
                tax_due = 0.10 * gross;
            } else if (gross <= 75900) {
                tax_due = 1865 + (0.15 * (gross - 18650));
            } else if (gross <= 153100) {
                tax_due = 10452.50 + (0.25 * (gross - 75900));
            } else if (gross <= 233350) {
                tax_due = 29752.50 + (0.28 * (gross - 153100));
            } else if (gross <= 416700) {
                tax_due = 52222.50 + (0.33 * (gross - 233350));
            } else {
                tax_due = 112728 + (0.396 * (gross - 470700));
            }
            break;
            
        default:
            cout << "ERROR: Invalid Filing Status" << endl;         //Error message if the filing status is something other than an S or an M
    }
    
    return tax_due;
}

int main() {
    string user_name = " ";                                         //initializing variables for user input
    int gross_income = 0;
    int tax_withheld = 0;
    char filing_status = ' ';
    
    cout << "Enter name: " << endl;                                 //Gets info from user
    getline(cin, user_name);
    cout << "Enter filing status ('S' for Single, 'M' for Married): " << endl;
    cin >> filing_status;
    cout << "Enter gross income: " << endl;
    cin >> gross_income;
    cout << "Enter taxes withheld: " << endl;
    cin >> tax_withheld;
    
    double tax_owed = CalculateTaxes(filing_status, gross_income);  //Stores the result of calling CalculateTaxes() on the filing status and gross income
    
    if (fabs(tax_owed - tax_withheld) < 0.0001) {                   //Determines if taxes due and taxes withheld are equal and prints results if true
        cout << "Name: " << user_name << endl;
        cout << "Total Gross Adjusted Income: $" << gross_income << endl;
        cout << "Total tax owed: None" << endl;
        cout << "Your taxes withheld are equal to your taxes owed." << endl;
    } else if (tax_owed > tax_withheld) {                           //Determines if user owes taxes and prints the result if true
        cout << "Name: " << user_name << endl;
        cout << "Total Gross Adjusted Income: $" << gross_income << endl;
        cout << "Total tax owed: $" << tax_owed << endl;
        cout << user_name << " owes the sum of $" << tax_owed << " dollars to the United States Government." << endl;
    } else {                                                        //Determines if user is entitled to refund and prints result if true
        cout << "Name: " << user_name << endl;
        cout << "Total Gross Adjusted Income: $" << gross_income << endl;
        cout << "Total tax owed: None" << endl;
        cout << user_name << " is entitled to a REFUND of $" << (tax_withheld - tax_owed) << " dollars." << endl;
    }
    
    return 0;
}

/*

Enter name: 
Joe Vandal
Enter filing status ('S' for Single, 'M' for Married): 
s
Enter gross income: 
12100
Enter taxes withheld: 
250
Name: Joe Vandal
Total Gross Adjusted Income: $12100
Total tax owed: $1348.75
Joe Vandal owes the sum of $1348.75 dollars to the United States Government.

Enter name: 
Alfonso Haynes
Enter filing status ('S' for Single, 'M' for Married): 
m
Enter gross income: 
32351
Enter taxes withheld: 
3192
Name: Alfonso Haynes
Total Gross Adjusted Income: $32351
Total tax owed: $3920.15
Alfonso Haynes owes the sum of $3920.15 dollars to the United States Government.

Enter name: 
Bridget Rowe
Enter filing status ('S' for Single, 'M' for Married): 
s
Enter gross income: 
88229
Enter taxes withheld: 
12057
Name: Bridget Rowe
Total Gross Adjusted Income: $88229
Total tax owed: $17796
Bridget Rowe owes the sum of $17796 dollars to the United States Government.

Enter name: 
Wendy Joseph
Enter filing status ('S' for Single, 'M' for Married): 
M
Enter gross income: 
73291
Enter taxes withheld: 
6972
Name: Wendy Joseph
Total Gross Adjusted Income: $73291
Total tax owed: $10061.1
Wendy Joseph owes the sum of $10061.1 dollars to the United States Government.

*/