//Created By: Isaac Vander Sluis
//Created On: 9/7/17

/*  ~~~~MAD LIBS~~~~
    This program has a pre-determined 'mad libs' template. The passage
    is from The Martian; words have been deleted from it, and the user
    will input their own words to fill those places. The result will be
    similar to the original passage, but with nonsensical insertions from
    an oblivious user.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string element = "potassium";               //initializing my string variabls to values
    string present_verb = "popping";            //I got from my girlfriend when I tested it on her
    string natural_disaster = "tsunami";
    string noun = "peacock";
    string adverb = "awkwardly";
    
    cout << "Enter an element: " << endl;       //getting string values from the user
    getline(cin, element);
    cout << "Enter a verb in the present tense: " << endl;
    getline(cin, present_verb);
    cout << "Enter a natural disaster or intense weather condition: " << endl;
    getline(cin, natural_disaster);
    cout << "Enter a noun: " << endl;
    getline(cin, noun);
    cout << "Enter an adverb: " << endl;
    getline(cin, adverb);
                                                //outputting the Mad Lib with variables replacing missing words
    cout << "I awoke to the " << element << " alarm in my suit. A steady, obnoxious " << present_verb << endl;
    cout << "that eventually roused me from a deep and profound desire to just " << endl;
    cout << "fucking die. The " << natural_disaster << " had abated. I was facedown, almost totally buried " << endl;
    cout << "in " << noun << ". As I " << adverb << " came to, I wondered why I wasn’t more dead." << endl;
    
    /*  Enter an element: 
        potassium
        Enter a verb in the present tense: 
        popping
        Enter a natural disaster or intense weather condition: 
        tsunami
        Enter a noun: 
        peacock
        Enter an adverb: 
        awkwardly
        I awoke to the potassium alarm in my suit. A steady, obnoxious popping
        that eventually roused me from a deep and profound desire to just 
        fucking die. The tsunami had abated. I was facedown, almost totally buried 
        in peacock. As I awkwardly came to, I wondered why I wasn’t more dead.
    */
    
    return 0;
}