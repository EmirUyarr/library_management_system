
#include<iostream>
#include<string>
#include "menu.h"
#include <iomanip>
#include "TSP.cpp"
#include "distanceshelf.cpp"
#include "worker.cpp"
#include"student.cpp"
using namespace std;

void display(menu m1)  {


m1.generalmenu();

}
	
void menu::createCustomDistancesFile() {
    distanceshelf distanceShelf;
    int selectedReyons[MAX_REYONLAR];

    cout << "Select reyons for the custom distances file (enter -1 to finish):" << endl;

    int selectedReyon;
    int index = 0;

    do {
        cout << "Enter reyon (0-" << MAX_REYONLAR - 1 << "): ";
        cin >> selectedReyon;

        if (selectedReyon >= 0 && selectedReyon < MAX_REYONLAR) {
            selectedReyons[index++] = selectedReyon;
        } else if (selectedReyon != -1) {
            cout << "Invalid reyon. Please enter a valid reyon." << endl;
        }
    } while (selectedReyon != -1);

    distanceShelf.createCustomDistancesFile(selectedReyons);
}
	  
void menu::generalmenu(){
	
	int choice;
	string adminusername;
	string adminpassword;
	static int giren=0;
		cout<<"\t\t\t\t\t _____________________________________________"<<endl;
		cout<<"\t\t\t\t\t|                                             |"<<endl;
		cout<<"\t\t\t\t\t|                    MENU                     |"<<endl;
		cout<<"\t\t\t\t\t|                                             |"<<endl;
		cout<<"\t\t\t\t\t|                                             |"<<endl;
		cout<<"\t\t\t\t\t|                                             |"<<endl;
		cout<<"\t\t\t\t\t|            PLEASE SELECT AN OPTION          |"<<endl;
		cout<<"\t\t\t\t\t|                                             |"<<endl;
		cout<<"\t\t\t\t\t|                1-BOOK LIST                  |"<<endl; 
		cout<<"\t\t\t\t\t|                2-ADMINASTOR                 |"<<endl;
		cout<<"\t\t\t\t\t|                3-BOOK RENTAL                |"<<endl;
		cout<<"\t\t\t\t\t|                4-EXIT                       |"<<endl;
		cout<<"\t\t\t\t\t|                                             |"<<endl;
		cout<<"\t\t\t\t\t|                                             |"<<endl;
		cout<<"\t\t\t\t\t|                                             |"<<endl;
		cout<<"\t\t\t\t\t|_____________________________________________|"<<endl;
		cin>>choice;
	
		switch(choice){
		
		case 1:
			{
			memberBook.print();
			 generalmenu();
				break;
			}
			
			
		case 2:
			
			Worker.WorkerEntrance();
			if(izin == 1 )
			{

				adminmenu();
			}
			else 
			{
				return generalmenu();
			}
		break;

		case 3:
		{   memberBook.bookList();
			studentName.rentBook(memberBook);
			generalmenu();
					break;	
		}
		
		

		case 4:
		
		{	
			cout<<"thank you <3";
			break;
		}	
		
		defult :
		{
			cout<<"Please select from the given options";
			}	
			
			
		}
		
	}	
		void menu::adminmenu(){
			
			int choice;
			
			cout<<"\t\t\t\t\t_____________________________________________"<<endl;
		    cout<<"\t\t\t\t\t|                                             |"<<endl;
			cout<<"\t\t\t\t\t|              ADMINASTOR MENU                |"<<endl;
			cout<<"\t\t\t\t\t|            1- Add New Book                  |"<<endl;
			cout<<"\t\t\t\t\t|            2- Remove A Book                 |"<<endl;
			cout<<"\t\t\t\t\t|            3- Change Book Rental Status     |"<<endl;
			cout<<"\t\t\t\t\t|            4- Show New Book List            |"<<endl;
			cout<<"\t\t\t\t\t|            5- Add Worker                    |"<<endl;
			cout<<"\t\t\t\t\t|            6- Remove Worker                 |"<<endl;
			cout<<"\t\t\t\t\t|            7- Worker list                   |"<<endl;
			cout<<"\t\t\t\t\t|            8- Add Student                   |"<<endl;
			cout<<"\t\t\t\t\t|            9- Remove Student                |"<<endl;
			cout<<"\t\t\t\t\t|           10- Show New Student List         |"<<endl;
			cout<<"\t\t\t\t\t|           11- Distences Variables           |"<<endl;
			cout<<"\t\t\t\t\t|           12- Placing Returned Books        |"<<endl;
			cout<<"\t\t\t\t\t|           13- Back To Main Menu             |"<<endl;
			cout<<"\t\t\t\t\t|           14- EXIT                          |"<<endl;
			cout<<"\t\t\t\t\t|                                             |"<<endl;
			cout<<"\t\t\t\t\t| ____________________________________________|"<<endl;
			cin>>choice;
			
	        switch(choice)
	    {
	    	case(1):
	
		memberBook.addBook();
		
	    
		
	    	adminmenu();
	    		break;
	    	
	    	case(2):
	    		memberBook.bookList();
	    		memberBook.removeBook();
	    		adminmenu();
	    		break;
	    	
	    	case(3):
				memberBook.bookList();
			memberBook.editRentStatus();
			generalmenu();
	    		
	    		
	    	case(4):
			memberBook.bookList();
				
				adminmenu();
				break;	
				
				
				
			case(5):
			Worker.addWorker();
			
			adminmenu();
			break;	
			
			case(6):
			Worker.workerList();
			Worker.removeWorker();
			adminmenu();
			break;


			case(7):
			Worker.workerList();
			
			adminmenu();
			break;


			case(8):
	

			studentName.addStudent();
			adminmenu();
			break;
			
			
			case(9):
			studentName.slist();
			studentName.removeStudent();
			adminmenu();
			break;
			case(10):
			studentName.studentList();
			adminmenu();

			
			case(11):
			distanceShelf.createDistancesFile();
			cout << "Distances entered and saved in distances.txt" << endl;
			adminmenu();
			break;
			
			case(12):
			memberBook.print(choice);
			createCustomDistancesFile();
			tsp.updateDistances();
			tsp.printDistancesTable();
			tsp.printShortestTour();
			memberBook.updateReturnedBooksToRentable();
			adminmenu();
			break;	

            case(13):
            izin=-1;
            generalmenu();
			break;

	    	case(14):
				
			
				break;
				cout<<"thank you ";
				
			defult :
				{
					cout<<"Please selecet from the given options";
				}
		   
	}
	
};

	
	
	


