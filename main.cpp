#include <iostream>
#include <fstream>
#include <strstream>
#include <string> 
#include <chrono>
#include <thread>
#include <vector>
#include <stdio.h>


using std::string;
using namespace std::this_thread;
using namespace std;

class Employee{
public :
    string Name;
    string Company;
    int Age;

    void GetEmployeeInfo(){
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }

    void CreateNewEmployeeRecord(){
        std::ofstream EmployeeFile;
        string FileName = "./Employees/" + Name + ".csv";
        EmployeeFile.open(FileName);
        EmployeeFile << "Id, Name, Company, Age, Description\n";
        EmployeeFile << "1, " +  Name + ", " + Company + ", " + to_string(Age) + ", First record for " + Name;
        EmployeeFile.close();

        cout << " \n [ Employee created and saved on 'Employees' folder ]\n";

        sleep_for(std::chrono::milliseconds(1000));
    }

    void AddRecord(){
        //TODO
    }

    
};

void CreateTable(){
    string tableInput;
    int file_exists;
    FILE *file;

    cout << "\n What is the Table's name?: ";
    cin >> tableInput;

    string tableName="./DB/" + tableInput + ".csv";
    const char * filename=tableName.c_str();

    file=fopen( filename,"r");
    if (file==NULL) file_exists=0;
    else {file_exists=1; fclose(file);}
    
    if(file_exists == 1){
        cout << "\n " + tableInput <<"'s table already exists\n";
        sleep_for(std::chrono::milliseconds(1000));
    } else { 
        int columns, counter;
        cout<<"\n How many columns: ";
        cin >> columns;

        vector <string> columnNames;

        for (int i = 0; i < sizeof(columns); i++)
        {
            string columnName;
            cout << " Column" + to_string(i + 1) + ":";
            cin >> columnName;
            columnNames.push_back(columnName);
        }
        
        cout<<"\n Creating a new table\n";

        std::ofstream FileName;
        FileName.open(tableName);


        
        FileName << "Id, Name, Company, Age, Description\n";
        FileName << "1, 2, 3, 4, 5";
        FileName.close();
        sleep_for(std::chrono::milliseconds(1000));
    }
}

void CreateEmployee(){
    string name;
    string company;
    int age;
    cout << "\n What is the Employee's name?: ";
    cin >> name;

    cout << " What is the Employee's company?: ";
    cin >> company;

    cout << " What is the Employee's age?: ";
    cin >> age;

    Employee newEmployee = Employee(name , company, age);
    newEmployee.CreateNewEmployeeRecord();
}

int main(){

    int command;
    bool running = true;

    cout << "\nWelcome to the employee system, please select an option and press enter\n";

    while (running) {
        cout << "\n 1 - Create new Table\n";
        cout << " 2 - Add record to exsisting employee\n";
        cout << " 3 - Add record to exsisting employee\n";
        cout << " 4 - Quit the program\n";
        cout << "\n \033[1;31m>\033[0m ";
        cin >> command;

        if(command == 1){
            CreateTable();
        }

        if(command == 2){
            CreateEmployee();
        }

        if(command == 3){
            string name;
            cout << "What is the name of the Employee?: ";
            cin >> name;
        }

        if (command == 4){
            cout << "\n Thanks for using Employee System.";
            running = false;
        }
    }
}
