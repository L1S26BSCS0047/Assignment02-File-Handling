/*
 * Name       : Zainab Fatima
 * Reg No     : L1S26BSCS0047
 * Assignment : 02 - File Handling
 * Question   : Q3 — Scholarship List  
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char path[100];
    char name[30];
    char topName[30] = "";

    int n;
    int count = 0;
     int eligible = 0;
     double cgpa;
     double total = 0.0;
    double topCGPA = -1.0;

    ifstream inFile;
    ofstream outFile;

    cout << "Enter the file name: ";
    cin.getline(path, 100);

    inFile.open(path);

    if (!inFile)
    {
        cout << "Could not open! " << endl;
        return 0;
    }

    if (!(inFile >> n))
    {
        cout << "No students found!" << endl;
        inFile.close();
        return 0;
    }

    if (n > 30)
    {
        cout << "Too many students!" << endl;
        inFile.close();
        return 0;
    }

    inFile.ignore(100, '\n');

    outFile.open("scholarship.txt");

    for (int i = 0; i < n; i++)
    {
        if (!inFile.getline(name, 30, ','))
            break;

        if (!(inFile >> cgpa))
            break;

        inFile.ignore(100, '\n');

        cout << "[" << name << "] CGPA: "
            << cgpa << endl;

        total += cgpa;
        count++;

        if (cgpa >= 3.50)
        {
            outFile << name << "," << cgpa << endl;
            eligible++;
        }

        if (cgpa > topCGPA)
        {
            topCGPA = cgpa;
            strcpy_s(topName, name);
        }
    }

    if (count < n)
    {
        cout << "Warning: only " << count
            << " of " << n << " records found." << endl;
    }

    if (count == 0)
    {
        cout << "No students found!" << endl;
    }
    else
    {
        cout << "Students: " << count << endl;

        cout << "Average CGPA: ";
        cout.precision(6);
        cout << total / count << endl;

        cout << "Eligible for scholarship: "
            << eligible << endl;

        cout << "Top student: " << topName
            << " (" << topCGPA << ")" << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}

