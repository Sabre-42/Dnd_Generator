#pragma once

#include "Inclusions.cpp"

class Diceroller
{
private:
	int result;
public:
	int userInput;

	int die()
	{
		cout << "What Dice Would You Like To Roll? \n"
			<< "1. 4-sided " << " 2. 6-sided " << " 3. 8-sided "
			<< " 4. 10-sided " << "5. 12-sided " << " 6. 20-sided "
			<< " 7. 100-sided " << " 8. Percentile \n";

		cout << "Input your choice in the form of a number: ";
		cin >> userInput;

		cout << "\n";

		return userInput;
	}

	void roller()
	{
		int numOfRolls;
		random_device rd;
		mt19937 gen(rd());

		switch (die())
		{
		case 1: //d4
		{
			uniform_int_distribution<> distr(1, 4);

			cout << "How many times do you want to roll? " << endl;
			cin >> numOfRolls;

			cout << "Results: ";

			for (int n = 0; n < numOfRolls; n++)
				cout << distr(gen) << ' ';

			cout << "\n\n";
		}
		break;

		case 2: //d6
		{
			uniform_int_distribution<> distr(1, 6);

			cout << "How many times do you want to roll? " << endl;
			cin >> numOfRolls;

			cout << "Results: ";

			for (int n = 0; n < numOfRolls; n++)
				cout << distr(gen) << ' ';

			cout << "\n\n";
		}
		break;

		case 3: //d8
		{
			uniform_int_distribution<> distr(1, 8);

			cout << "How many times do you want to roll? " << endl;
			cin >> numOfRolls;

			cout << "Results: ";

			for (int n = 0; n < numOfRolls; n++)
				cout << distr(gen) << ' ';

			cout << "\n\n";
		}
		break;

		case 4: //d10
		{
			uniform_int_distribution<> distr(1, 10);

			cout << "How many times do you want to roll? " << endl;
			cin >> numOfRolls;

			cout << "Results: ";

			for (int n = 0; n < numOfRolls; n++)
				cout << distr(gen) << ' ';

			cout << "\n\n";
		}
		break;

		case 5: //d12
		{
			uniform_int_distribution<> distr(1, 12);

			cout << "How many times do you want to roll? " << endl;
			cin >> numOfRolls;

			cout << "Results: ";

			for (int n = 0; n < numOfRolls; n++)
				cout << distr(gen) << ' ';

			cout << "\n\n";
		}
		break;

		case 6: //d20
		{
			uniform_int_distribution<> distr(1, 20);

			cout << "How many times do you want to roll? " << endl;
			cin >> numOfRolls;

			cout << "Results: ";

			for (int n = 0; n < numOfRolls; n++)
				cout << distr(gen) << ' ';

			cout << "\n\n";
		}
		break;

		case 7: //d100
		{
			uniform_int_distribution<> distr(1, 100);

			cout << "How many times do you want to roll? " << endl;
			cin >> numOfRolls;

			cout << "Results: ";

			for (int n = 0; n < numOfRolls; n++)
				cout << distr(gen) << ' ';

			cout << "\n\n";
		}
		break;

		case 8: // Percentile
		{
			uniform_int_distribution<> distr(1, 100);

			cout << "Results: " << distr(gen) << "% " << "\n\n";
		}
		break;
		}
	}
};