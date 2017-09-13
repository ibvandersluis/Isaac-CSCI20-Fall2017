//Created By: Isaac Vander Sluis
//Created On: 9/12/17

/* ~~~~Stock Portfolio~~~~
   Uses a struct to hold a stock portfolio. It holds information about the
   stock's name, sector, current price, and number of shares owned.
   
   The sectors are codified with letters according to this system:
   A - Auto Companies
   C - Consumer Products
   F - Financial/Insurance
   I - Industrial
   T - Technology
*/

#include <iostream>
#include <string>
using namespace std;

struct Portfolio {
    string stock_name;
    char stock_sector;
    double stock_value;
    int stock_owned;
    double total;
};

int main() {
    Portfolio stock1;  //Initialiezes new instance of object with type Portfolio
    
    cout << "Enter information for stock 1..." << endl; //Get info for stock1 from user
    cout << "Enter stock name: " << endl;
    cin >> stock1.stock_name;
    cout << "Enter the stock sector: " << endl << "A - Auto Company" << endl;
    cout << "C - Consumer Products" << endl << "F - Financial/Insurance" << endl;
    cout << "I - Industrial" << endl << "T - Technology" << endl;
    cin >> stock1.stock_sector;
    cout << "Enter current stock price: " << endl;
    cin >> stock1.stock_value;
    cout << "Enter the number of stocks owned: " << endl;
    cin >> stock1.stock_owned;
    
    stock1.total = stock1.stock_owned * stock1.stock_value; //Calculate total value of stock1 held by user
    
    //-----------------------------------------------------
    
    Portfolio stock2;  //Initialiezes new instance of object with type Portfolio
    
    cout << "Enter information for stock 2..." << endl; //Get info for stock2 from user
    cout << "Enter stock name: " << endl; 
    cin >> stock2.stock_name;
    cout << "Enter the stock sector: " << endl << "A - Auto Company" << endl;
    cout << "C - Consumer Products" << endl << "F - Financial/Insurance" << endl;
    cout << "I - Industrial" << endl << "T - Technology" << endl;
    cin >> stock2.stock_sector;
    cout << "Enter current stock price: " << endl;
    cin >> stock2.stock_value;
    cout << "Enter the number of stocks owned: " << endl;
    cin >> stock2.stock_owned;
    
    stock2.total = stock2.stock_owned * stock2.stock_value; //Calculate total value of stock2 held by user
    
    //-----------------------------------------------------
    
    Portfolio stock3;  //Initialiezes new instance of object with type Portfolio
    
    cout << "Enter information for stock 3..." << endl; //Get info from stock3 from user
    cout << "Enter stock name: " << endl; 
    cin >> stock3.stock_name;
    cout << "Enter the stock sector: " << endl << "A - Auto Company" << endl;
    cout << "C - Consumer Products" << endl << "F - Financial/Insurance" << endl;
    cout << "I - Industrial" << endl << "T - Technology" << endl;
    cin >> stock3.stock_sector;
    cout << "Enter current stock price: " << endl;
    cin >> stock3.stock_value;
    cout << "Enter the number of stocks owned: " << endl;
    cin >> stock3.stock_owned;
    
    stock3.total = stock3.stock_owned * stock3.stock_value; //Calculate total value of stock3 held by user
    
    //-----------------------------------------------------
    
    Portfolio stock4;  //Initialiezes new instance of object with type Portfolio
    
    cout << "Enter information for stock 4..." << endl; //Get info from stock4 from user
    cout << "Enter stock name: " << endl; 
    cin >> stock4.stock_name;
    cout << "Enter the stock sector: " << endl << "A - Auto Company" << endl;
    cout << "C - Consumer Products" << endl << "F - Financial/Insurance" << endl;
    cout << "I - Industrial" << endl << "T - Technology" << endl;
    cin >> stock4.stock_sector;
    cout << "Enter current stock price: " << endl;
    cin >> stock4.stock_value;
    cout << "Enter the number of stocks owned: " << endl;
    cin >> stock4.stock_owned;
    
    stock4.total = stock4.stock_owned * stock4.stock_value; //Calculate total value of stock4 held by user
    
    //-----------------------------------------------------
    
    Portfolio stock5;  //Initialiezes new instance of object with type Portfolio
    
    cout << "Enter information for stock 5..." << endl; //Get info from stock5 from user
    cout << "Enter stock name: " << endl; 
    cin >> stock5.stock_name;
    cout << "Enter the stock sector: " << endl << "A - Auto Company" << endl;
    cout << "C - Consumer Products" << endl << "F - Financial/Insurance" << endl;
    cout << "I - Industrial" << endl << "T - Technology" << endl;
    cin >> stock5.stock_sector;
    cout << "Enter current stock price: " << endl;
    cin >> stock5.stock_value;
    cout << "Enter the number of stocks owned: " << endl;
    cin >> stock5.stock_owned;
    
    stock5.total = stock5.stock_owned * stock5.stock_value; //Calculate total value of stock5 held by user
    
    //-----------------------------------------------------
    
    Portfolio stock6;  //Initialiezes new instance of object with type Portfolio
    
    cout << "Enter information for stock 6..." << endl; //Get info from stock6 from user
    cout << "Enter stock name: " << endl; 
    cin >> stock6.stock_name;
    cout << "Enter the stock sector: " << endl << "A - Auto Company" << endl;
    cout << "C - Consumer Products" << endl << "F - Financial/Insurance" << endl;
    cout << "I - Industrial" << endl << "T - Technology" << endl;
    cin >> stock6.stock_sector;
    cout << "Enter current stock price: " << endl;
    cin >> stock6.stock_value;
    cout << "Enter the number of stocks owned: " << endl;
    cin >> stock6.stock_owned;
    
    stock6.total = stock6.stock_owned * stock6.stock_value; //Calculate total value of stock6 held by user
    
    //-----------------------------------------------------
    
    double portfolio_total = stock1.total + stock2.total + stock3.total + stock4.total; //Calculate total value of portfolio
    
    cout << "     Stock Name     |   Sector  |   No of Shares  |   Current Value    |    Total Value   " << endl;
    cout << "____________________|___________|_________________|____________________|__________________" << endl;
    cout << "        " << stock1.stock_name << "              " << stock1.stock_sector << "               " << stock1.stock_owned << "               " << stock1.stock_value << "          " << stock1.total << endl;
    cout << "        " << stock2.stock_name << "              " << stock2.stock_sector << "               " << stock2.stock_owned << "               " << stock2.stock_value << "          " << stock2.total << endl;
    cout << "        " << stock3.stock_name << "              " << stock3.stock_sector << "               " << stock3.stock_owned << "               " << stock3.stock_value << "          " << stock3.total << endl;
    cout << "        " << stock4.stock_name << "              " << stock4.stock_sector << "               " << stock4.stock_owned << "               " << stock4.stock_value << "          " << stock4.total << endl;
    cout << "        " << stock5.stock_name << "              " << stock5.stock_sector << "               " << stock5.stock_owned << "               " << stock5.stock_value << "          " << stock5.total << endl;
    cout << "        " << stock6.stock_name << "              " << stock6.stock_sector << "               " << stock6.stock_owned << "               " << stock6.stock_value << "          " << stock6.total << endl;
    cout << endl << endl << "Portfolio Total: $" << portfolio_total << endl;
    
    return 0;
}

/* 
        Stock Name     |   Sector  |   No of Shares  |   Current Value    |    Total Value   
   ____________________|___________|_________________|____________________|__________________
        FordM              A                  87               18.76          1632.12
        Albertsn              C                  542               34.39          18639.4
        AAPL              T                  5               145.91          729.55
        TSLA              A                  50               375.64          18782
        WCF              F                  1368               35.02          47907.4
        AMD              T                  3               12.26          36.78


   Portfolio Total: $39783.1
*/