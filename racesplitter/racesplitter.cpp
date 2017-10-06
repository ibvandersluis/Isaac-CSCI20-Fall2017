//Created By: Isaac Vander Sluis
//Created On: 10/5/17

/* ~~~~~~~~~RACESPLITTER~~~~~~~~~~
   This program takes a runner's time for a 1 mile race from the user,
   determines the runner's velocity in feet/second and meters/second,
   calculates how long their average 1/4 mile split was, and outputs
   the results along with a comparison to the stats for the race winner.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Runner {
    public:
        void SetSeconds(int minutes, int seconds);  //mutator
        void SetFPS(int seconds);                   //mutator
        void SetMPS(int seconds);                   //mutator
        void SetLap();                              //mutator
        
        int GetSeconds() const;                     //accessor
        double GetFPS() const;                      //accessor
        double GetMPS() const;                      //accessor
        double GetLap() const;                      //accessor
    private:
        double secs_;                               //private class variables
        double fps_;
        double mps_;
        double lap_;
};

//declaring all class functions
void Runner::SetSeconds(int minutes, int seconds) {
    secs_ = (minutes * 60.0) + seconds;
}

void Runner::SetFPS(int seconds) {
    fps_ = 5280.0 / GetSeconds();
}

void Runner::SetMPS(int seconds) {
    mps_ = 1600.0 / GetSeconds();
}

void Runner::SetLap() {
    lap_ = GetSeconds() / 4.0;
}

int Runner::GetSeconds() const {
    return secs_;
}

double Runner::GetFPS() const {
    return fps_;
}

double Runner::GetMPS() const {
    return mps_;
}

double Runner::GetLap() const {
    return lap_;
}

int main() {
    Runner runner1;                                 //declaring object of type Runner
    int user_mins = 0;                              //initializing uner input variables
    int user_secs = 0;
    double first_place_time = 253.0;                //defining winner's race time in seconds
    double first_fps = 5280.0 / first_place_time;   //calculating winner's pace in ft/s
    double first_mps = 1600.0 / first_place_time;   //calculating winner's pace in m/s
    double first_lap = first_place_time / 4;        //calculating winner's avg lap time in seconds
    
    cout << "Enter your race time." << endl;        //getting runner info from user
    cout << "Minutes: " << endl;
    cin >> user_mins;
    cout << "Seconds: " << endl;
    cin >> user_secs;
    
    runner1.SetSeconds(user_mins, user_secs);       //using all mutators to assign values to class variables
    runner1.SetFPS(runner1.GetSeconds());
    runner1.SetMPS(runner1.GetSeconds());
    runner1.SetLap();
    
    cout << endl;                                   //outputting results to user
    cout << "You ran at a velocity of " << runner1.GetFPS() << " feet/second, ";
    cout << "or " << runner1.GetMPS() << " meters/second." << endl;
    cout << "The race champion ran at " << first_fps << " feet/second, ";\
    cout << "or " << first_mps << " meters/second." << endl;
    cout << "Your 1/4 mile lap time was " << runner1.GetLap() << " seconds, compared with";
    cout << " the champions lap time of " << first_lap << " seconds." << endl;
    
    return 0;
}

/*
Enter your race time.
Minutes: 
8
Seconds: 
58

You ran at a velocity of 9.81413 feet/second, or 2.97398 meters/second.
The race champion ran at 20.8696 feet/second, or 6.32411 meters/second.
Your 1/4 mile lap time was 134.5 seconds, compared with the champions lap time of 63.25 seconds.


Enter your race time.
Minutes: 
27
Seconds: 
15

You ran at a velocity of 3.22936 feet/second, or 0.978593 meters/second.
The race champion ran at 20.8696 feet/second, or 6.32411 meters/second.
Your 1/4 mile lap time was 408.75 seconds, compared with the champions lap time of 63.25 seconds.


Enter your race time.
Minutes: 
57
Seconds: 
22

You ran at a velocity of 1.53399 feet/second, or 0.464846 meters/second.
The race champion ran at 20.8696 feet/second, or 6.32411 meters/second.
Your 1/4 mile lap time was 860.5 seconds, compared with the champions lap time of 63.25 seconds.


Enter your race time.
Minutes: 
3
Seconds: 
47

You ran at a velocity of 23.2599 feet/second, or 7.04846 meters/second.
The race champion ran at 20.8696 feet/second, or 6.32411 meters/second.
Your 1/4 mile lap time was 56.75 seconds, compared with the champions lap time of 63.25 seconds.


Enter your race time.
Minutes: 
11
Seconds: 
3

You ran at a velocity of 7.9638 feet/second, or 2.41327 meters/second.
The race champion ran at 20.8696 feet/second, or 6.32411 meters/second.
Your 1/4 mile lap time was 165.75 seconds, compared with the champions lap time of 63.25 seconds.


Enter your race time.
Minutes: 
36
Seconds: 
30

You ran at a velocity of 2.41096 feet/second, or 0.730594 meters/second.
The race champion ran at 20.8696 feet/second, or 6.32411 meters/second.
Your 1/4 mile lap time was 547.5 seconds, compared with the champions lap time of 63.25 seconds.


Enter your race time.
Minutes: 
40
Seconds: 
8

You ran at a velocity of 2.19269 feet/second, or 0.664452 meters/second.
The race champion ran at 20.8696 feet/second, or 6.32411 meters/second.
Your 1/4 mile lap time was 602 seconds, compared with the champions lap time of 63.25 seconds.


Enter your race time.
Minutes: 
7
Seconds: 
45

You ran at a velocity of 11.3548 feet/second, or 3.44086 meters/second.
The race champion ran at 20.8696 feet/second, or 6.32411 meters/second.
Your 1/4 mile lap time was 116.25 seconds, compared with the champions lap time of 63.25 seconds.


Enter your race time.
Minutes: 
21
Seconds: 
36

You ran at a velocity of 4.07407 feet/second, or 1.23457 meters/second.
The race champion ran at 20.8696 feet/second, or 6.32411 meters/second.
Your 1/4 mile lap time was 324 seconds, compared with the champions lap time of 63.25 seconds.


Enter your race time.
Minutes: 
60
Seconds: 
22

You ran at a velocity of 1.45776 feet/second, or 0.441745 meters/second.
The race champion ran at 20.8696 feet/second, or 6.32411 meters/second.
Your 1/4 mile lap time was 905.5 seconds, compared with the champions lap time of 63.25 seconds.
*/