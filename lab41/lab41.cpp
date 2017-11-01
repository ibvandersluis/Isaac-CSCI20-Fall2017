//Created By: Isaac Vander Sluis
//Created On: 10/31/17

/*
    ~~~~~~~ARRAY TOOLS~~~~~~~
    This program creates a class ArrayTools that provides the user with a
    rudimentary toolbox for determining critical information about an integer
    array. The class functions can tell the user:
        - The max and min values within a given range
        - The sum of all elements in the array
        - The number of even and odd numbers in the array
        - What location a certain number is stored there, if present
        - Whether or not the array is given in order
        - And prints all elements of the array
    
   
*/

#include <iostream>
using namespace std;

class ArrayTools {
    public:
        ArrayTools();                             //Constructor
        ArrayTools(int array[], int size);        //Overload constructor
        void const Print();                       //Print function
        
        int Find_min(int a, int b);               //Determines min
        int Find_max(int a, int b);               //Determines max
        int Find_sum();                           //Determines sum
        int Num_even();                           //Determines num evens
        int Num_odd();                            //Determines num odds
        int Search(int val);                      //Determines if a value is present
        
        bool Is_sorted();                         //Determines if array is sorted
    private:
        int size_;                                //Class variables
        int array_[];
};

//This constructor sets a default array and size
ArrayTools::ArrayTools() {
    int value = 0;
    size_ = 10;    
    for (int i = 0; i < 10; i++) {
        array_[i] = value;
        value++;
    }

}

//This overloaded constructor allows the user to specify the array and the size
ArrayTools::ArrayTools(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array_[i] = array[i];
    }
    size_=size;
}

//This function prints all elements of the array
void const ArrayTools::Print() { 
    for (int i = 0; i < size_; i++) {
        cout << array_[i] << " ";
    }
    cout << endl;
    
    return;
}

//This function returns the maximum value within a range of indices
int ArrayTools::Find_max(int a, int b) {
    int max = array_[a];
    
    for (int i = a; i <= b; i++) {
        if (array_[i] > max) {
            max = array_[i];
        }
    }
    return max;
}

//This function returns the minimum value within a range of indices
int ArrayTools::Find_min(int a, int b) {
    int min = array_[a];
    
    for (int i = a; i <= b; i++) {
        if (array_[i] < min) {
            min = array_[i];
        }
    }
    return min;
}

//This function returns the sum of the values within the array
int ArrayTools::Find_sum() {
    int sum = 0;
    
    for (int i = 0; i < size_; i++) {
        sum += array_[i];
    }
    return sum;
}

//This function returns the number of even numbers in the array
int ArrayTools::Num_even() {
    int even = 0;
    
    for (int i = 0; i < size_; i++) {
        if ((array_[i] % 2) == 0) {
            even++;
        }
    }
    return even;
}

//This function returns the number of odd numbers in the array
int ArrayTools::Num_odd() {
    int odd = 0;
    
    for (int i = 0; i < size_; i++) {
        if ((array_[i] % 2) == 1) {
            odd++;
        }
    }
    return odd;
}

//This function returns the index location of a value if it is present in the array or -1 otherwise
int ArrayTools::Search(int val) {
    int i = 0;

    for (i = 0; i < size_; i++) {
        if (array_[i] == val) {
            return i;
        }
    }
    return -1;
}

//This function determines if the array is given in increasing order
bool ArrayTools::Is_sorted() {
    int num_in_order = 0;
    
    for (int i = 0; i < size_; i++) {
        if (i == 0) {
            num_in_order++;
        } else if (array_[i] >= array_[i-1]) {
            num_in_order++;
        }
    }
    
    if (num_in_order == size_) {
        return true;
    } else {
        return false;
    }
}

int main() {
    const int SIZE = 10;
    int myArray[SIZE];
    
    cout << "Enter an array of 10 integers: " << endl;
    
    for(int i = 0; i < SIZE; i++) {
        cin>>myArray[i];
    }
    ArrayTools a(myArray, SIZE);
    
    a.Print();
    cout<<"Min: "<<a.Find_min(0, 4)<<endl;
    cout<<"Max: "<<a.Find_max(5, 10)<<endl;
    cout<<"Sum = "<<a.Find_sum()<<endl;
    cout<<"Search 10 "<<a.Search(10)<<endl;
    cout<<"Sorted? "<<a.Is_sorted()<<endl;
    
    return 0;
}

/*

    Enter an array of 10 integers: 
    1
    2
    3
    4
    5
    6
    7
    8
    9
    10
    1 2 3 4 5 6 7 8 9 10 
    Min: 1
    Max: 10
    Sum = 55
    Search 10 9
    Sorted? 1

*/