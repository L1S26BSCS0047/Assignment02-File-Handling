/*
 * Name       : Zainab Fatima
 * Reg No     : L1S26BSCS0047
 * Assignment : 02 - File Handling
 * Question   : Q5 — Expense Tracker 
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    int choice, amount;

    char category[20], wanted[20];
    int amounts[100];
    char categories[100][20];

    do
    {
        cout << "===== Expense Tracker =====" << endl;
        cout << "1. Add an expense" << endl;
        cout << "2. Show all expenses" << endl;
        cout << "3. Show total of a category" << endl;
        cout << "4. Clear all expenses" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter category: ";
            cin >> category;

            cout << "Enter amount: ";
            cin >> amount;

            if (amount <= 0)
            {
                cout << "Invalid amount!" << endl;
            }
            else
            {
                // Add expense at the end
                ofstream file("expenses.txt", ios::app);
                file << category << " " << amount << endl;
                file.close();

                cout << "Expense saved." << endl;
            }
        }
        else if (choice == 2)
        {
            // Read all expenses again
            ifstream file("expenses.txt");
            int count = 0, total = 0;
            int largest = 0;

            while (count < 100 &&
                file >> categories[count] >> amounts[count])
            {
                total += amounts[count];

                // Keep the first largest expense
                if (count == 0 || amounts[count] > amounts[largest])
                {
                    largest = count;
                }

                count++;
            }

            file.close();

            if (count == 0)
            {
                cout << "No expenses yet." << endl;
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    cout << i + 1 << ". " << categories[i]
                        << " " << amounts[i] << endl;
                }

                cout << "Total spent: " << total << endl;
                cout << "Largest expense: " << categories[largest]
                    << " (" << amounts[largest] << ")" << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Enter category: ";
            cin >> wanted;

            // Read the file and find the category
            ifstream file("expenses.txt");
            int count = 0, total = 0;
            char cat[20];
            int amt;

            while (file >> cat >> amt)
            {
                if (strcmp(cat, wanted) == 0)
                {
                    count++;
                    total += amt;
                }
            }

            file.close();

            if (count == 0)
            {
                cout << "No expenses found for "
                    << wanted << endl;
            }
            else
            {
                cout << "Expenses in " << wanted
                    << ": " << count << endl;
                cout << "Total for " << wanted
                    << ": " << total << endl;
            }
        }
        else if (choice == 4)
        {
            // Opening without ios::app clears the file
            ofstream file("expenses.txt");
            file.close();

            cout << "All expenses cleared." << endl;
        }
        else if (choice == 5)
        {
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
