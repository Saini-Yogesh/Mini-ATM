#include <bits/stdc++.h>
using namespace std;

string CurrentDateandTime() // gives us Current Date and Time in form of string
{
    time_t now = time(nullptr);      // getting vurrent timr
    tm *localTime = localtime(&now); // Convert now to local time
    char timeString[20];             // Format the local time as a string
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);
    return timeString; // return the time in string format
}
class ATM
{
public:
    long long int account_number;                 // Account number of user
    string name;                                  // Name of User
    int PIN;                                      // PIN of user
    double balance;                               // Bank Balence of User
    string mobile_number;                         // Mobile number of user
    vector<pair<string, double>> AllTransactions; // To Record All Transactions History

    // Constructor
    ATM(long long int account_number, string name, int PIN, double balance, string mobile_number)
    {
        this->account_number = account_number;
        this->name = name;
        this->PIN = PIN;
        this->balance = balance;
        this->mobile_number = mobile_number;
    }
    long long int getAccount_number()
    {
        return account_number;
    }
    string getName()
    {
        return name;
    }
    int getPIN()
    {
        return PIN;
    }
    double getBalance()
    {
        return balance;
    }
    string getMobile_number()
    {
        return mobile_number;
    }
    void setMobile_number()
    {
        string mob_prev, mob_new;
        cout << "Enter old mobile number : ";
        cin >> mob_prev; // Taking Previous Mobile number
        cout << "Enter new mobile number : ";
        cin >> mob_new;                // Taking New Mobile number
        if (mob_prev == mobile_number) // if Mobile Number are correct
        {
            mobile_number = mob_new; // Updating Mobile number
            cout << endl;
            cout << "Mobile Number updated successfully!!!";
            cout << endl;
        }
        else // if Mobile Number are Wrong
        {
            cout << endl;
            cout << "Incorrect old mobile number!!!" << endl;
        }
    }
    void cashWithdraw()
    {
        double amount;
        cout << "Enter the amount : ";
        cin >> amount;                      // Enter The Amount
        if (amount > 0 && amount < balance) // If amount Is Avilable In Bank
        {
            cout << endl;
            balance -= amount;                                         // Decreasing The Bank Balence By Amount
            cout << "Processing........" << endl;                      // Processing
            cout << "Please collect your cash" << endl;                // Collet Cash
            cout << "Available balance : " << balance << endl;         // Show Avilable Balence After Withdraw
            AllTransactions.push_back({CurrentDateandTime(), amount}); // Add Transactions In History
        }
        else if (amount < 0 || amount > balance) // In Case Of Invalid Input
        {
            cout << "Invalid Input!!!" << endl;
        }
        else // If Amount Is Not Avilable In Bank
        {
            cout << "Insufficient Balance!!!" << endl;
        }
    }
    void PrintAllTransactions()
    {
        if (AllTransactions.size() == 0) // If No Transication Till Now
        {
            cout << endl;
            cout << "         No Transactions Till Now!!!           " << endl;
        }
        else // If Have Transication Till Now
        {
            cout << "Date of Transactions : Amount Withdrawal" << endl;
            for (auto it : AllTransactions) // Itrating For Each Transcation
                cout << it.first << "  : " << it.second << endl;
        }
    }
};