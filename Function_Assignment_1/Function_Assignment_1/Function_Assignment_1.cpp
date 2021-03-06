// Function_Assignment_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

void displayMenu();
void amtTendered(double);
double billTotal(double);

//Food Choice Constants

const int GYRO_CHOICE = 1,
		  MOUSSAKA_CHOICE = 2,
		  SALAD_CHOICE = 3,
		  DOLMA_CHOICE = 4,
		  SODA_CHOICE = 5,
		  COFFEE_CHOICE = 6,
		  WATER_CHOICE = 7,
		  EXIT_CHOICE = 8;

//Food Price Constants

const double GYRO_PRICE = 7.00,
			 MOUSSAKA_PRICE = 8.50,
			 SALAD_PRICE = 3.75,
			 DOLMA_PRICE = 2.00,
			 SODA_PRICE = 2.80,
			 COFFEE_PRICE = 1.00,
			 WATER_PRICE = 2.00;


//Initialize Main Function

int main()
{

	int choice = 0;				// Variable For Menu Choice
	double subtotal = 0;		// Variable For Order Subtotal
	double total = 0;			// Variable For Order Total
	char reset = 'y';			// Variable For Resetting Program

	do {

		//Call Display Menu Function
		displayMenu();
		cout << endl;

		do {

			// Ask user for menu selection
			cout << "Enter Your Selection: ";
			cin >> choice;


			// Data Validation Checking for only INT or DOUBLE values
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "***ERROR*** Invalid Input --> Re-Enter Selection: ";
				cin >> choice;
			}

			// Loop through choices adding each menu item price to variable subtotal
			switch (choice)
			{
			case GYRO_CHOICE:
				subtotal += GYRO_PRICE;
				break;
			case MOUSSAKA_CHOICE:
				subtotal += MOUSSAKA_PRICE;
				break;
			case SALAD_CHOICE:
				subtotal += SALAD_PRICE;
				break;
			case DOLMA_CHOICE:
				subtotal += DOLMA_PRICE;
				break;
			case SODA_CHOICE:
				subtotal += SODA_PRICE;
				break;
			case COFFEE_CHOICE:
				subtotal += COFFEE_PRICE;
				break;
			case WATER_CHOICE:
				subtotal += WATER_PRICE;
				break;
			}

			//If choice is not in range throw an error and ask user to re-enter value
			while (choice < 1 || choice > 8)
			{
				cout << "Error not a valid input --> Re-enter: ";
				cin >> choice;
			}

			//Continue to loop as long as choice is not equal to 8
		} while (choice != 8);


		// Use value of subtotal as a parameter for billTotal Function and return that value and set it equal to variable total
		total = billTotal(subtotal);

		// Call amtTendered function using variable total as a parameter
		amtTendered(total);

		// Reset variable subtotal to 0 so program can start fresh if re-ran
		subtotal = 0;

		// Ask user if they would like to place another order
		cout << "\nWould you like to place another order? (Enter Y for YES): ";
		cin >> reset;
		cout << endl;

		// While the user returns y re-run the program if not terminate the program.
	} while (reset == 'y' || reset == 'Y');


    return 0;
}


//************************************
//		 Display Menu Function		 *
//************************************

// Prints the Menu to the display

void displayMenu()
{
	cout << fixed << setprecision(2);
	cout << "Greek Island Menu\n\n";
	cout << left << setw(15) << "1) Gyro" << right << setw(1) << "$" << left << setw(8) << GYRO_PRICE << endl;
	cout << left << setw(15) << "2) Moussaka" << right << setw(1) << "$" << left << setw(8) << MOUSSAKA_PRICE << endl;
	cout << left << setw(15) << "3) Salad" << right << setw(1) << "$" << left << setw(8) << SALAD_PRICE << endl;
	cout << left << setw(15) << "4) Dolma" << right << setw(1) << "$" << left << setw(8) << DOLMA_PRICE << endl;
	cout << left << setw(15) << "5) Soda" << right << setw(1) << "$" << left << setw(8) << SODA_PRICE << endl;
	cout << left << setw(15) << "6) Coffee" << right << setw(1) << "$" << left << setw(8) << COFFEE_PRICE << endl;
	cout << left << setw(15) << "7) Water" << right << setw(1) << "$" << left << setw(8) << WATER_PRICE << endl;
	cout << left << setw(15) << "8) End Order" << endl;
}

//************************************
//		 Total Bill Function		 *
//************************************

double billTotal(double subtotal)
{
	const double TIP = .20;			// Declares a constant for Tip Percentage
	const double TAX = .065;		// Declares a constant for Tax Rate


	// Prints and Calculates: Subtotal, Tip Amount, and Tax
	cout << left << setw(15) << "\nSubtotal: " << right << setw(1) << "$" << left << setw(8) << subtotal << endl;
	cout << left << setw(15) << "Tip Amount: " << right << setw(1) << "$" << left << setw(8) << subtotal * TIP << endl;
	cout << left << setw(15) << "Tax: " << right << setw(1) << "$" << left << setw(8) << subtotal * TAX << endl;

	// Returns the sum of Subtital, Tip Amount, and Tax
	return subtotal + (subtotal * TAX) + (subtotal * TIP);
}

//************************************
//    Amount Tendered Function		 *
//************************************

void amtTendered(double total)
{
	double payment = 0;				// Declares a double variable for payment


	// Prints the bill total, and Askes the user to enter the payment amount.
	cout << left << setw(15) << "\nTotal Bill: " << right << setw(1) << "$" << left << setw(8) << total << endl;
	cout << "Enter Amount Tendered: $";
	cin >> payment;

	// Data Validation Checking for only INT or DOUBLE values
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "***ERROR*** Invalid Input --> Re-Enter Amount Tendered: $";
		cin >> payment;
	}

	// If the payment is sufficient change returned will be printed to the display
	if (payment >= total)
	{
		cout << "Thank You! Your change is: $" << payment - total << endl;
	}
	else {

		// If the payment is less than total run this
		while (payment < total)
		{
			// Set total to total minus the payment to get new required amount.
			total = total - payment;
			cout << "\nI\'m sorry that is not enough money please pay the remaining: $" << total << endl;

			//Have the user enter another payment amount to pay the remainder
			cout << "Enter Payment Amount: $";
			cin >> payment;
		}

		// Once the Condition was met print the amount of change that should be given
		cout << "\nThank You! Your change is: $" << payment - total << endl;
     }
	}
