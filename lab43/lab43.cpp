//Created By: Isaac Vander Sluis
//Created On: 11/7/17

/*
    ~~~~~~~SHOPPING CART 0.1~~~~~~~
    This program serves the same funtion as Shopping Cart 0, but it uses objects
    to store information about each item. As in Shopping Cart 0, Shopping Cart
    0.1 uses parallel arrays to keep track of the items, price, and quantity
    that are in the store's inventory, and another set of parallel arrays are
    used to keep track of each item that the user adds to their cart. Loops are
    used to keep asking the user to add items to their cart until they elect to
    check out. After they are done shopping, their cart is printed out in an
    itemizes list, showing individual prices followed by the total.
*/

#include <iostream>
#include <string>
using namespace std;


/*
    This class defines items for sale in an online commerce environment. Each
    item has a name (product), a price, and a quantity held in the store. The
    class also includes a print function that prints a these variables.
*/
class Item {
    public:
        Item();
        Item(string name, double price, int quant);
        void PrintItem();
        
        void SetProduct(string name);
        void SetPrice(double price);
        void SetQuantity(int quant);
        
        const string GetProduct();
        const double GetPrice();
        const int GetQuantity();
    private:
        string product_;
        double price_;
        int quantity_;
};


//This constructor defines the default values of an item, if none are specified.
Item::Item() {
    product_ = "NO NAME";
    price_ = 0.00;
    quantity_ = 0;
}

//This overload constructor defines the product, price, and quantity as specified
Item::Item(string name, double price, int quant) {
    product_ = name;
    price_ = price;
    quantity_ = quant;
}

//This print function prints the product, price, and quantity in a line
void Item::PrintItem() {
    cout << product_ << "         $" << price_ << "    x " << quantity_ << endl;
}

//This function sets the product name to a specific value
void Item::SetProduct(string name) {
    product_ = name;
}

//This function sets the price to a specified value
void Item::SetPrice(double price) {
    price_ = price;
}

//This function sets the quantity to a specified value
void Item::SetQuantity(int quant) {
    quantity_ = quant;
}

//this function returns the name of the item
const string Item::GetProduct() {
    return product_;
}

//this funtion returns the price of the item
const double Item::GetPrice() {
    return price_;
}

//This function returns the quantity of the item
const int Item::GetQuantity() {
    return quantity_;
}


int main() {
    const int NUM_PRODUCTS = 10;                            //Sets the # of products for sale to 10
    char keep_shopping = 'Y';                               //Initializes a variable that lets the user continue their shopping
    int user_command = 0;                                   //Initializes a variable that lets the user select an item for purchase
    double total = 0.00;                                    //Initializes a variable that keeps track of the cart's total
    Item cart[NUM_PRODUCTS * 20];                           //Initializes an array to hold the shopping cart of the user
    Item inventory[NUM_PRODUCTS] = {                        //Initializes the inventory of the online store
        //   Product                Price    Quantity
        Item(" Mouse        ",      14.99,    50),
        Item(" Keyboard     ",      39.99,    45),
        Item(" Case         ",      74.99,    35),
        Item(" Motherboard  ",      94.99,    30),
        Item(" Processor    ",      99.99,    45),
        Item(" Graphics Card",      94.99,    40),
        Item(" Memory       ",      89.99,    60),
        Item(" Power Supply ",      69.99,    40),
        Item(" Hard Drive   ",      64.99,    30),
        Item("Monitor      ",       99.99,    15)
    };
    
    int cart_count = 0;                                     //Initializes a variable to keep track of an iterate through the cart's inventory
    
    while ((keep_shopping == 'Y') || (keep_shopping == 'y')) {
        for (int i = 0; i < NUM_PRODUCTS; i++) {            //This loop prints the current invetory of the online store
            cout << i+1 << ". ";
            inventory[i].PrintItem();
        }
        
        cout << endl << endl << "Enter an item number to add to your cart, or '0' to check out:" << endl;
        cin >> user_command;                                //Prompts user for input to select an item or check out
        
        int h = user_command - 1;
        
        if (user_command == 0) {                            //Looks for a checkout command from user
            keep_shopping = 'N';
        } else {
            if (inventory[h].GetQuantity() > 0) {           //Only adds to cart if there are items in stock
                inventory[h].SetQuantity(inventory[h].GetQuantity() - 1);
                cart[cart_count] = inventory[h];
                
                cout << cart[cart_count].GetProduct() << " was added to your cart." << endl;
                cart_count++;
            } else {                                        //Prompts user for another value if out of stock
                cout << "ERROR: Out of Stock" << endl;
                cout << "Enter an item number to add to your cart: " << endl;
                cin >> user_command;
            }
            
            cout << "Keep shopping? (Y/N)" << endl;         //Determines if user has other items to add to cart
            cin >> keep_shopping;
        }
    }
    
    cout << "Your shopping cart:" << endl;
    
    for (int g = 0; g <= cart_count; g++) {                 //This loop prints the user's cart
        if (cart[g].GetPrice() > 0.0001) {
            cout << cart[g].GetProduct() << "        $" << cart[g].GetPrice() << endl;
            total += cart[g].GetPrice();
        }
    }
    
    cout << endl << endl << "TOTAL: $" << total;            //Prints the total of the user's cart
    
    
    return 0;
}

