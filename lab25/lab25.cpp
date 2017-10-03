//Created By: Isaac Vander Sluis
//Created On: 10/3/17

/* ~~~~~~~~~~~~~~~~~~~~~~~~~BOOKSHELF~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   This program creates a class Book that stores the title, author, and
   copyright year of a book. The user will input data for 5 books. The program
   will print the users input as (s)he goes and print a list of all book data
   at the end.
*/

#include <iostream>
#include <string>
using namespace std;

class Book {
    public:
        void SetTitle(string book_name);        //mutator
        void SetAuthor(string author_name);     //mutator
        void SetCopyright(int copyright_year);  //mutator
        
        string GetTitle() const;                //accessor
        string GetAuthor() const;               //accessor
        int GetCopyright() const;               //accessor
        
        void PrintData();                       //accessor (print function)
    private:
        string title;                           //private object variables
        string author;
        int copyright;
};

//class function definitions
void Book::SetTitle(string book_name) {
    title = book_name;
}

void Book::SetAuthor(string author_name) {
    author = author_name;
}

void Book::SetCopyright(int copyright_year) {
    copyright = copyright_year;
}

string Book::GetTitle() const {
    return title;
}

string Book::GetAuthor() const {
    return author;
}

int Book::GetCopyright() const {
    return copyright;
}

void Book::PrintData() {
    cout << "Title: '" << GetTitle() << "'" << endl;
    cout << "Author: " << GetAuthor() << endl;
    cout << "Copyright Year: " << GetCopyright() << endl << endl;
    
    return;
}

int main() {
    Book book1;    //initializing 5 objects of type Book
    Book book2;
    Book book3;
    Book book4;
    Book book5;
    
    string user_string = ""; //these variables will be place-holders to use as function parameters
    int user_int = 0;
    
    //informing user to prepare for steps ahead
    cout << "Pick 5 books. You will be entering the title, author, " << endl;
    cout << "and copyright year for each." << endl;
    
    //getting info from user
    cout << "Book One" << endl << "Enter title: " << endl;
    getline(cin, user_string);
    book1.SetTitle(user_string);
    cout << "You entered '" << book1.GetTitle() << "' as the title." << endl;
    cout << "Enter author: " << endl;
    getline(cin, user_string);
    book1.SetAuthor(user_string);
    cout << "You entered '" << book1.GetAuthor() << "' as the author." << endl;
    cout << "Enter copyright: " << endl;
    cin >> user_int;
    book1.SetCopyright(user_int);
    cout << "You entered '" << book1.GetCopyright() << "' as the copyright." << endl << endl;
    cin.ignore(1); //ignores the \n char left over previous cin >> user_int
    
    cout << "Book Two" << endl << "Enter title: " << endl;
    getline(cin, user_string);
    book2.SetTitle(user_string);
    cout << "You entered '" << book2.GetTitle() << "' as the title." << endl;
    cout << "Enter author: " << endl;
    getline(cin, user_string);
    book2.SetAuthor(user_string);
    cout << "You entered '" << book2.GetAuthor() << "' as the author." << endl;
    cout << "Enter copyright: " << endl;
    cin >> user_int;
    book2.SetCopyright(user_int);
    cout << "You entered '" << book2.GetCopyright() << "' as the copyright." << endl << endl;
    cin.ignore(1);
    
    cout << "Book Three" << endl << "Enter title: " << endl;
    getline(cin, user_string);
    book3.SetTitle(user_string);
    cout << "You entered '" << book3.GetTitle() << "' as the title." << endl;
    cout << "Enter author: " << endl;
    getline(cin, user_string);
    book3.SetAuthor(user_string);
    cout << "You entered '" << book3.GetAuthor() << "' as the author." << endl;
    cout << "Enter copyright: " << endl;
    cin >> user_int;
    book3.SetCopyright(user_int);
    cout << "You entered '" << book3.GetCopyright() << "' as the copyright." << endl << endl;
    cin.ignore(1);
    
    cout << "Book Four" << endl << "Enter title: " << endl;
    getline(cin, user_string);
    book4.SetTitle(user_string);
    cout << "You entered '" << book4.GetTitle() << "' as the title." << endl;
    cout << "Enter author: " << endl;
    getline(cin, user_string);
    book4.SetAuthor(user_string);
    cout << "You entered '" << book4.GetAuthor() << "' as the author." << endl;
    cout << "Enter copyright: " << endl;
    cin >> user_int;
    book4.SetCopyright(user_int);
    cout << "You entered '" << book4.GetCopyright() << "' as the copyright." << endl << endl;
    cin.ignore(1);
    
    cout << "Book Five" << endl << "Enter title: " << endl;
    getline(cin, user_string);
    book5.SetTitle(user_string);
    cout << "You entered '" << book5.GetTitle() << "' as the title." << endl;
    cout << "Enter author: " << endl;
    getline(cin, user_string);
    book5.SetAuthor(user_string);
    cout << "You entered '" << book5.GetAuthor() << "' as the author." << endl;
    cout << "Enter copyright: " << endl;
    cin >> user_int;
    book5.SetCopyright(user_int);
    cout << "You entered '" << book5.GetCopyright() << "' as the copyright." << endl << endl;
    cin.ignore(1);
    
    cout << "These are the items on your bookshelf: " << endl; //prints info for all 5 books to user
    book1.PrintData();
    book2.PrintData();
    book3.PrintData();
    book4.PrintData();
    book5.PrintData();
}

/*

Pick 5 books. You will be entering the title, author, 
and copyright year for each.
Book One
Enter title: 
Fahrenheit 451
You entered 'Fahrenheit 451' as the title.
Enter author: 
Ray Bradbury
You entered 'Ray Bradbury' as the author.
Enter copyright: 
1953
You entered '1953' as the copyright.

Book Two
Enter title: 
Good Omens
You entered 'Good Omens' as the title.
Enter author: 
Terry Pratchett
You entered 'Terry Pratchett' as the author.
Enter copyright: 
1990
You entered '1990' as the copyright.

Book Three
Enter title: 
The Lies of Locke Lamora
You entered 'The Lies of Locke Lamora' as the title.
Enter author: 
Scott Lynch
You entered 'Scott Lynch' as the author.
Enter copyright: 
2006
You entered '2006' as the copyright.

Book Four
Enter title: 
Nineteen Eighty-Four
You entered 'Nineteen Eighty-Four' as the title.
Enter author: 
George Orwell
You entered 'George Orwell' as the author.
Enter copyright: 
1949
You entered '1949' as the copyright.

Book Five
Enter title: 
House of Leaves
You entered 'House of Leaves' as the title.
Enter author: 
Mark Z. Danielewski
You entered 'Mark Z. Danielewski' as the author.
Enter copyright: 
2000
You entered '2000' as the copyright.

These are the items on your bookshelf: 
Title: 'Fahrenheit 451'
Author: Ray Bradbury
Copyright Year: 1953

Title: 'Good Omens'
Author: Terry Pratchett
Copyright Year: 1990

Title: 'The Lies of Locke Lamora'
Author: Scott Lynch
Copyright Year: 2006

Title: 'Nineteen Eighty-Four'
Author: George Orwell
Copyright Year: 1949

Title: 'House of Leaves'
Author: Mark Z. Danielewski
Copyright Year: 2000

*/