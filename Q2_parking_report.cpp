/*
 * Name       : Zainab Fatima
 * Reg No     : L1S26BSCS0047
 * Assignment : 02 - File Handling
 * Question   : Q2 — Parking Report
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream inFile("parking.txt");
    ofstream outFile("receipts.txt");

    if (!inFile)
    {
        cout << "parking.txt not found!";
        return 1;
    }

    int d;
     int m;
    int y;
    char slash;

    inFile >> d >> slash >> m >> slash >> y;

    inFile.ignore(100, '\n');
    inFile.ignore(100, '\n');

    cout << "Parking report " << d << "/" << m << "/" << y << endl;

    outFile << "Receipts for " << d << "/" << m << "/" << y << endl;

    char plate[15], longestPlate[15] = "";
    char type;
    char inTime[6], outTime[6];

    int vehicles = 0;
    int cars = 0, bikes = 0;
    int totalCollected = 0;
    int longestMinutes = -1;

    while (inFile >> plate >> type >> inTime >> outTime)
    {
        int inHour, inMin;
        int outHour, outMin;

        inHour = (inTime[0] - '0') * 10
            + (inTime[1] - '0');
        inMin = (inTime[3] - '0') * 10
            + (inTime[4] - '0');

        outHour = (outTime[0] - '0') * 10
            + (outTime[1] - '0');
        outMin = (outTime[3] - '0') * 10
            + (outTime[4] - '0');

        int start = inHour * 60 + inMin;
        int end = outHour * 60 + outMin;

        int minutes = end - start;

        int hoursCharged = (minutes + 59) / 60;

        if (hoursCharged == 0)
        {
            hoursCharged = 1;
        }

        int fee;

        if (type == 'C')
        {
            fee = hoursCharged * 100;
            cars++;
        }
        else
        {
            fee = hoursCharged * 40;
            bikes++;
        }

        int hours = minutes / 60;
        int remainingMinutes = minutes % 60;

        cout << plate << " ";

        if (type == 'C')
            cout << "Car ";
        else
            cout << "Bike ";

        cout << hours << " h " << remainingMinutes << " min " << "Fee: " << fee << endl;

        outFile << plate << " " << fee << endl;

        vehicles++;
        totalCollected += fee;

        if (minutes > longestMinutes)
        {
            longestMinutes = minutes;
            strcpy_s(longestPlate, plate);
        }
    }

    if (vehicles == 0)
    {
        cout << "No vehicles found!" << endl;
        outFile.close();
        return 0;
    }

    cout << "Vehicles: " << vehicles << endl;
    cout << "Cars: " << cars << " Bikes: " << bikes << endl;
    cout << "Total collected: " << totalCollected << endl;

    cout << "Longest stay: " << longestPlate  << " (" << longestMinutes / 60  << " h " << longestMinutes % 60
   << " min)" << endl;

    inFile.close();
    outFile.close();

    return 0;
}