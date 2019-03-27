// Function_Assignment_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

void displayMenu();
void amtTendered(double);
double billTotal(double);

//Food Choices
const int GYRO_CHOICE = 1,
		  MOUSSAKA_CHOICE = 2,
		  SALAD_CHOICE = 3,
		  DOLMA_CHOICE = 4,
		  SODA_CHOICE = 5,
		  COFFEE_CHOICE = 6,
		  WATER_CHOICE = 7,
		  EXIT_CHOICE = 8;

//Food Prices
const double GYRO_PRICE = 7.00,
			 MOUSSAKA_PRICE = 8.50,
			 SALAD_PRICE = 3.75,
			 DOLMA_PRICE = 2.00,
			 SODA_PRICE = 2.80,
			 COFFEE_PRICE = 1.00,
			 WATER_PRICE = 2.00;


int main()
{

	int choice = 0;
	double subtotal = 0;
	double total = 0;
	char reset = 'y';

	do {
		displayMenu();
		cout << endl;

		do {

			cout << "Enter Your Selection: ";
			cin >> choice;

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

			while (choice < 1 || choice > 8)
			{
				cout << "Error not a valid input --> Re-enter: ";
				cin >> choice;
			}

		} while (choice != 8);

		total = billTotal(subtotal);

		amtTendered(total);

		cout << "\nWould you like to run this again? (Enter Y for YES): ";
		cin >> reset;

	} while (reset == 'y' || reset == 'Y');


    return 0;
}


//************************************
//		 Display Menu Function		 *
//************************************

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
	const double TIP = .20;
	const double TAX = .065;

	cout << left << setw(15) << "\nSubtotal: " << right << setw(1) << "$" << left << setw(8) << subtotal << endl;
	cout << left << setw(15) << "Tip Amount: " << right << setw(1) << "$" << left << setw(8) << subtotal * TIP << endl;
	cout << left << setw(15) << "Tax: " << right << setw(1) << "$" << left << setw(8) << subtotal * TAX << endl;

	return subtotal + (subtotal * TAX) + (subtotal * TIP);
}

//************************************
//    Amount Tendered Function		 *
//************************************

void amtTendered(double total)
{
	double payment = 0;

	cout << left << setw(15) << "\nTotal Bill: " << right << setw(1) << "$" << left << setw(8) << total << endl;
	cout << "Enter Amount Tendered: $";
	cin >> payment;

	if (payment >= total)
	{
		cout << "Thank You! Your change is: $" << payment - total << endl;
	}
	else {
			cout << "I\'m sorry that is not enough money please pay the remaining: $" << total - payment << endl;
     	 }


	}
