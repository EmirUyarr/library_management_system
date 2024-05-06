#pragma once
#ifndef WORKER_H
#define WORKER_H
#include <string>
#include<iostream>
#include<fstream>
#include <iomanip>
#include <sstream>
using namespace std;

class worker : public person {
public:
	void setPhoneNumber();
    int getPhoneNumber();
	void addWorker();
	void removeWorker(); 
    void WorkerEntrance();
    void workerList();
    void wlist();
private:
    int WorkerPassword;
	ofstream workers;
    string currentName;
	ofstream Wentrance;
    string currentWorkerName;
    string currentWorkerSurname;
    int currentWorkerPassword;
    string Wname;
    string Wsurname;
    int WWorkerPassword;
};

#endif

