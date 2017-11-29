//Created By: Isaac Vander Sluis
//Created On: 11/21/17

/*

~~~~~~TEST GRADER~~~~~~
This program imports a user-specified file to use as an answer key and stores
those answers in an array. The program then imports a file of student answers and
grades each test individually, outputting the overall score and list of missed
questions to the user as well as to an output file. The program closes both input
and output files before terminating.

*/

#include <iostream>
#include <ios>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
    ifstream input;                                     //initialize array for input from file
    ofstream output;                                    //initialize array for file output
    string answer_key[21];                              //initialize array to store answer key
    string test_answers[21];                            //initialize array to store student's answers
    int missed_qs[21];                                  //initialize array to store omitted or wrong answers
    string file_name = "";                              //initialize variable to store file name(s)
    string first_name = "";                             //initialize variable to store first name
    string last_name = "";                              //initialize variable to store last name
    double score = 0.0;                                 //initialize variable to track test score
    int j = 0;                                          //initialize variable to iterate through missed_qs[] array
    
    cout << fixed << setprecision(1);                   //limits number outputs to one decimal point in both output file and cout
    output << fixed << setprecision(1);
    
    cout << "Enter file for answer key: " << endl;      //prompts user for file to input
    cin >> file_name;
    
    input.open(file_name);                              //opens file
    if (!input.is_open()) {                             //prints error if file won't open
        cout << "Could not open file " << file_name << endl;
        return 1;
    }
    cout << "Opening " << file_name << endl;            //informs the user that it is opening the file
    
    for (int i = 0; i < 21; i++) {                      //copies answer key into array
        input >> answer_key[i];
    }
    
    cout << "Answer key imported from " << file_name << endl;
    cout << "Closing " << file_name << endl;            //informs user that answer key has been imported and it is closing the file
    input.close();                                      //closes file
    
    cout << "Enter file for student answers: " << endl; //prompts user for file with student scores to input
    cin >> file_name;
    
    input.open(file_name);                              //opens file for input
    output.open("student_scores.txt");                  //opens file for output
    if (!input.is_open()) {                             //prints error if file won't open
        cout << "Could not open file" << file_name << endl;
        return 1;
    }
    cout << "Opening " << file_name << endl;            //informs the user that it is opening the file
    
    while (!input.eof()) {                              //loop runs until end of file
        score = 0.0;                                    //resets score
        j = 0;                                          //resets missed_qs[] tracker
        input >> first_name;                            //gets first name
        input >> last_name;                             //gets last name
        for (int i = 0; i < 21; i++) {                  //copies student answers into answer array
            input >> test_answers[i];
            if (i + 1 == 19) {                          //special case for answering question 19 (allows for slight variation)
                if ((test_answers[i] == answer_key[i])||(test_answers[i] == "var")) {
                    score += 1.0;
                } else if (test_answers[i] == "?") {
                    score += 0.0;
                    missed_qs[j] = i + 1;
                    j++;
                } else {
                    score -= 0.25;
                    missed_qs[j] = i + 1;
                    j++;
                }
            } else if (i + 1 == 20) {                   //special case for answering question 20 (allows for slight variation)
                if ((test_answers[i] == answer_key[i])||(test_answers[i] == "rand()")) {
                    score += 1.0;
                } else if (test_answers[i] == "?") {
                    score += 0.0;
                    missed_qs[j] = i + 1;
                    j++;
                } else {
                    score -= 0.25;
                    missed_qs[j] = i + 1;
                    j++;
                }
            } else {                                    //question grading algorithm (as seen above)
                if (test_answers[i] == answer_key[i]) {
                    score += 1.0;                       //adds one point for right answers
                } else if (test_answers[i] == "?") {
                    score += 0.0;                       //adds nothing for omitted answers
                    missed_qs[j] = i + 1;               //adds question number to missed_qs[] array
                    j++;                                //increments missed_qs[] tracker
                } else {
                    score -= 0.25;                      //deducts one point for wrong answers
                    missed_qs[j] = i + 1;               //adds question number to missed_qs[] array
                    j++;                                //increments missed_qs[] tracker
                }
            }
        }
        output << "Student: " << first_name << " " << last_name << endl;                //prints student name to file
        output << "Missed Questions: ";                                                 //prints question numbers that were not correct
        for (int i = 0; i < j; i++) {
            output << missed_qs[i] << ", ";
        }
        output << endl << "Overall grade: " << (score / 21.0) * 100 << endl << endl;    //prints overall grade
        
        cout << endl << endl << "Student: " << first_name << " " << last_name << endl;  //prints student name to screen
        cout << "Missed Questions: ";                                                   //prints question numbers that were not correct
        for (int i = 0; i < j; i++) {
            cout << missed_qs[i] << ", ";
        }
        cout << endl << "Overall grade: " << (score / 21.0) * 100 << endl;              //prints overall grade
    }
    
    cout << endl << "Closing " << file_name << endl;                                    //informs user that it is closing the file
    input.close();                                                                      //closes input file
    output.close();                                                                     //closes output file
    
    return 0;
}

/*

Enter file for answer key: 
test_key.txt
Opening test_key.txt
Answer key imported from test_key.txt
Closing test_key.txt
Enter file for student answers: 
test_answers.txt
Opening test_answers.txt


Student: Christian Smith
Missed Questions: 1, 2, 3, 4, 6, 7, 8, 10, 11, 12, 13, 14, 17, 18, 20, 21, 
Overall grade: 14.3


Student: Paxton Jones
Missed Questions: 1, 2, 3, 5, 6, 7, 9, 10, 11, 13, 14, 15, 17, 20, 21, 
Overall grade: 16.7


Student: Abby Sciuto
Missed Questions: 1, 2, 3, 4, 5, 7, 8, 9, 10, 12, 13, 16, 20, 21, 
Overall grade: 23.8


Student: Audrey Smithson
Missed Questions: 1, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 
Overall grade: -3.6


Student: Katie Holmes
Missed Questions: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 14, 15, 17, 18, 
Overall grade: 23.8


Student: Carrie Grant
Missed Questions: 1, 2, 3, 6, 7, 8, 11, 12, 16, 17, 18, 
Overall grade: 38.1

Closing test_answers.txt

*/