#pragma once

#include "Inclusions.cpp"
#include "Diceroller.h"


class Statgen : public virtual Diceroller
{
public:

	int stat1, stat2, stat3, stat4, stat5, stat6;
	int stat;
	int roll1, roll2, roll3, roll4;
	vector<int>totalRoll;

	int methodChoice()
	{
		cout << "\nChoose method of rolling character stats: \n"
			<< "Method 1 - 4d6 drop lowest \n"
			<< "Method 2 - 4d6 drop lowest - reroll 1's \n"
			<< "Method 3 - 3d6 - No Mulligan \n"
			<< "Method 4 - 3d6 - Reroll 1's \n"
			<< "Method 5 - 2d6 + 6 \n";

		cout << "input your choice as an integer: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			stat1 = method1();
			stat2 = method1();
			stat3 = method1();
			stat4 = method1();
			stat5 = method1();
			stat6 = method1();

			cout << "\n\nMethod: 4d6 drop lowest \n\n"
				<< "Strength: " << stat1 << endl
				<< "Dexterity: " << stat2 << endl
				<< "Constitution: " << stat3 << endl
				<< "Intelligence: " << stat4 << endl
				<< "Wisdom: " << stat5 << endl
				<< "Charisma: " << stat6 << endl;
		}
		break;

		case 2:
		{
			stat1 = method2();
			stat2 = method2();
			stat3 = method2();
			stat4 = method2();
			stat5 = method2();
			stat6 = method2();

			cout << "\n\nMethod: 4d6 drop lowest - reroll 1's \n\n"
				<< "Strength: " << stat1 << endl
				<< "Dexterity: " << stat2 << endl
				<< "Constitution: " << stat3 << endl
				<< "Intelligence: " << stat4 << endl
				<< "Wisdom: " << stat5 << endl
				<< "Charisma: " << stat6 << endl;
		}
		break;

		case 3:
		{
			stat1 = method3();
			stat2 = method3();
			stat3 = method3();
			stat4 = method3();
			stat5 = method3();
			stat6 = method3();
			
			cout << "\n\nMethod: 3d6 - No Mulligan \n\n";

			allocation(stat1, stat2, stat3, stat4, stat5, stat6);
		}
		break;

		case 4:
		{
			stat1 = method4();
			stat2 = method4();
			stat3 = method4();
			stat4 = method4();
			stat5 = method4();
			stat6 = method4();

			cout << "\n\nMethod: 3d6 - Reroll 1's\n\n"
				<< "Strength: " << stat1 << endl
				<< "Dexterity: " << stat2 << endl
				<< "Constitution: " << stat3 << endl
				<< "Intelligence: " << stat4 << endl
				<< "Wisdom: " << stat5 << endl
				<< "Charisma: " << stat6 << endl;
		}
		break;

