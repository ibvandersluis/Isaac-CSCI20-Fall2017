//Created By: Isaac Vander Sluis
//Created On: 10/10/17

/* ~~~~Phone Plan Calculator~~~~
   This program takes the amount of data, number of lines, and number of tablets
   from the user and compare each plan to determine which is cheapest.
   The program then ouputs the best option to the user...
*/

#include <iostream>
using namespace std;

//Calculates the cost of the plan based on data, number of lines, and number of tablets desired
int ATTUnlimChoice(int data, int lines, int tablets) {
    int data_price = 0;
    int lines_price = 0;
    int tablets_price = 0;
    
    if (lines == 1) {
        lines_price = 60;
    } else if (lines = 2) {
        lines_price = 115;
    } else if ((lines > 2) && (lines <= 10)) {
        lines_price = 115 + (20 * (lines - 2));
    }
    
    tablets_price = 10 * tablets;
    
    return data_price + lines_price + tablets_price;
}

//Calculates the cost of the plan based on data, number of lines, and number of tablets desired
int ATTFamily(int data, int lines, int tablets) {
    int data_price = 0;
    int lines_price = 0;
    int tablets_price = 0;
    
    if (data == 0) {
        data_price = 0;
    } else if (data <= 1) {
        data_price = 30;
    } else if (data <= 3) {
        data_price = 40;
    } else if (data <= 6) {
        data_price = 60;
    } else if (data <= 10) {
        data_price = 80;
    } else if (data <= 16) {
        data_price = 90;
    } else if (data <= 25) {
        data_price = 110;
    }
    
    lines_price = 20 * lines;
    tablets_price = 10 * tablets;
    
    return data_price + lines_price + tablets_price;
}

//Calculates the cost of the plan based on data, number of lines, and number of tablets desired
int VZUnlim(int data, int lines, int tablets) {
    int data_price = 0;
    int lines_price = 0;
    int tablets_price = 0;
    
    if (lines == 1) {
        lines_price = 80;
    } else if (lines > 1) {
        lines_price = 110 + (20 * lines);
    }
    
    tablets_price = 10 * tablets;
    
    return data_price + lines_price + tablets_price;
}

//Calculates the cost of the plan based on data, number of lines, and number of tablets desired
int SprintUnlim(int data, int lines, int tablets) {
    int data_price = 0;
    int lines_price = 0;
    int tablets_price = 0;
    
    if (lines == 1) {
        lines_price = 60;
    } else if (lines > 1) {
        lines_price = 100 + (30 * (lines - 2));
    }
    
    return data_price + lines_price + tablets_price;
}

//Calculates the cost of the plan based on data, number of lines, and number of tablets desired
int Sprint2GB(int data, int lines, int tablets) {
    int data_price = 0;
    int lines_price = 0;
    int tablets_price = 0;
    
    lines_price = 40 * lines;
    
    return data_price + lines_price + tablets_price;
}

int main() {
    //initializing variables for user input
    int data_gb = 0;
    int num_lines = 0;
    int num_tablets = 0;
    
    //initializing variables to hold results of math functions
    int att_unlimited_choice = 0;
    int att_family_plan = 0;
    int verizon_unlimited = 0;
    int sprint_unlimited = 0;
    int sprint_2g = 0;
    
    //getting info from user
    cout << "How many lines do you need in your plan?" << endl;
    cin >> num_lines;
    cout << "How many gigabytes of data do you need?" << endl;
    cin >> data_gb;
    cout << "How many tablets?" << endl;
    cin >> num_tablets;
    
    att_unlimited_choice = ATTUnlimChoice(data_gb, num_lines, num_tablets);  //variables with results of cost calculations
    att_family_plan = ATTFamily(data_gb, num_lines, num_tablets);
    verizon_unlimited = VZUnlim(data_gb, num_lines, num_tablets);
    sprint_unlimited = SprintUnlim(data_gb, num_lines, num_tablets);
    sprint_2g = Sprint2GB(data_gb, num_lines, num_tablets);
    
    //printing info back to user
    if ((att_unlimited_choice < att_family_plan) && (att_unlimited_choice < verizon_unlimited) && (att_unlimited_choice < sprint_unlimited) && (att_unlimited_choice < sprint_2g)) {
        cout << "It looks like the AT&T Unlimited Choice Plan is the best for you." << endl;
    } else if ((att_family_plan < att_unlimited_choice) && (att_family_plan < verizon_unlimited) && (att_family_plan < sprint_unlimited) && (att_family_plan < sprint_2g)) {
        cout << "It looks like the AT&T Family Plan is the best for you." << endl;
    } else if ((verizon_unlimited < att_unlimited_choice) && (verizon_unlimited < att_family_plan) && (verizon_unlimited < sprint_unlimited) && (verizon_unlimited < sprint_2g)) {
        cout << "It looks like the Verizon Unlimited Plan is the best for you." << endl;
    } else if ((sprint_unlimited < att_unlimited_choice) && (sprint_unlimited < att_family_plan) && (sprint_unlimited < verizon_unlimited) && (sprint_unlimited < sprint_2g)) {
        cout << "It looks like the Sprint Unlimited Plan is the best for you." << endl;
    } else if ((sprint_2g < sprint_unlimited) && (sprint_2g < verizon_unlimited) && (sprint_2g < att_family_plan) && (sprint_2g < att_unlimited_choice)) {
        cout << "It looks like the Sprint 2G Plan is the best for you." << endl;
    }
    
    return 0;
}

/*
How many lines do you need in your plan?
2
How many gigabytes of data do you need?
5
How many tablets?
0
It looks like the Sprint 2G Plan is the best for you.

How many lines do you need in your plan?
3
How many gigabytes of data do you need?
15
How many tablets?
1
It looks like the Sprint 2G Plan is the best for you.

How many lines do you need in your plan?
1
How many gigabytes of data do you need?
0
How many tablets?
0
It looks like the AT&T Family Plan is the best for you.
*/