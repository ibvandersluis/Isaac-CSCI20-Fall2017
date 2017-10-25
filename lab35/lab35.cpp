//Created By: Isaac Vander Sluis
//Created On: 10/24/17

/*

~~~~~~~TEMP CONVERTER~~~~~~~
This program defines a class TemperatureConverter, which takes a double and
makes that input accessable in Kelvin, Fahrenheit, and Celsius. Rankine gets
left out.

By default, the temperature is set to 0 deg Kelvin, but the user can initialize
it to any value that is equal to or above Absolute Zero (0 deg K).

The class includes getters and setters to assisgn and retrieve the temperature
both to and from either of the three temperature scales. A print function prints
the stored temperature in all three scales.

*/

#include <iostream>
using namespace std;

class TemperatureConverter {
    public:
        TemperatureConverter();                              //Constructor
        TemperatureConverter(double deg_kelvin);             //Overload constructor
        
        void SetTempFromKelvin(double deg_kelvin);           //Mutator
        void SetTempFromCelsius(double deg_celsius);         //Mutator
        void SetTempFromFahrenheit(double deg_fahrenheit);   //Mutator
        
        double GetTempFromKelvin() const;                    //Accessor
        double GetTempAsCelsius() const;                     //Accessor
        double GetTempAsFahrenheit() const;                  //Accessor
        
        void PrintTemperatures();                            //Print function
    private:
        double kelvin_;                                      //Class variable
};

//This is the constructor. It initializes all instances of TemperatureConverter to kelvin_ = 0 by default.
TemperatureConverter::TemperatureConverter() {
    kelvin_ = 0;
    
    return;
}

//This overload constructor allows the user to specify the starting value of kelvin_ so long as it is non negative.
TemperatureConverter::TemperatureConverter(double deg_kelvin) {
    if (deg_kelvin >= 0) {
        kelvin_ = deg_kelvin;
    }
    
    return;
}

//This mutator sets the value of kelvin_ from a kelvin input
void TemperatureConverter::SetTempFromKelvin(double deg_kelvin) {
    if (deg_kelvin >= 0) {
        kelvin_ = deg_kelvin;
    }
    
    return;
}

//This mutator sets the value of kelvin_ from a celsius input
void TemperatureConverter::SetTempFromCelsius(double deg_celsius) {
    if (deg_celsius >= -273.15) {
        kelvin_ = deg_celsius + 273.15;
    }
    
    return;
}

//This mutator sets the value of kelvin_ from a fahrenheit input
void TemperatureConverter::SetTempFromFahrenheit(double deg_fahrenheit) {
    if (deg_fahrenheit >= -459.67) {
        kelvin_ = 5 * ((deg_fahrenheit - 32.0)/9.0) + 273.15;
    }
    
    return;
}

//This accessor returns the temperature in kelvin
double TemperatureConverter::GetTempFromKelvin() const {
    return kelvin_;
}

//This accessor returns the temperature in celsius
double TemperatureConverter::GetTempAsCelsius() const {
    return kelvin_ - 273.15;
}

//This accessor returns the temperature in fahrenheit
double TemperatureConverter::GetTempAsFahrenheit() const {
    return (9 * GetTempAsCelsius()) / 5 + 32;
}

void TemperatureConverter::PrintTemperatures() {
    cout << "The temperature in Kelvin is: " << GetTempFromKelvin() << endl;
    cout << "The temperature in Celsius is: " << GetTempAsCelsius() << endl;
    cout << "The temperature in Fehrenheit is: " << GetTempAsFahrenheit() << endl;
    
    return;
}

int main () {
    TemperatureConverter temp1; //testing default constructor
    TemperatureConverter temp2(274); //testing overloaded constructor
    
    temp1.PrintTemperatures();
    temp2.PrintTemperatures();
    
    temp1.SetTempFromKelvin(400.15); //testing mutator function
    cout<<temp1.GetTempFromKelvin()<<endl;//testing accessor function
    temp1.PrintTemperatures();
    
    temp2.SetTempFromCelsius(32); //testing other functions
    cout<<temp2.GetTempAsCelsius()<<endl;
    temp2.PrintTemperatures();
    
    temp2.SetTempFromFahrenheit(32);
    cout<<temp2.GetTempAsFahrenheit()<<endl;
    temp2.PrintTemperatures();
    
    return 0;
}

/*

The temperature in Kelvin is: 0
The temperature in Celsius is: -273.15
The temperature in Fehrenheit is: -459.67
The temperature in Kelvin is: 274
The temperature in Celsius is: 0.85
The temperature in Fehrenheit is: 33.53
400.15
The temperature in Kelvin is: 400.15
The temperature in Celsius is: 127
The temperature in Fehrenheit is: 260.6
32
The temperature in Kelvin is: 305.15
The temperature in Celsius is: 32
The temperature in Fehrenheit is: 89.6
32
The temperature in Kelvin is: 273.15
The temperature in Celsius is: 0
The temperature in Fehrenheit is: 32

*/