		case 5:
		{
			stat1 = method5();
			stat2 = method5();
			stat3 = method5();
			stat4 = method5();
			stat5 = method5();
			stat6 = method5();

			cout << "\n\nMethod: 2d6 + 6\n\n"
				<< "Strength: " << stat1 << endl
				<< "Dexterity: " << stat2 << endl
				<< "Constitution: " << stat3 << endl
				<< "Intelligence: " << stat4 << endl
				<< "Wisdom: " << stat5 << endl
				<< "Charisma: " << stat6 << endl;
		}
		break;
		}

		return NULL;
	}

	int method1() // 4d6 - Drop lowest
	{
		char filename[MAX_PATH];

		GetModuleFileNameA(nullptr, filename, sizeof(filename));

		string filepath;

		filepath = filename;
		filepath = filepath.erase(filepath.find_last_of('\\'));

		ofstream datafile;
		datafile.open(filepath + "/output.txt", ios::out);

		for (int i = 0; i < 3; i++)
		{
			int* ptr1 = &roll1;
			int* ptr2 = &roll2;
			int* ptr3 = &roll3;
			int* ptr4 = &roll4;

			if (datafile.is_open())
			{
				random_device rd;
				mt19937 gen(rd());
				uniform_int_distribution<> distr(1, 6);

				*ptr1 = distr(gen);
				*ptr2 = distr(gen);
				*ptr3 = distr(gen);
				*ptr4 = distr(gen);

				totalRoll.push_back(*ptr1);
				totalRoll.push_back(*ptr2);
				totalRoll.push_back(*ptr3);
				totalRoll.push_back(*ptr4);

				cout << "\nInitial Roll: ";
				for (int j = 0; j < totalRoll.size(); j++)
					cout << totalRoll.at(j) << ' ';
				cout << "\n";

				datafile << "\nInitial Vector: ";
				for (int k = 0; k < totalRoll.size(); k++)
					datafile << totalRoll.at(k) << endl;
				datafile << "\n";

				auto m = min_element(totalRoll.begin(), totalRoll.end());
				totalRoll.erase(m);

				cout << "Dropped Lowest Roll: ";
				for (int i = 0; i < totalRoll.size(); i++)
					cout << totalRoll.at(i) << ' ';
				cout << "\n";

				datafile << "Editted Vector: ";
				for (int i = 0; i < totalRoll.size(); i++)
					datafile << totalRoll.at(i) << ' ';
				datafile << "\n";

				stat = accumulate(totalRoll.begin(), totalRoll.end(), decltype(totalRoll)::value_type(0));

				cout << "Final Stat: " << stat << endl;
				datafile << "Final Stat: " << stat << endl;

			}
			else
			{
				cout << "Failed to open data file\n";
				cout << "Exiting program";

				exit(1);
			}

			ptr1 = nullptr;
			ptr2 = nullptr;
			ptr3 = nullptr;
			ptr4 = nullptr;

			delete ptr1;
			delete ptr2;
			delete ptr3;
			delete ptr4;

			totalRoll.erase(totalRoll.begin(), totalRoll.end());
		}

		datafile.close();

		return stat;
	}

	int method2() // 4d6 - Drop Lowest - Reroll 1's
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distr(1, 6);

		roll1 = distr(gen);
		roll2 = distr(gen);
		roll3 = distr(gen);
		roll4 = distr(gen);

		totalRoll.push_back(roll1);
		totalRoll.push_back(roll2);
		totalRoll.push_back(roll3);
		totalRoll.push_back(roll4);

		cout << "\nInitial Roll: ";
		for (int i = 0; i < totalRoll.size(); i++)
			cout << totalRoll.at(i) << ' ';
		cout << "\n";

		if (roll1 == 1)
			replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen));
		if (roll2 == 1)
			replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen));
		if (roll3 == 1)
			replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen));
		if (roll4 == 1)
			replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen));

		cout << "Rerolled 1's: ";
		for (int j = 0; j < totalRoll.size(); j++)
			cout << totalRoll.at(j) << ' ';
		cout << "\n";

		auto m = min_element(totalRoll.begin(), totalRoll.end());
		totalRoll.erase(m);

		cout << "Dropped Lowest Roll: ";
		for (int k = 0; k < totalRoll.size(); k++)
			cout << totalRoll.at(k) << ' ';
		cout << "\n";

		stat = accumulate(totalRoll.begin(), totalRoll.end(), decltype(totalRoll)::value_type(0));
		cout << "Final Stat: " << stat;

		totalRoll.erase(totalRoll.begin(), totalRoll.end());

		return stat;
	}

	int method3()
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distr(1, 6);

		roll1 = distr(gen);
		roll2 = distr(gen);
		roll3 = distr(gen);

		totalRoll.push_back(roll1);
		totalRoll.push_back(roll2);
		totalRoll.push_back(roll3);
		
		cout << "\nInitial Roll: ";
		for (int i = 0; i < totalRoll.size(); i++)
			cout << totalRoll.at(i) << ' ';
		cout << "\n";

		stat = accumulate(totalRoll.begin(), totalRoll.end(), decltype(totalRoll)::value_type(0));

		cout << "Final Stat: " << stat;

		totalRoll.erase(totalRoll.begin(), totalRoll.end());

		return stat;
	}

	int method4()
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distr(1, 6);

		roll1 = distr(gen);
		roll2 = distr(gen);
		roll3 = distr(gen);

		totalRoll.push_back(roll1);
		totalRoll.push_back(roll2);
		totalRoll.push_back(roll3);

		cout << "\nInitial Roll: ";
		for (int i = 0; i < totalRoll.size(); i++)
			cout << totalRoll.at(i) << ' ';
		cout << "\n";

		if (roll1 == 1)
		{
			replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen));
		}

		if (roll2 == 1)
		{
			replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen));
		}

		if (roll3 == 1)
		{
			replace(totalRoll.begin(), totalRoll.end(), 1, distr(gen));
		}

		cout << "Reroll 1's: ";
		for (int i = 0; i < totalRoll.size(); i++)
			cout << totalRoll.at(i) << ' ';
		cout << "\n";

		stat = accumulate(totalRoll.begin(), totalRoll.end(),
			decltype(totalRoll)::value_type(0));

		cout << "Final Stat: " << stat;

		totalRoll.erase(totalRoll.begin(), totalRoll.end());

		return stat;
	}

	int method5()
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distr(1, 6);

		roll1 = distr(gen);
		roll2 = distr(gen);
		roll3 = 6;

		totalRoll.push_back(roll1);
		totalRoll.push_back(roll2);

		cout << "\nInitial Roll: ";
		for (int i = 0; i < totalRoll.size(); i++)
			cout << totalRoll.at(i) << ' ';
		cout << "\n";

		totalRoll.push_back(roll3);

		cout << "Adding 6 to the rolls: ";
		for (int i = 0; i < totalRoll.size(); i++)
			cout << totalRoll.at(i) << ' ';
		cout << "\n";

		stat = accumulate(totalRoll.begin(), totalRoll.end(),
			decltype(totalRoll)::value_type(0));

		cout << "Final Stat: " << stat;

		totalRoll.erase(totalRoll.begin(), totalRoll.end());

		return stat;
	}

	int allocation(int stat1, int stat2, int stat3, int stat4, int stat5, int stat6)
	{
		//int strength, dexterity, constitution, intelligence, wisdom, charisma;
		vector<int> arr;

		arr.push_back(stat1);
		arr.push_back(stat2);
		arr.push_back(stat3);
		arr.push_back(stat4);
		arr.push_back(stat5);
		arr.push_back(stat6);
		
		cout << "\n"
			 << "Here are all of the rolls made: ";

		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr.at(i) << " ";
		}

		cout << "\nHow would you like to allocate them?\n";

		return EXIT_SUCCESS;
	}
};