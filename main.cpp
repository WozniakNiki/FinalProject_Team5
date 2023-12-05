// ITCS 2530 Final Project - Team 5
// Nicole Wozniak, Kaden Jantz, Md Jehin

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Globals
const int ARRAY_SIZE = 9;

struct Order 
{
    Item items[ARRAY_SIZE];
    int orderTotal; //all items cost together
};

struct Item 
{
    string itemCategory; //cookies, cupcakes, pies
    string itemType;  //snickerdoodle, chocolate, apple for example.
    int quanity;
    double price; //single item price point
    int totalCost; //total price with the items price x quanity
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
