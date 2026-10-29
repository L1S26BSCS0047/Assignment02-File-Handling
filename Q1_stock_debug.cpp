ss/*
 * Name       : Zainab Fatima
 * Reg No     : L1S26BSCS0047
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

#include <iostream>
//FIX 1:fstream is header file for file handling 
#include <fstream>
using namespace std;
int main() {
    ifstream inFile("stock.txt");
    //FIX 2:the program prints "stock.txt not found!" so we use (!inFile)
    if (!inFile) {
        cout << "stock.txt not found!" << endl;
        return 1;
    }
    //FIX 3: ios::app means new data added at the end of file so old data remains safe
    ofstream reorder("reorder.txt", ios :: app);

    char code[10];
    int qty, count = 0, low = 0;
    double price;
    //FIX 4:int total changed to double because qty * price gives a decimal value 
    double total = 0;
    //FIX 5:infile.ignore is used to skip the header line
    inFile.ignore(100, '\n');

    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {
    //FIX 6:endl is added because we print one item per line
            reorder << code << " " << qty << endl;
            low++;
        }
    }
    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;
    return 0;
}
