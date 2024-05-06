#ifndef MENU_H
#define MENU_H
#include<iostream>
#include <string>
#include "distanceshelf.h"
#include "student.h"
#include <iomanip>
#include "TSP.h"
#include "worker.h"
using namespace std;


class menu {

private:
        
    	string name;
    	string id;
    	book memberBook;
    	student studentName;
        distanceshelf distanceShelf;
        TSP tsp;
        worker Worker;
public:
   void createCustomDistancesFile();
   friend void display(menu m1);
   void generalmenu();	
   void adminmenu();
   

};
#endif
