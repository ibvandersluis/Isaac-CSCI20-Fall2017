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
    string employeeName = "";      //These variables are flexible and will be
    int hourlyPay = 0;          //given values by the user.
    int hoursWorked = 0;
    int insuranceCost = 0;
    int startOdometer = 0;
    int endOdometer = 0;
    
    int taxPercent = 17;        //These variables are constant.
    int milesRate = 0.35;
    int netPay = hourlyPay * hoursWorked;
    int milesTraveled = endOdometer - startOdometer;
    int travelReimbursement = milesTraveled * milesRate;
}