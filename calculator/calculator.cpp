//Created By: Isaac Vander Sluis
//Created On: 8/29/17

/*  This program is designed to generate an employee's weekly pay stub
    given certain variables:
        - employee name
        - hourly pay
        - hours worked
        - miles traveled
        - insurance cost
    Using this information, the program will deduct wages for health
    insurance, apply taxes at 17%, reimburse the employee for miles traveled,
    and output a pay stub.
*/

#include <iostream>
#include <string>
using namespace std;

struct Employee {          //Stores data unique to each employee
    string name;
    int hours_worked;
    double hourly_pay;
    double insurance_cost;
    int start_odometer;
    int end_odometer;
};

int main() {
    Employee employee1;
    
    cout << "Enter the employee's first and last name: " << endl;  //Gets employee info from user
    getline(cin, employee1.name);
    cout << "Enter the number of hours " << employee1.name << " worked this week: " << endl;
    cin >> employee1.hours_worked;
    cout << "Enter " << employee1.name <<"'s hourly wage: " << endl;
    cin >> employee1.hourly_pay;
    cout << "Enter " << employee1.name << "'s cost of insurance: " << endl;
    cin >> employee1.insurance_cost;
    cout << "Enter " << employee1.name << "'s starting odometer: " << endl;
    cin >> employee1.start_odometer;
    cout << "Enter " << employee1.name << "'s ending odometer: " << endl;
    cin >> employee1.end_odometer;
    
    const double TAX_PERCENTAGE = 0.17;            //These variables are constant
    const double MILES_RATE = 0.35;
    
    double gross_pay = employee1.hourly_pay * employee1.hours_worked;   //Equations for determining variable for output: reimbursement, gross pay, net pay, and total pay
    double tax_deduction = (gross_pay - employee1.insurance_cost) * TAX_PERCENTAGE;
    double net_pay = gross_pay - employee1.insurance_cost - tax_deduction;
    int miles_traveled = employee1.end_odometer - employee1.start_odometer;
    double travel_reimbursement = miles_traveled * MILES_RATE;
    double total_pay = net_pay + travel_reimbursement;
    
    cout << endl << endl << endl << "~~~~~~~WEEKLY PAY STUB~~~~~~~" << endl; //The pay stup is outputted to the user
    cout << "EMPLOYEE: " << employee1.name << endl;
    cout << "HOURS WORKED: " << employee1.hours_worked << endl;
    cout << "HOURLY WAGE: $" << employee1.hourly_pay << endl;
    cout << "GROSS PAY: $" << gross_pay << endl;
    cout << "TAXES PAID: $" << tax_deduction << endl;
    cout << "INSURANCE PAID: $" << employee1.insurance_cost << endl;
    cout << "NET PAY: $" << net_pay << endl;
    cout << "REIMBURSEMENT: $" << travel_reimbursement << endl;
    cout << "***********************" << endl;
    cout << "TOTAL PAY: $" << total_pay << endl;
    
    return 0;
}

/* ~~~~~~~WEEKLY PAY STUB~~~~~~~
   EMPLOYEE: Sofia Cameron
   HOURS WORKED: 40
   HOURLY WAGE: $23.57
   GROSS PAY: $942.8
   TAXES PAID: $129.906
   INSURANCE PAID: $178.65
   NET PAY: $634.245
   REIMBURSEMENT: $310.1
   ***********************
   TOTAL PAY: $944.344
   
   ~~~~~~~WEEKLY PAY STUB~~~~~~~
   EMPLOYEE: Richard Watson
   HOURS WORKED: 29
   HOURLY WAGE: $11.5
   GROSS PAY: $333.5
   TAXES PAID: $-1.8819
   INSURANCE PAID: $344.57
   NET PAY: $-9.1881
   REIMBURSEMENT: $328.3
   ***********************
   TOTAL PAY: $319.112
   
   ~~~~~~~WEEKLY PAY STUB~~~~~~~
   EMPLOYEE: Heather Hunt
   HOURS WORKED: 35
   HOURLY WAGE: $60
   GROSS PAY: $2100
   TAXES PAID: $318.793
   INSURANCE PAID: $224.75
   NET PAY: $1556.46
   REIMBURSEMENT: $0
   ***********************
   TOTAL PAY: $1556.46
   
   ~~~~~~~WEEKLY PAY STUB~~~~~~~
   EMPLOYEE: Eddy Hall
   HOURS WORKED: 40
   HOURLY WAGE: $8.25
   GROSS PAY: $330
   TAXES PAID: $25.4541
   INSURANCE PAID: $180.27
   NET PAY: $124.276
   REIMBURSEMENT: $79.45
   ***********************
   TOTAL PAY: $203.726
*/