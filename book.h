
#include<iostream>
#include<string>
#ifndef BOOK
#define BOOK
#include <iomanip>
#include<fstream>
using namespace std;

class book
{
private:
string bookName;
string writerName;
string bookType;
string bookRentable;
int bookCode;
ofstream books;
public:
void bookList();
void addBook();
void removeBook();
void editRentStatus();
void print();
void print(int n);
void updateReturnedBooksToRentable();  

};
#endif
