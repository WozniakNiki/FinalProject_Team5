// ITCS 2530 Final Project - Team 5
// Nicole Wozniak, Kaden Jantz, Md Jehin

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Globals
const int ARRAY_SIZE = 3;

struct Order 
{
    Cookies cookies[ARRAY_SIZE];
    Cupcakes cupcakes[ARRAY_SIZE];
    Pies pies[ARRAY_SIZE];
    int orderTotal;

};

struct Cookies 
{
    string itemType; //ChocolateChip, PeanutButter, Snickerdoodle
    int quanity;
    double price; //2.50, 3.00, 3.50
    int totalCost;
};

struct Cupcakes
{
    string itemType; //Chocolate, Confetti, RedVelvet
    int quanity;
    double price; //3.00, 3.50, 4.00
    int totalCost;
};

struct Pies
{
    string itemType; //Apple, Pecan, KeyLime
    int quanity;
    double price; //5.00, 6.00, 7.00
    int totalCost;
};

//main flow with the main menu print out
int main()
{
    return 0;
}

//takes in three files and prints into proper structs/arrays
bool ReadFromFile(ifstream& file, Order order)
{

    return true;
}

//view current order in the console
void CurrentOrder(Order order)
{

}

//branch into the add/remove functions
void EditOrder(Order order)
{

}

//add item(s) to order
void AddToOrder(Order order)
{
}

//removing item(s) from order
void RemoveFromOrder(Order order)
{

}

//Check out the current order, calculate totals, lead into PrintFucntion
void Checkout(Order order)
{

}

//print order to console with totals, and print to order.txt file
bool Print(Order order)
{

}