/*

1.  Mouse                 $14.99        x 50
2.  Keyboard              $39.99        x 45
3.  Case                  $74.99        x 35
4.  Motherboard           $94.99        x 30
5.  Processor             $99.99        x 45
6.  Graphics Card         $94.99        x 40
7.  Memory                $89.99        x 60
8.  Power Supply          $69.99        x 40
9.  Hard Drive            $64.99        x 30
10. Monitor               $99.99        x 15


Enter an item number to add to cart, or '0' to check out:
5
 Processor     was added to your cart.
Keep shopping? (Y/N)
y
1.  Mouse                 $14.99        x 50
2.  Keyboard              $39.99        x 45
3.  Case                  $74.99        x 35
4.  Motherboard           $94.99        x 30
5.  Processor             $99.99        x 44
6.  Graphics Card         $94.99        x 40
7.  Memory                $89.99        x 60
8.  Power Supply          $69.99        x 40
9.  Hard Drive            $64.99        x 30
10. Monitor               $99.99        x 15


Enter an item number to add to cart, or '0' to check out:
8
 Power Supply  was added to your cart.
Keep shopping? (Y/N)
y
1.  Mouse                 $14.99        x 50
2.  Keyboard              $39.99        x 45
3.  Case                  $74.99        x 35
4.  Motherboard           $94.99        x 30
5.  Processor             $99.99        x 44
6.  Graphics Card         $94.99        x 40
7.  Memory                $89.99        x 60
8.  Power Supply          $69.99        x 39
9.  Hard Drive            $64.99        x 30
10. Monitor               $99.99        x 15


Enter an item number to add to cart, or '0' to check out:
2
 Keyboard      was added to your cart.
Keep shopping? (Y/N)
y
1.  Mouse                 $14.99        x 50
2.  Keyboard              $39.99        x 44
3.  Case                  $74.99        x 35
4.  Motherboard           $94.99        x 30
5.  Processor             $99.99        x 44
6.  Graphics Card         $94.99        x 40
7.  Memory                $89.99        x 60
8.  Power Supply          $69.99        x 39
9.  Hard Drive            $64.99        x 30
10. Monitor               $99.99        x 15


Enter an item number to add to cart, or '0' to check out:
4
 Motherboard   was added to your cart.
Keep shopping? (Y/N)
y
1.  Mouse                 $14.99        x 50
2.  Keyboard              $39.99        x 44
3.  Case                  $74.99        x 35
4.  Motherboard           $94.99        x 29
5.  Processor             $99.99        x 44
6.  Graphics Card         $94.99        x 40
7.  Memory                $89.99        x 60
8.  Power Supply          $69.99        x 39
9.  Hard Drive            $64.99        x 30
10. Monitor               $99.99        x 15


Enter an item number to add to cart, or '0' to check out:
0
Your shopping cart: 

 Processor             $99.99
 Power Supply          $69.99
 Keyboard              $39.99
 Motherboard           $94.99


TOTAL: $304.96

*/