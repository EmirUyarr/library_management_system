#include"person.h"
#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<stdexcept>
#include <sstream>
using namespace std;

void person::addPerson()
{	
cout << "Enter the details for the new person:" << endl;

cout<<"Name"<<endl;
cin>>name;


cout<<"Surname"<<endl;
cin>>surname;

}
void person::removePerson(){
    cout << "Enter the name which person : ";
    cin >> rName;

}
