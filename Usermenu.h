#pragma once


#include "Inclusions.cpp"
#include "Statgen.h"

class Usermenu : public Statgen
{
public:
	int menuChoice;
	char recursiveChoice;

	void menu()
	{
		cout << "What would you like to do? \n"
			<< "1. Character Stat Generator \n"
			<< "2. Dice Roller \n";

		cout << "\nChoice: ";
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			Statgen::methodChoice();
			break;

		case 2:
		{
			Diceroller::die();
			Diceroller::roller();
		}
		break;

		default:
		{
			cout << "Improper Input! \n\n" << "Try Again!" << endl;
			menu();
		}
		break;
		};

		cout << "\nWant to run the program again? (Y/N): ";
		cin >> recursiveChoice;
		cout << endl;

		if (recursiveChoice == 'y' || recursiveChoice == 'Y')
			menu();
		else if (recursiveChoice == 'n' || recursiveChoice == 'N')
		{
			cout << "Enjoy Your Day!";
			exit(EXIT_SUCCESS);
		}
	}
};