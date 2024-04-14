#include <bits/stdc++.h>
#include "ATM.h"
using namespace std;

int main()
{
    ATM user1(1234567, "Yogesh Saini", 1111, 41000, "8852983794"); // User Details

    while (true)
    {
        int enterPIN;                      // PIN
        long long int enterAccount_number; // Account Number
        cout << endl;
        cout << "------------------- Welcome to ATM -------------------" << endl;
        cout << endl;
        cout << "Enter Account Number : ";
        cin >> enterAccount_number; // Taking Account Number
        cout << endl;
        cout << "Enter PIN : ";
        cin >> enterPIN; // Taking PIN

        if (enterAccount_number == user1.getAccount_number() && enterPIN == user1.getPIN()) // Check User Exist or NOt
        {
            while (true)
            {
                // User Interface
                cout << endl;
                cout << "------------------- Welcome to ATM -------------------" << endl;
                cout << "Select options - " << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Withdraw Cash" << endl;
                cout << "3. Show ALL Transactions Till Now" << endl;
                cout << "4. Show User Details" << endl;
                cout << "5. Update Mobile Number" << endl;
                cout << "6. Exit" << endl;
                cout << endl;
                cout << "Enter Your Choice(1/ 2/ 3/ 4/ 5/ 6) : ";
                int choice;
                cin >> choice;
                if (choice == 1) // Check Balance
                {
                    cout << endl;
                    cout << "Your Bank Balance is : " << user1.getBalance() << endl; // Call To getBalance() function
                }
                else if (choice == 2) // Withdraw Cash
                {
                    user1.cashWithdraw(); // Call to cashWithdraw() function
                }
                else if (choice == 3) // Show ALL Transactions
                {
                    user1.PrintAllTransactions(); // Call to PrintAllTransactions() function
                }
                else if (choice == 4) // Show User Details
                {
                    cout << endl;
                    cout << "> User details are : " << endl;
                    cout << "> Name : " << user1.getName() << endl;                     // Call to getName() function
                    cout << "> Account Number : " << user1.getAccount_number() << endl; // Call to getAccount_number() function
                    cout << "> Mobile number : " << user1.getMobile_number() << endl;   // Call to getMobile_number() function
                    cout << "> Balance : " << user1.getBalance() << endl;               // Call to getBalance() function
                }
                else if (choice == 5) // Update Mobile Number
                {
                    user1.setMobile_number(); // Call to setMobile_number() function
                }
                else if (choice == 6) // EXit
                {
                    cout << endl;
                    cout << "Exiting........" << endl;
                    exit(0); // Exit From ATM
                }
                else
                {
                    cout << "Enter valid data!!" << endl;
                }
            }
        }
        else
        {
            cout << "User Not Exist!" << endl;
        }
    }
    return 0;
}
