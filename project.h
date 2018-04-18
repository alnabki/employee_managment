#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;
class Project{
    public:
        string id, title, description, status;
    public:
        void enterId(){
            cout << "Enter project id: ";
            cin >> id;
        }

        /*void show(){
            cout << "id: " << id << "\t\ttitle: " << title << "\t\tdescription: " << description << "\t\tstatus: " << status << endl;
        }*/

        void show(){
            cout <<" _______________________________________________________________________________________________"<<endl;
            cout <<"|                                                                                               |"<<endl;
            cout <<"|                                         Project's details                                     |"<<endl;
            cout <<"|_______________________________________________________________________________________________|"<<endl;
            cout <<"|"<<setw(10)<<"id"<<setw(20)<<"Title"<<setw(30)<<"Description"<<setw(20)<<"Status"<<setw(16)<<"|"<<endl;
            cout <<"|"<<setw(10)<<id<<setw(20)<<title<<setw(30)<<description<<setw(20)<<status<<setw(16)<<"|"<<endl;
            cout <<"|_______________________________________________________________________________________________|"<<endl;
        }

        void enter(){
            cout << "Enter project details" << endl;
            cout << "Title: ";
            cin >> title;
            cout << "\nDescription: ";
            cin >> description;
            cout << endl;
        }

        void Add()
        {
            inbtwInsertProject();
        }

        void Delete(string id)
        {
            inbtwDeleteProject(id);
        }

        void Update()
        {
            inbtwUpdateProject();
        }
};

#endif // PROJECT_H_INCLUDED
