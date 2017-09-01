//Created By: Isaac Vander Sluis
//Created On: 8/31/17

/*  ~~~~ US POPULATION CALCULATOR ~~~~
    Purpose: Program estimates what the population of the US will be in
    x number of years, determined by the user. All math is done within the
    program. After computing the future population, the program prints to
    the user what the population will be in the year specified.
*/

#include <iostream>
using namespace std;

int main()
{
    int seconds_in_minute = 60; //Time measurements
    int minutes_in_hour = 60;
    int hours_in_day = 24;
    int days_in_year = 365;
    int seconds_in_year = seconds_in_minute * minutes_in_hour * hours_in_day * days_in_year;

    int birth_rate = 8;         //Averaging one birth every 8 seconds
    int death_rate = 12;        //Averaging one death every 12 seconds
    int migration_rate = 33;    //Averaging one migrant ever 33 seconds
    
    int births_per_year = seconds_in_year / birth_rate;
    int deaths_per_year = seconds_in_year / death_rate;
    int migrants_per_year = seconds_in_year / migration_rate;
    
    int current_population = 325778982;
    int years_from_now = 0;
    
    cout << "How many years from now do you want to know the US population?" << endl;
    cin >> years_from_now;
    
    int gross_population_gain = (births_per_year * years_from_now) + (migrants_per_year * years_from_now);
    int gross_population_loss = deaths_per_year * years_from_now;
    int projected_population = current_population + gross_population_gain - gross_population_loss;
    int projection_year = 2017 + years_from_now;
    
    cout << "In " << projection_year << " the population of the United States will be roughly " << projected_population << ".";
    
    return 0;
}