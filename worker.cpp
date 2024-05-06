#include"worker.h"
#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<stdexcept>
#include <sstream>
using namespace std;

int izin=-1; 

void worker::addWorker()
{
	addPerson();
	workers.open("worker.txt",ios::app);
	
cout << "Enter the details for the new worker:" << endl;
  

cout<<"New Worker password"<<endl;
cin.ignore();
cin>>WorkerPassword;       


workers<<endl<<endl<< left<< setw(40) << name << setw(40) <<surname<< setw(40) << WorkerPassword;
workers.close();
}

void worker::removeWorker(){
removePerson();
    ifstream Remove("worker.txt");
    ofstream temporarys("temporarys.txt");
    while(!(Remove.eof()))
{
	Remove>> name >>surname >>WorkerPassword;
	
	if(rName == name)
	{	
	}
	else
	temporarys<<endl<<endl<<name<< setw(40) <<surname<< setw(40) << WorkerPassword;

}
Remove.close();
temporarys.close();
remove("worker.txt");
rename("temporarys.txt", "worker.txt");
}
 void worker::WorkerEntrance() {
    static int entrance = 0;
    Wentrance.open("worker.txt", ios::app);
    ifstream workerFile("worker.txt"); 
    string workerLine;
    while (getline(workerFile, workerLine)) {
        istringstream iss(workerLine);
        iss >> currentWorkerName >> currentWorkerSurname >> currentWorkerPassword;
    }
    cout << "\t\t\t Please Login" << endl;
    cout << "\t\t\t Enter Name" << endl;
    cin >> Wname;

    cout << "\t\t\t Enter Surname" << endl;
    cin >> Wsurname;

    cout << "\t\t\t Enter Password" << endl;
    cin >> WWorkerPassword;

    if (currentWorkerName == Wname && currentWorkerSurname == Wsurname && currentWorkerPassword == WWorkerPassword) {
        izin = 1;
        entrance++;
    } else {
        cout << "\t\t\t Invalid name/surname/password" << endl << endl;
        WorkerEntrance(); 
    }
    Wentrance.close();
}
void worker::workerList()
{
	 {
        	cout <<"____________________________________________________________________________________________________________"<<endl;
        	wlist();	
		}
		};	
	void worker::wlist(){
	    ifstream workers;
		string wrkrs;
		workers.open("worker.txt");
		while(getline(workers , wrkrs))
		{
			cout<<wrkrs<<endl;
		}
		workers.close();
		 };
		 