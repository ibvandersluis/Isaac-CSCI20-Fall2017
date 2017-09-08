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

int main()
{
    string employee_name = "";                  //These variables are flexible and will be
    double hourly_pay = 0;                      //given values by the user.
    double hours_worked = 0;
    double insurance_cost = 0;
    double start_odometer = 0;
    double end_odometer = 0;
    double gross_wage = 0;
    
                                                //Getting info from user
    cout << "Enter the employee's first and last name: " << endl;
    getline(cin, employee_name);
    cout << "Enter " << employee_name <<"'s hourly wage: " << endl;
    cin >> hourly_pay;
    cout << "Enter the number of hours " << employee_name << " works in a week: " << endl;
    cin >> hours_worked;
    cout << "Enter " << employee_name << "'s cost of insurance: " << endl;
    cin >> insurance_cost;
    cout << "Enter " << employee_name << "'s starting odometer: " << endl;
    cin >> start_odometer;
    cout << "Enter " << employee_name << "'s ending odometer: " << endl;
    cin >> end_odometer;
    
    const double tax_percent = 0.17;            //These variables are constant, or based on constants
    const double miles_rate = 0.35;
    double net_pay = hourly_pay * hours_worked;
    double miles_traveled = end_odometer - start_odometer;
    double travel_reimbursement = miles_traveled * miles_rate;
    
    cout << endl << endl << endl << "~~~WEEKLY PAY STUB~~~" << endl;
    cout << "EMPLOYEE: " << employee_name << endl;
    cout << "NET PAY: $" << net_pay << endl;
    
    return 0;
}