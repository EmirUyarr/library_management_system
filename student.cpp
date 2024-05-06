#include"student.h"
#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<stdexcept>
#include <sstream>
#include"person.cpp"
#include "book.cpp"
using namespace std;

		void student::slist()
		{
			ifstream students;
			string line;
			students.open("students.txt");

			while(getline(students , line))
			{
				cout<<line<<endl;
			}
			students.close();
			
		}
void student::addStudent()
{
	addPerson();
	students.open("students.txt",ios::app);
	
cout << "Enter the details for the new student:" << endl;
cout<<"ID"<<endl;
cin>>id;       

students<<endl<<endl<< left<< setw(40) << name << setw(40) <<surname<< setw(40) <<id;
students.close();   
}
void student::removeStudent(){
removePerson();
    ifstream Remove("students.txt");
    ofstream temporary("temporary.txt");

    while(!(Remove.eof()))
{
	Remove>> name >>surname >>id;
    
	if(rName == name)
	{
		cout<<"student is removed"<<endl;		
	}
	else
	temporary<<endl<<endl<<name<< setw(40) <<surname<< setw(40) <<id;
}
Remove.close();
temporary.close();
remove("students.txt");
rename("temporary.txt", "students.txt");
}
void student::rentBook(book& book) {
    string rentid;
    cout << "Enter Your ID: ";
    cin >> rentid;
    ifstream studentFile("students.txt");
    string studentLine;

    while (getline(studentFile, studentLine)) {
        istringstream iss(studentLine);
        string currentName;
		string currentSurname;
		string currentId; 
        time_t now = time(0);
        tm *ltm = localtime(&now);

           
            ltm->tm_mday += 15; 
            mktime(ltm);

        int year = 1900 + ltm->tm_year;
         int month = 1 + ltm->tm_mon;
         int day = ltm->tm_mday;
        iss >> currentName >> currentSurname >> currentId;

        if (currentId == rentid) {
            string rentBookName;
            cout << "Enter the name of the book you want to rent: ";
            cin.ignore(); 
            getline(cin, rentBookName);
            ifstream bookFile("books.txt");
            string bookLine;
            ofstream tempBookFile("temp_books.txt");

            while (getline(bookFile, bookLine)) {
                istringstream issBook(bookLine);
                string currentBookName, currentWriter, currentType, currentRentable , currentCode;
                issBook >> currentBookName >> currentWriter >> currentType >> currentRentable >> currentCode;

            if (currentBookName == rentBookName) {
                    
             if (currentRentable == "Rentable") {
                     cout << "return date: " << year << "-" << month << "-" << day << endl;
                        cout << currentName << " " << currentSurname << " rented the book: " << currentBookName << endl;
                        tempBookFile << left << setw(40)<< currentBookName << setw(40) << currentWriter << setw(40) << currentType << setw(40) << "Rented" << setw(40) << currentCode <<setw(10) << year << "-" << month << "-" << day << endl;

         } else {
                        cout << "Selected book is not available for rent." << endl;
                        tempBookFile << bookLine << endl;
                    }
         } else {
               
                    tempBookFile << bookLine << endl;
                }
            }
            bookFile.close();
            tempBookFile.close();
            remove("books.txt");
            rename("temp_books.txt", "books.txt");

            break;
        }
    }

    studentFile.close();
}
void student::studentList()
{
	 {
	    	cout <<"____________________________________________________________________________________________"<<endl;
	    	cout<<"                                                                               "<<endl;
	    	cout<<"                                             STUDENT LIST                                      "<<endl;
	    	cout<<"                                                                                "<<endl;
	    	cout <<"____________________________________________________________________________________________"<<endl;
	    	cout<<"                                                                                 "<<endl;
        	cout<<"        STUDENT NAME                          STUDENT SURNAME                         ID             "<<endl;
        	cout <<"_________________________________________________________________________________________"<<endl;
        	cout <<"___________________________________________________________________________________________"<<endl;
        	cout<<endl;
        	cout<<endl;
        	slist();	
		}
		};
		