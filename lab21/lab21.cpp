//Created By: Isaac Vander Sluis
//Created On: 9/19/17

/* ~~~~CALLING FUNCTIONS~~~~
   This program takes temperature and wind speed values from the user and
   calculates windchill based on old and new formulas. The programs prints
   this information to the user in a table, along with the difference between
   the two results.
*/

#include <iostream>
#include <cmath>  //Includes math library for using pow and sqrt functions
using namespace std;

int main() {
    double temp = 0;  //Initializes variables to 0
    double wind_speed = 0;
    
    cout << "Enter the temperature: " << endl; //Gets data from user
    cin >> temp;
    cout << "Enter the wind speed: " << endl;
    cin >> wind_speed;
    
    double old_windchill = 0.081 * (3.71 * sqrt(wind_speed) + 5.81 - 0.25 * wind_speed) * (temp - 91.4) + 91.4; //Old formula for windchill
    double new_windchill = 35.74 + 0.6215 * temp - 35.75 * pow(wind_speed, 0.16) + 0.4275 * temp * pow(wind_speed, 0.16); //New formula for windchill
    double windchill_difference = old_windchill - new_windchill;
    
    cout << endl << endl;
    cout << "   TEMP   |  WIND SPEED  |   OLD WINDCHILL   |   NEW WINDCHILL   |   DIFFERENCE" << endl;
    cout << "__________|______________|___________________|___________________|________________" << endl;
    cout << "    " << temp << "           " << wind_speed << "             " << old_windchill << "               " << new_windchill << "            " << windchill_difference << endl;
    
    return 0;
}

/*
      TEMP   |  WIND SPEED  |   OLD WINDCHILL   |   NEW WINDCHILL   |   DIFFERENCE
   __________|______________|___________________|___________________|________________
       30           4             30.5753               25.767            4.8083
       
       
      TEMP   |  WIND SPEED  |   OLD WINDCHILL   |   NEW WINDCHILL   |   DIFFERENCE
   __________|______________|___________________|___________________|________________
       39.25           10             27.8601               32.713            -4.85286


      TEMP   |  WIND SPEED  |   OLD WINDCHILL   |   NEW WINDCHILL   |   DIFFERENCE
   __________|______________|___________________|___________________|________________
       100           2             98.7538               105.711            -6.95719
*/