//Created By: Isaac Vander Sluis
//Created On: 11/16/17

/*

~~~~~~~~~TRANSCRIPT WEBPAGE GENERATOR~~~~~~~~~~~
This program prompts the user for a file to read. It iterates through the file,
reading in student names, the number of classes they take, and their respective
grades. It then calculates GPA and outputs this figure along with their name to
the user.

*/

#include <iostream>
#include <ios>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
    ifstream inFS;                  //initialize file input/output variables
    ofstream outFS;
    string file_name = "";          //initialize variables for info about the student and the file
    string first_name = "";
    string last_name = "";
    int num_classes = 0;
    char grade = ' ';
    int class_hours = 0;
    int total_units = 0;
    double grade_points = 0.0;
    double sem_gpa = 0.0;
    
    cout << "Enter file name for inport:" << endl;      //prompt user for file to read
    cin >> file_name;
    
    cout << "Opening " << file_name << endl;            //opens file and an html file for output
    inFS.open(file_name);
    outFS.open("output.html");
    if (!inFS.is_open()) {                              //prints error if file won't open
        cout << "Could not open file " << file_name << endl;
        return 1;
    }
    
    outFS << "<!DOCTYPE html>" << endl;                 //prints basic structure for html file
    outFS << "<html>" << endl;
    outFS << "<head>" << endl;
    outFS << "<title>Student Transcript</title>" << endl;
    outFS << "</head>" << endl;
    outFS << "<body>" << endl;
    outFS << "<h1>Student Transcript</h1>" << endl;
    
    outFS << setprecision(2) << fixed;                  //limit numbers to 2 digits after decimal point, for use with GPA
    
    while (!inFS.eof()) {                               //iterates through file, taking in student info
        sem_gpa = 0.0;
        inFS >> first_name;
        inFS >> last_name;
        inFS >> num_classes;
        
        outFS << "<h3>Student: " << first_name << " " << last_name << "</h3>" << endl;
        
        for (int n = num_classes; n > 0; n--) {
            inFS >> class_hours;
            inFS >> grade;
            
            switch (grade) {                            //determines number of grade points to add to student's running total
                case 'A':
                case 'a':
                    grade_points += 4.0 * class_hours;
                    break;
                case 'B':
                case 'b':
                    grade_points += 3.0 * class_hours;
                    break;
                case 'C':
                case 'c':
                    grade_points += 2.0 * class_hours;
                    break;
                case 'D':
                case 'd':
                    grade_points += 1.0 * class_hours;
                    break;
                case 'F':
                case 'f':
                    grade_points += 0.0;
                    break;
                default:
                    outFS << "ERROR" << endl;
            }
            total_units += class_hours;                 //adds units for current class to running total of student's units
        }
        sem_gpa = grade_points / total_units;           //output GPA by calculating grade points divided by number of units
        outFS << "<p>Semester GPA: " << sem_gpa << "</p>" <<endl;
    }
    
    outFS << "</body>" << endl;                         //wrap up html file
    outFS << "</html>" << endl;
    
    cout << "Closing " << file_name << endl;
    
    inFS.close();                                       //close files
    outFS.close();
    
    return 0;
}

/*

Enter file name for inport:
test_input.txt
Opening test_input.txt
Closing test_input.txt



<!DOCTYPE html>
<html>
<head>
<title>Student Transcript</title>
</head>
<body>
<h1>Student Transcript</h1>
<h3>Student: Suzy Cue</h3>
<p>Semester GPA: 3.75</p>
<h3>Student: Joe Joseph</h3>
<p>Semester GPA: 2.80</p>
<h3>Student: Jillian Smith</h3>
<p>Semester GPA: 2.55</p>
<h3>Student: Jillian Smith</h3>
<p>Semester GPA: 2.40</p>
</body>
</html>

*/