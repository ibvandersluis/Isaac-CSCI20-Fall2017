//Created By: Isaac Vander Sluis
//Created On: 11/16/17

/*



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
    string student_name = "";
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
        getline(inFS, student_name);
        inFS >> num_classes;
        
        outFS << "<h3>Student: " << student_name << "</h3>" << endl;
        
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
                    cout << "ERROR" << endl;
            }
        }
        
        outFS << "<p>Semester GPA: " << sem_gpa / num_classes << "</p>" <<endl;
        
    }
    
    outFS << "</body>" << endl;
    outFS << "</html>" << endl;
    
    cout << "Closing " << file_name << endl;
    
    inFS.close();
    
    return 0;
}

/*

Enter file name for inport:
test_input.txt
Opening test_input.txt

*/