// ITCS 2530 Final Project - Team 5
// Nicole Wozniak, Kaden Jantz, Md Jehin

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Globals
const int ARRAY_SIZE = 9;

struct Item
{
    string itemCategory; //cookies, cupcakes, pies
    string itemType;  //snickerdoodle, chocolate, apple for example.
    int quanity;
    double price; //single item price point
    int totalCost; //total price with the items price x quanity
};

struct Order
{
    Item items[ARRAY_SIZE];
    int orderTotal; //all items cost together
};

// Function Declarations
bool ReadFromFile(ifstream& file, Order order);
void CurrentOrder(Order order);
void EditOrder(Order order);
void AddToOrder(Order order);
void RemoveFromOrder(Order order);
string GetInitials(string name);
void Checkout(Order order);
bool Print(Order order);

//main flow with the main menu print out
int main()
{
    Order order;

    Item item1;
    Item item2;

    item1.itemCategory = "Cookie";
    item1.itemType = "Name Example";
    item2.itemCategory = "Cupcake";
    item2.itemType = "Test Name";

    order.items[0] = item1;
    order.items[1] = item1;
    order.items[2] = item2;

    EditOrder(order);

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
    // Input a full string to avoid input overflow
    string input;

    cout << "Would you like to add or remove items? (a/r)";
    cin >> input;

    // Check first char
    if (input[0] == 'a')
        AddToOrder(order);

    else if (input[0] == 'r')
        RemoveFromOrder(order);

    // Cancel
    else {
        cout << "Unrecognized Command! Canceling edit..." << endl;
        return;
    }
}

//add item(s) to order
void AddToOrder(Order order)
{
    // Keep track of current catagory
    string category;

    // Configure output settings
    cout << fixed << setprecision(2);

    // Display each item option
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        Item item = order.items[i];

        // Print catagory headers
        if (category != item.itemCategory) {
            category = item.itemCategory;

            cout << category << ":" << endl;
        }

        cout << item.itemType << " (" << GetInitials(item.itemType) << ") - $" << item.price << endl;
    }
}

//removing item(s) from order
void RemoveFromOrder(Order order)
{

}

//get the initials of a name for users
string GetInitials(string name)
{
    // Start with first letter
    string initials = "";
    initials += name[0];

    // Go through every character
    for (int i = 1; i < name.length() - 1; i++)
        // Add the one after if one is space
        if (name[i] == ' ')
        {
            i++;
            initials += name[i];
        }

    return initials;
}

//Check out the current order, calculate totals, lead into PrintFucntion
void Checkout(Order order)
{

}

//print order to console with totals, and print to order.txt file
bool Print(Order order)
{

}
