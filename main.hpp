#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int writeFile(const string& filename)
{
ofstream outFile("employee.txt");
int numEmployees, id;
string name, department;
double salary, total = 0;

cout << "Number of employees: ";
cin >> numEmployees;
outFile << numEmployees << endl;

for (int i = 0; i< numEmployees; i++){
    cout << "ID, Name, Department, Salary: ";
    cin >> id >> name >> department >> salary;
    outFile << id << " " << name << " " << department << " " << salary << endl;
}

outFile.close();
return numEmployees;
}

int readFile(const string& filename){
    ifstream inFile("employee.txt");
    int numEmployees, id;
    string name, department;
    double salary, total = 0;

    inFile >> numEmployees;

    cout << "\n | ID | Name | Department | Salary |" << endl;
    cout << "|-------|------|------------|--------|" << endl;

    for (int i = 0; i < numEmployees; i++){
        inFile >> id >> name >> department >> salary;
        total += salary;
        cout << "|" << setw(8) << left << id
            << "|" << setw(7) << name
            << "|" << setw(10) << department
            << "|" << setw(9) << salary << "|" << endl;
    }

    cout << "\nTotal employees: " << numEmployees << endl;
    cout << "average salary: " << (total / numEmployees) << endl;

    inFile.close();
    return numEmployees;
}

