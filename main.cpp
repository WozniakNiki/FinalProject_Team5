// ITCS 2530 Final Project - Team 5
// Nicole Wozniak, Kaden Jantz, Md Jehin

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Globals
const int ARRAY_SIZE = 9;
const int SETVALUE = 40;
const int CATEGORIES = 3;

struct Item
{
	string itemCategory; //cookies, cupcakes, pies
	string itemType;  //snickerdoodle, chocolate, apple for example.
	int quanity;
	float price; //single item price point
	float totalCost; //total price with the items price x quanity
};

struct Order
{
	Item items[ARRAY_SIZE];
	float orderTotal; //all items cost together
};

// Function Declarations
char MainMenu();
char SubMenu();
Order ReadFromFile(string fileName[3], Order order);
void CurrentOrder(Order order);
void EditOrder(Order order);
void AddToOrder(Order order);
void RemoveFromOrder(Order order);
string GetInitials(string name);
void Checkout(Order order);
bool Print(Order order, const string& filename);

//main flow with the main menu print out
//Nicole Wozniak
int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		std::cout << "Error! Not enough files found. Expecting 3!" << endl;
		return 1;
	}
	string fileNames[] = { argv[1] , argv[2], argv[3] };

	Order order;
	//Item item1;
	//Item item2;

	//item1.itemCategory = "Cookie";
	//item1.itemType = "Name Example";
	//item2.itemCategory = "Cupcake";
	//item2.itemType = "Test Name";

	//order.items[0] = item1;
	//order.items[1] = item1;
	//order.items[2] = item2;

	order = ReadFromFile(fileNames, order);
	
	cout << setfill('*') << setw(SETVALUE) << "" << endl;
	cout << "Welcome to the C Bakery!!" << endl;
	cout << setfill('*') << setw(SETVALUE) << "" << endl;

	enum Menu {EDIT = 'e', VIEW = 'v', CHECKOUT = 'c', EXIT = 'x', ADD = 'a', REMOVE = 'r' }; //Can remove add/remove if needed later
	char selection;

	selection = MainMenu();

	while (selection != 'x')
	{
		switch (selection)
		{
		case EDIT:
			EditOrder(order);
			selection = MainMenu();
			break;

		case VIEW:
			CurrentOrder(order);
			selection = MainMenu();
			break;

		case CHECKOUT:
			Checkout(order);
			selection = MainMenu();
			break;

		case EXIT:
			cout << "Hope to see you again soon! Good bye.";
			return 0;
			break;

		default:
			cout << "An error has occured";
			return 1;
			break;
		}
	}
	
	cout << "Hope to see you again soon! Good bye.";
	return 0;
}

//takes in three files and prints into proper structs/arrays
//Nicole Wozniak
Order ReadFromFile(string fileName[3], Order order)
{
	int categoryOneCounter = 0, categoryTwocounter = 0; //This will remove magic numbers and open it up to having an uneven amount of items in each category.
	ifstream file;
	for (int i = 0; i < CATEGORIES; i++)
	{
		
		file.open(fileName[i]);

		if (!file.is_open())
		{
			std::cout << "An Error has occured!" << endl;
		}
		int line = 0;
		switch (i)
		{
		case 0: //Cookies - first file
			for (int j = 0; j < CATEGORIES; j++)
			{
				order.items[j].itemCategory = "Cookies";
				file >> order.items[j].itemType >> order.items[j].price;
				order.items[j].quanity = 0;
				order.items[j].totalCost = 0.00;
				categoryOneCounter++;
			}
			break;
		case 1: //Cupcakes - second file
			categoryTwocounter = categoryOneCounter;
			for (int j = 0; j < CATEGORIES; j++)
			{
				order.items[j+ categoryOneCounter].itemCategory = "Cupcakes";
				file >> order.items[j+ categoryOneCounter].itemType >> order.items[j+ categoryOneCounter].price;
				order.items[j+ categoryOneCounter].quanity = 0;
				order.items[j+ categoryOneCounter].totalCost = 0.00;
				categoryTwocounter++;
			}
			break;
		case 2: //Pies - third file
			for (int j = 0; j < CATEGORIES; j++)
			{
				order.items[j +categoryTwocounter].itemCategory = "Pies";
				file >> order.items[j + categoryTwocounter].itemType >> order.items[j + categoryTwocounter].price;
				order.items[j + categoryTwocounter].quanity = 0;
				order.items[j + categoryTwocounter].totalCost = 0.00;
			}
			break;
		default:
			std::cout << "An Error has occured!" << endl;
			break;
		}
		file.close();
	}

	return order;
}

//Main Menu Readout
//Nicole Wozniak
char MainMenu()
{
	cout << "\nWhat would you like to do?" << endl;
	cout << "Enter 'e' to edit your order (adding or removing items)." << endl;
	cout << "Enter 'v' to see your current order." << endl;
	cout << "Enter 'c' to check out." << endl;
	cout << "Enter 'x' if you wish to quit." << endl;

	char input;
	cin >> input;
	input = tolower(input);
	return input;
}

//Submenu for the Edit Order
//Nicole Wozniak
char SubMenu()
{
	cout << "Enter 'a' to add to your order." << endl;
	cout << "Enter 'r' to remove from your order." << endl;

	char input;
	cin >> input;
	input = tolower(input);
	return input;
}

//view current order in the console
//Nicole Wozniak
void CurrentOrder(Order order)
{
	string category;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		Item displayItem = order.items[i];
		
		if (category != displayItem.itemCategory)
		{
			category = displayItem.itemCategory;
			cout << "\n" << category << ":" << endl;
		}

		cout << "There are " << order.items[i].quanity << " " << order.items[i].itemType << ". At the price of $" << fixed << setprecision(2) << order.items[i].price << " each. Total for this item is $" << order.items[i].totalCost << endl;
	}

	cout << "\nThe orders full cost is $" << setprecision(2) << order.orderTotal << endl;
}

//branch into the add/remove functions
//Kaden Jantz
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
//Kaden Jantz
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
//Kaden Jantz
void RemoveFromOrder(Order order)
{

}

//get the initials of a name for users
//Kaden Jantz
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
//Md Jehin
void Checkout(Order& order)
{
	order.orderTotal = 0.0;

	// Calculate the total cost for each item and update the order total
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		order.items[i].totalCost = order.items[i].quanity * order.items[i].price;
		order.orderTotal += order.items[i].totalCost;
	}

	// Print the order details
	Print(order, "order.txt");

	// Reset quantities to 0 after checkout
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		order.items[i].quanity = 0;
	}

	cout << "Your current order total is: $" << setprecision(2) << order.orderTotal << endl;
}

// Print order to console with totals, and print to order.txt file
// Md Jehin
bool Print(Order order, const string& filename)
{
	// Print the order details to the console
	CurrentOrder(order);

	// Write the order details to the specified file
	ofstream outFile(filename);

	if (!outFile.is_open())
	{
		cout << "Error writing to file." << endl;
		return false;
	}

	// Write the order details to the file
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		outFile << order.items[i].quanity << " " << order.items[i].itemType << " " << order.items[i].itemCategory
			<< " at the cost of $" << setprecision(2) << order.items[i].price << " each. For a total of $"
			<< setprecision(2) << order.items[i].totalCost << " for this item." << endl;
	}

	outFile << "The order's full cost is $" << setprecision(2) << order.orderTotal << endl;

	cout << "Order details have been saved to '" << filename << "'." << endl;

	outFile.close();
	return true;
}
