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
    ifstream inFS;
    ofstream outFS;
    string file_name = "";
    string first_name = "";
    string last_name = "";
    int num_classes = 0;
    char grade = ' ';
    int class_hours = 0.0;
    double sem_gpa = 0.0;
    double ovr_gpa = 0.0;
    
    cout << "Enter file name for inport:" << endl;
    cin >> file_name;
    cin.ignore();
    
    cout << "Opening " << file_name << endl;
    inFS.open(file_name);
    outFS.open("output.html");
    if (!inFS.is_open()) {
        cout << "Could not open file " << file_name << endl;
        return 1;
    }
    
    outFS << "<!DOCTYPE html>" << endl;
    outFS << "<html>" << endl;
    outFS << "<head>" << endl;
    outFS << "<title>Student Transcript</title>" << endl;
    outFS << "</head>" << endl;
    outFS << "<body>" << endl;
    outFS << "<h1>Student Transcript</h1>";
    
    while (!inFS.eof()) {
        sem_gpa = 0.0;
        inFS >> first_name;
        inFS >> last_name;
        inFS >> num_classes;
        
        outFS << "<h3>Student: " << first_name << " " << last_name << "</h3>" << endl;
        
        for (int n = num_classes; n > 0; n--) {
            inFS >> class_hours;
            inFS >> grade;
            
            switch (grade) {
                case 'A':
                case 'a':
                    sem_gpa += 4.0;
                    break;
                case 'B':
                case 'b':
                    sem_gpa += 3.0;
                    break;
                case 'C':
                case 'c':
                    sem_gpa += 2.0;
                    break;
                case 'D':
                case 'd':
                    sem_gpa += 1.0;
                    break;
                case 'F':
                case 'f':
                    sem_gpa += 0.0;
                    break;
                default:
                    outFS << "ERROR" << endl;
            }
        }
        
        outFS << "<p>Semester GPA: " << sem_gpa / num_classes << "</p>" <<endl;
    }
    
    outFS << "</body>" << endl;
    outFS << "</html>" << endl;
    
    cout << "Closing " << file_name << endl;
    
    inFS.close();
    outFS.close();
    
    return 0;
}

/*

<!DOCTYPE html>
<html>
<head>
<title>Student Transcript</title>
</head>
<body>
<h1>Student Transcript</h1><h3>Student: Suzy Cue</h3>
<p>Semester GPA: 3.75</p>
<h3>Student: Joe Joseph</h3>
<p>Semester GPA: 2</p>
<h3>Student: Jillian Smith</h3>
<p>Semester GPA: 2.2</p>
<h3>Student: Jillian Smith</h3>
<p>Semester GPA: 2</p>
</body>
</html>

*/