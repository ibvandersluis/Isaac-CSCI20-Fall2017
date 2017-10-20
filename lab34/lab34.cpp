 // This program reads in a letter and reports whether
// it is an uppercase letter, a lowercase letter, or neither.
// it should continue reading in values until the user enters a -1.
#include <iostream> 
using namespace std; 
int main() {
        // Read a character in
        char ch;
        cout << "Please enter a character: ";
        cin  >> ch;
         
// check -- is it a letter??
        if (ch >= 'a') {
            if (ch <= 'z') {
               cout << "Yes, that is a lowercase letter." << endl;
            }
        }
        else if (ch >= 'A') {
            if (ch <= 'Z') {
               cout << "Yes, that is a uppercase letter" << endl;
            }
        }        else {
            cout << "Not a letter" << endl;
        }
          return 0; }
/*
    Process: To debug this program, the first thing I did was run the program.
    A long list of errors came out, so I went to the top error, which said that
    the #include statement was expecting a library. So I looked at the line with
    #include and found that the library <iostream> was on the next line. I moved
    the library to the same line as #include and ran the program, no errors.
   
    I was prompted to enter a character, according to the purpose of the program.
    I started entering characters systematically:
        - 3 upper case letters: 'A', 'Z', and a letter in the middle. All
          produced the expected output.
        - 3 lower case letters: 'a', 'z', and a letter in the middle. None of
          these printed any output. I took note of this and tested the 'else'
          branch.
        - 3 non-letter characters: '0', '9', and '%'. All produced the expected
          output.
          
    I then set about determining why inputting a lower case letter was not
    producing the expected output. I realized that the way the if-else branch
    was set up, lower case letters must have values greater that 'A' in order
    to even enter the decision tree. I'm not very familiar with the ASCII table,
    but I realized it could be possible for the logic to be set up backwards.
    So I swapped where the upper case and lower case letters were in the logic
    tree, and also swapped the print statements accordingly. The program worked.
    
    In hindsight, if I were the one writing this program, I would have avoided
    nested if-else entirely and instead used something like
            
            if ((ch >= 'A') && (ch <= 'Z')) {
                [print statement]
            } else if ((ch >= 'a') && (ch <= 'z')) {
                [print statement]
            } else {
                [print statement]
            }
            
    This would have avoided the initial logic error.
*/