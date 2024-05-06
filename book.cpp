#include "book.h"
#include<iostream>
#include<string>
#include <iomanip>
#include<fstream>
using namespace std;

void book::bookList()
{
	 {
	    	cout <<"                                                                                "<<endl;
	    	cout <<"_______________________________________________________________________________________________________________________________________"<<endl;
	    	cout<<"                                                                                 "<<endl;
	    	cout<<"                                                                     BOOK LIST                                      "<<endl;
	    	cout<<"                                                                            "<<endl;
	    	cout <<"_______________________________________________________________________________________________________________________________________"<<endl;
	    	cout<<"                                                                                "<<endl;
        	cout<<"  BOOK NAME                     WRITER                        BOOK GENRE                       RENT STATUS             CODE             "<<endl;
        	cout <<"_______________________________________________________________________________________________________________________________________"<<endl;
        	cout <<"____________________________________________________________________________________________________________"<<endl;
        	print();	
		}
		};
		
	void book::addBook() {
    books.open("books.txt", ios::app);

    cout << "Enter the details for the new book:" << endl;

    cout << "Name: ";
    cin.ignore();
    getline(cin, bookName);

    cout << "Writer: ";
    getline(cin, writerName);

    cout << "Type: ";
    getline(cin, bookType);

    cout << "Rent status: ";
    getline(cin, bookRentable);

	cout << "code: ";
    cin >> bookCode;

    books << endl << endl << left << setw(40) << bookName << setw(40) << writerName << setw(40) << bookType << setw(40) << bookRentable <<  setw(40) << bookCode << endl;
    books.close();
}
void book::removeBook()
{
	string name_control;
    cout << "Enter the name of the book you want to delete: ";
	cin.ignore();
    getline(cin,name_control);
    ifstream Removebook("books.txt");
    ofstream temporarybook("temporarybook.txt");
    while(!(Removebook.eof()))
{
	Removebook>> bookName >> writerName >>bookType >> bookRentable >> bookCode;
	
	if(name_control == bookName)
	{
		cout<<"book  is removed"<<endl;		
	}
	else
	temporarybook<<endl<<endl<< left << setw(40) << bookName << setw(40) << writerName << setw(40) << bookType << setw(40) << bookRentable << setw(40) << bookCode << endl;

Removebook.close(); 
temporarybook.close();

remove("books.txt");
rename("temporarybook.txt", "books.txt");
}
}

void book::editRentStatus() {
    ifstream books("books.txt");
    ofstream temporary("temporary.txt", ios::app);
    string bookDetails;
    string targetBookName;
    string newRentStatus;

    cout << "Enter the name of the book you want to edit: ";
    cin.ignore();
    getline(cin, targetBookName);

    cout << "Enter the new rent status (rentable, rented , returned): ";
    getline(cin, newRentStatus);

    bool found = false;

    while (getline(books, bookDetails)) {
        string bookName, writerName, bookType, bookRentable, bookCode;
        istringstream iss(bookDetails);
        iss >> bookName >> writerName >> bookType >> bookRentable >> bookCode;

        if (targetBookName == bookName) {
            found = true;
            cout << "Rent status of '" << bookName << "' is updated to '" << newRentStatus << "'." << endl;
            temporary  << left << setw(40) << bookName << setw(40) << writerName << setw(40) << bookType << setw(40) << newRentStatus << setw(40) << bookCode << endl;
        } else {
            temporary  << left << setw(40) << bookName << setw(40) << writerName << setw(40) << bookType << setw(40) << bookRentable << setw(40) << bookCode << endl;
        }
    }
    books.close();
    temporary.close();

    if (!found) {
        cout << "Book not found." << endl;
        remove("temporary.txt");
    } else {
        remove("books.txt");
        rename("temporary.txt", "books.txt");
    }
}
void book::print(){
        ifstream books;
			string bks;
			books.open("books.txt");
			while(getline(books , bks))
			{
				cout<<bks<<endl;
			}
			books.close();
}
void book::print(int n){
    ifstream books("books.txt");
    string bookDetails;

    cout <<"Returned Books:" << endl;
    cout <<"_______________________________________________________________________________________________________________________________________"<<endl;
    cout<<"  BOOK NAME                     WRITER                        BOOK GENRE                       RENT STATUS             CODE             "<<endl;
    cout <<"_______________________________________________________________________________________________________________________________________"<<endl;

    while (getline(books, bookDetails)) {
       
        string bookName, writerName, bookType, bookRentable, bookCode;
        istringstream iss(bookDetails);
        iss >> bookName >> writerName >> bookType >> bookRentable >> bookCode;
        if (bookRentable == "Returned") {
            cout << left << setw(30) << bookName << setw(30) << writerName << setw(30) << bookType << setw(30) << bookRentable << setw(30) << bookCode << endl;
        }
    }
    books.close();
}

void book::updateReturnedBooksToRentable() {
    ifstream books("books.txt");
    ofstream temporary("temporary.txt", ios::app);
    string bookDetails;

    while (getline(books, bookDetails)) {
        string bookName, writerName, bookType, bookRentable, bookCode;
        istringstream iss(bookDetails);
        iss >> bookName >> writerName >> bookType >> bookRentable >> bookCode;
        if (bookRentable == "Returned") {
            bookRentable = "Rentable";
            cout << "Rent status of '" << bookName << "' is updated to 'Rentable'." << endl;
        }
        temporary << left << setw(40) << bookName << setw(40) << writerName << setw(40) << bookType << setw(40) << bookRentable << setw(40) << bookCode << endl;
    }

    books.close();
    temporary.close();

    remove("books.txt");
    rename("temporary.txt", "books.txt");
}