#include <iostream>
#include <string>
#include <login.h>
#include <iomanip>

using namespace std;



void manageEmployeeMenu(){
    int choice;
    cout << "==========================================" <<endl;
    cout << right << setw(25) << "Manage Employee" <<endl;
    cout << "==========================================" <<endl;
    cout << endl;
    cout << " 1. Add Employee" << endl;
    cout << " 2. Update Employee" << endl;
    cout << " 3. Delete Employee" << endl;
    cout << " 4. Show All Employees" << endl;
    cout << " 5. Sign Employee as admin" << endl;
    cout << " 6. Back" << endl;
    cout << " \n Enter your choice(1-6):";
    cin >> choice;
    switch(choice){
        case 1:cout << " 1. Add Employee" << endl;break;
        case 2:break;
        case 3:break;
        case 4:break;
        case 5:break;
        case 6:break;
    }


}

void employeeMenu(){
    int choice;
    cout << "==========================================" <<endl;
   cout << right << setw(25) << "Hello Employee" <<endl;
   cout << "==========================================" <<endl;
   cout << endl;
   cout << " 1. START" << endl;
   cout << " 2. PAUSE" << endl;
   cout << " 3. FINISH" << endl;
   cout << " 4. MANAGE TIMEOFF" << endl;
   cout << " 5. LOGOUT" << endl;
   cout << " \n Enter your choice(1-5):";
   cin >> choice;
   switch(choice){
        case 1:cout << " 1. START" << endl;break;
        case 2:cout << " 2. PAUSE" << endl;break;
        case 3:cout << " 3. FINISH" << endl;break;
        case 4:cout << " 4. MANAGE TIMEOFF" << endl;break;
        case 5:cout << " 5. LOGOUT" << endl;break;
   }
 }


 int main()
{
 manageEmployeeMenu();



    return 0;
}
