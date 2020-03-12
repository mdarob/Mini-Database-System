#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <string>

// remove function does not work

using namespace std;

short int peopleInDatabase = 0;

class Person
{
    private:
        string name;
        string surname;
        short int age;
        string telephone;
    public:
        Person(){
            name = " ";
            surname = " ";
            age = 0;
            telephone = " "; 
        }
      
        Person(string name, string surname, short int age, string telephone){
            this->name = name;
            this->surname = surname;
            this->age = age;
            this->telephone = telephone; 
            peopleInDatabase = peopleInDatabase + 1;
            
            //showPoeple();
        }
        
        void savePoepleToFile()
        {
            ofstream file;
            //file.open("db.txt", ios_base::app);
            file.open("db.txt");
        	if(file.is_open())
        	{
        		file << peopleInDatabase << endl;
    			file << getName() << endl;
    			file << getSurname() << endl;
    			file << getAge() << endl;
    			file << getTelephone() << endl;

        		file.close();
        		cout << "Saved to file properly!" << endl;
        	}
        	else
        		cout << "oops! Couldn't save to DB" << endl;
        }
        
        void searchForPerson(string name)
        {
        	if(peopleInDatabase > 0){
        		for(int i=0; i < peopleInDatabase; i++)
        		{
        			if(name == this->name) // this-> is the hidden object
        			{
        			  cout << "Name Found!" << endl;
        				cout << "Person Index: " << (i+1) << endl;
        				cout << "Name: " << name << endl;
        				cout << "Surname: " << surname << endl;
        				cout << "Age: " << age << endl;
        				cout << "Telephone: " << telephone << endl << endl;
        			}
        			else
        				cout << "ERR, Person cannot be found" << endl;
        		}
        
        	} else 
        	    cout << "No one in DB" << endl;
        }
        
        
        void showPoeple()
        {
        	if(peopleInDatabase > 0){
        		//for (int i=0; i<peopleInDatabase; i++)
        		//{
        			//cout << "Person Index: " << (i+1) << endl;
    				cout << "Name: " << getName() << endl;
    				cout << "Surname: " << getSurname() << endl;
    				cout << "Age: " << getAge() << endl;
    				cout << "Telephone: " << getTelephone() << endl << endl;
        		//}
        	} else
        		cout << "Nothin to show from Data Base" << endl;
        }
        
        // This function does not work
        void removePerson(int index)
        {
            Person people[10];
            if(peopleInDatabase > 0)
        	{
        	    if(peopleInDatabase >= index)
        	    {
        	        for (int i=index; i<peopleInDatabase; i++)
        	        {
        	            people[i-1].name = people[i].name;
        	            people[i-1].surname = people[i].surname;
        	            people[i-1].age = people[i].age;
        	            people[i-1].telephone = people[i].telephone;
        	        }
        	    }
                
                //override the old list and push this new people list
                savePoepleToFile();
                
    		    peopleInDatabase--;
    	    }       	
        }   
        
        
        void loadfromFile()
        {
        	ifstream file("db.txt");
        
        	if (file.is_open())
        	{
        		file >> peopleInDatabase;
        
        		if (peopleInDatabase > 0)
        		{
        			for (int i = 0; i < peopleInDatabase; i++)
        			{
            			file >> name;
            			file >> surname;
            			file >> age;
            			file >> telephone;
        			}
        
        			cout << "People has been loaded properly. " << endl;
        		}
        		else
        			cout << "Databse is Empty" << endl;
        	}
        	else
        		cout << "The file db.txt doesn't exist" << endl;
        }              
        
        string getName(){
            return name;
        }
        string getSurname(){
            return surname;
        }
        short int getAge(){
            return age;
        }
        string getTelephone(){
            return telephone;
        }
};

int main()
{
    Person people("John", "Oliver", 78, "1233411");
    Person people2("Ted", "Cruz", 72, "54564564");
    
    people.savePoepleToFile();
    //people.showPoeple();
    //people.loadfromFile();
    
    people2.savePoepleToFile();
    //people2.showPoeple();
    //people2.loadfromFile();
    people2.removePerson(1);
    
}
