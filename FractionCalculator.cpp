//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : Fraction Calculator (L3-2)                        * 
//*                                                                     * 
//* Written by      : Anthony Cantu                                     * 
//*                                                                     * 
//* Purpose         : This application will allow the user to select	*
//*		      an operation to either add, subtract, multiply,	*
//*		      or divide two fractions. The fractions are not	*
//*		      displayed at their lowest terms.                  * 
//*                                                                     * 
//* Inputs          : User makes a selection from the menu and then     * 
//*		      enters two fractions.				* 
//*                                                                     * 
//* Outputs         : Display of the menus and the calculated answer    * 
//*                                                                     * 
//* Calls           : menu();						*
//*		      validateSelection(char selection);                * 
//*		      initializeFraction(int& n1, int& d1, int& n2,	*
//*				int& d2);				*
//*		      addFraction(int n1, int d1, int n2, int d2,	*
//*				int& rN, int& rD);			*
//*		      subtractFraction(int n1, int d1, int n2, int d2,	*
//*				int& rN, int& rD);			*
//*		      divideFraction(int n1, int d1, int n2, int d2,	*
//*				int& rN, int& rD);			*
//*		      multiplyFraction(int n1, int d1, int n2, int d2,	*
//*				int& rN, int& rD);			*
//*		      validateFraction(bool num);			*
//*                                                                     * 
//* Structure       : BEGIN                                             * 
//*                        Straight line code no sub-processes          * 
//*                   STOP                                              * 
//*                        End of Program                               * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Collaboration   :							* 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//* 10/13/23      acantu 000.000.000 Initial release of program		* 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <iostream>
#include <iomanip>

//Function Prototypes
void menu();
bool validateSelection(char selection);
void initializeFraction(int& n1, int& d1, int& n2, int& d2);
void addFraction(int n1, int d1, int n2, int d2, int& rN, int& rD);
void subtractFraction(int n1, int d1, int n2, int d2, int& rN, int& rD);
void divideFraction(int n1, int d1, int n2, int d2, int& rN, int& rD);
void multiplyFraction(int n1, int d1, int n2, int d2, int& rN, int& rD);
int validateFraction(bool num);

using namespace std;

int main()
{
	char selection;	//Users input selection
	char q;

	int n1, //Numerator for first fraction
		d1, //Denominator for first fraction
		n2, //Numerator for second fraction
		d2;	//Denominator for second fraction

	int rN, //Numerator results
		rD;	//Denominator results

	do
	{
		menu();	//Display the menu

		cin >> selection;
		if (validateSelection(selection))
		{
			initializeFraction(n1, d1, n2, d2);

			switch (selection)
			{
			case '1':
				addFraction(n1, d1, n2, d2, rN, rD);
				cout << n1 << "/" << d1 << " + " << n2 << "/" << d2 << " = " << rN <<
					"/" << rD << endl;
				break;
			case '2':
				subtractFraction(n1, d1, n2, d2, rN, rD);
				cout << n1 << "/" << d1 << " - " << n2 << "/" << d2 << " = " << rN <<
					"/" << rD << endl;
				break;
			case '3':
				multiplyFraction(n1, d1, n2, d2, rN, rD);
				cout << n1 << "/" << d1 << " * " << n2 << "/" << d2 << " = " << rN <<
					"/" << rD << endl;
				break;
			case '4':
				divideFraction(n1, d1, n2, d2, rN, rD);
				cout << n1 << "/" << d1 << " / " << n2 << "/" << d2 << " = " << rN <<
					"/" << rD << endl;
				break;
			case '9':
				break;
			}
		}
		else
		{
			cout << endl << "Invalid selection!" << endl << endl;
		}
	} while (selection != '9');

	cout << "Press any key to Exit.";
	cin.ignore(2, '\n');
	cin.get(q);
	return 0;
}

void menu()
{
	cout << "This program performs operations on integer fractions. Enter:" << endl;
	cout << setfill(' ');
	cout << setw(8) << "" << left << "1 : To add fraction," << endl;
	cout << setw(8) << "" << left << "2 : To subtract fraction," << endl;
	cout << setw(8) << "" << left << "3 : To multiply fraction," << endl;
	cout << setw(8) << "" << left << "4 : To divide fraction, and" << endl;
	cout << setw(8) << "" << left << "9 : To exit the program" << endl;
}

bool validateSelection(char selection)
{
	switch (selection)
	{
	case '1':
	case '2':
	case '3':
	case '4':
	case '9':
		return true;
	default:
		return false;
	}
}

int validateFraction(bool isNumerator) //True to validate numerator, False to validate denominator
{
	int number;
	bool validInput = false;
	do
	{
		cin.clear();
		cin.ignore(2, '\n');
		cin >> number;
		if (!cin)
		{
			cout << "Enter a integer for the " << (isNumerator ? "numerator: " : "denominator: ");
			continue;
		}

		if (!isNumerator)
		{
			if (number == 0)
			{
				cout << "The denominator should not equal 0." << endl;
				cout << "Enter a integer for the " << (isNumerator ? "numerator: " : "denominator: ");
				validInput = false;
				continue;
			}
		}
		validInput = true;
	} while (!cin || !validInput);
	return number;
}

void initializeFraction(int& n1, int& d1, int& n2, int& d2)
{
	n1 = 0;
	d1 = 0;
	n2 = 0;
	d2 = 0;

	cout << "For fraction 1" << endl;
	cout << "Enter the numerator: ";
	n1 = validateFraction(true);
	cout << "Enter the denoinator: ";
	d1 = validateFraction(false);
	cout << "For fraction 2" << endl;
	cout << "Enter the numerator: ";
	n2 = validateFraction(true);
	cout << "Enter the denominator: ";
	d2 = validateFraction(false);
}

void addFraction(int n1, int d1, int n2, int d2, int& rN, int& rD)
{
	rN = (n1 * d2) + (n2 * d1);
	rD = (d1 * d2);
}

void subtractFraction(int n1, int d1, int n2, int d2, int& rN, int& rD)
{
	rN = (n1 * d2) - (n2 * d1);
	rD = (d1 * d2);
}

void multiplyFraction(int n1, int d1, int n2, int d2, int& rN, int& rD)
{
	rN = (n1 * n2);
	rD = (d1 * d2);
}

void divideFraction(int n1, int d1, int n2, int d2, int& rN, int& rD)
{
	swap(n2, d2);
	rN = (n1 * n2);
	rD = (d1 * d2);
}
