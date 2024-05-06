#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include<iostream>
#include"book.h"
#include<fstream>
#include <iomanip>
#include <sstream>
#include"person.h"
using namespace std;

class student : public person {
public:
    void rentBook(book& book);
	void setStudentID(int id );
    int getStudentID();
	void studentList();
	void slist();
	void addStudent();
	void removeStudent();
private:
    int id;
	ofstream students;
};
#endif

