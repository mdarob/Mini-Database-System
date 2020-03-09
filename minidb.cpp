#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

void requireEnter();
void addPerson();
void showPoeple();
void savePoepleToFile();
void loadfromFile();
void searchForPerson();
void removePerson();

// To Do's
// 1. Use class ADT
// 2. Use vector later
// 3. Implement exception handler

struct Person{
	string name;
	string surname;
	short int age; 
	string telephone;
};

short peopleInDatabase;

Person people[10];  

int main()
{
	loadfromFile();
	cout << "People In DB: " << peopleInDatabase << endl;
	char test;

	do{
		cout << "Menu" << endl;
		cout << "1.  Add Person" << endl;
		cout << "2.  Show Every Person" << endl;
		cout << "3.  Save Poeple to file" << endl;
		cout << "4.  Load poeple from file" << endl;
		cout << "5.  Search For a Person" << endl;
		cout << "6.  Remove Peorson from DB" << endl << endl;

		test = _getch();

		switch(test){
			case '1':
				addPerson();
				break;
			case '2':
				showPoeple();
				break;
			case '3':
				savePoepleToFile();
				break;
			case '4':
				loadfromFile();
				break;	
			case '5':
				searchForPerson();
				break;
			case '6':
				removePerson();
				break;
		}

		requireEnter();
		system("cls");

	} while(test != 27);

	return 0;
}

void removePerson()
{
	if(peopleInDatabase > 0)
	{
		short index;
		cout << "What person to remove? Type Index: " << endl;
		cin >> index;

	if(peopleInDatabase >= index )
	{
		for (int i=index; i< peopleInDatabase; i++)
		{
			people[i-1].name = people[i].name;
			people[i-1].surname = people[i].surname;
			people[i-1].age = people[i].age;
			people[i-1].telephone = people[i].telephone;
		}
	} else cout << "The Person does not exist" << endl;

		peopleInDatabase--;
	}
}

void searchForPerson()
{
	if(peopleInDatabase > 0){
		string name;
		cout << "Type a name to search " << endl;
		cin >> name;

		for(int i=0; i < peopleInDatabase; i++)
		{
			if(name == people[i].name)
			{
				cout << "Person Index: " << (i+1) << endl;
				cout << "Name: " << people[i].name << endl;
				cout << "Surname: " << people[i].surname << endl;
				cout << "Age: " << people[i].age << endl;
				cout << "Telephone: " << people[i].telephone << endl << endl;
			}
			else
				cout << "Person cannot be found" << endl;
		}

	} else cout << "No one in DB" << endl;
}

void loadfromFile()
{
	ifstream file("db.txt");

	if (file.is_open())
	{
		file >> peopleInDatabase;

		if (peopleInDatabase > 0)
		{
			/*for (int i = 0; i < peopleInDataBase; i++)
			{
			file >> people[i].name;
			file >> people[i].surname;
			file >> people[i].age;
			file >> people[i].telephone;
			}*/
			int i = 0;
			do
			{
				file >> people[i].name;
				file >> people[i].surname;
				file >> people[i].age;
				file >> people[i].telephone;

				i++;
			} while (!file.eof());

			cout << "People has been loaded properly. " << endl;
		}
		else
			cout << "Databse is Empty" << endl;
	}
	else
		cout << "The file database.txt doesnt exist" << endl;
}

void savePoepleToFile()
{
	ofstream file("db.txt");
	if(file.is_open()){
		file << peopleInDatabase << endl;

		for (int i=0; i<peopleInDatabase; i++)
		{
			file << people[i].name << endl;
			file << people[i].surname << endl;
			file << people[i].age << endl;
			file << people[i].telephone << endl;
		}

		file.close();
		cout << "Saved to file properly!" << endl;
	}
	else
		cout << "oops! Couldn't save to DB" << endl;
}

void showPoeple()
{
	if(peopleInDatabase > 0){
		for (int i=0; i<peopleInDatabase; i++)
		{
			cout << "Person Index: " << (i+1) << endl;
			cout << "Name: " << people[i].name << endl;
			cout << "Surname: " << people[i].surname << endl;
			cout << "Age: " << people[i].age << endl;
			cout << "Telephone: " << people[i].telephone << endl << endl;
		}
	} else
		cout << "Nothin to show from Data Base" << endl;
}

void addPerson()
{
	cout << "Type Name: ";
	cin >> people[peopleInDatabase].name;
	cout << endl;
	cout << "Type surname: ";
	cin >> people[peopleInDatabase].surname;
	cout << endl;
	cout << "Type age: ";
	cin >> people[peopleInDatabase].age;
	cout << endl;
	cout << "Type telephone: ";
	cin >> people[peopleInDatabase].telephone;
	cout << endl;

	peopleInDatabase++;
}

void requireEnter(){
	cout << "Press Enter to Conitnue..... " << endl;
	while(_getch() != 13);
}