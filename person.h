#ifndef PERSON_H
#define PERSON_H
#include <string>
#include<iostream>
#include<fstream>
#include <iomanip>
#include <sstream>
using namespace std;

class person {
protected:
string name;
string surname;
string rName;
public:
void addPerson();
void removePerson();


};
#endif