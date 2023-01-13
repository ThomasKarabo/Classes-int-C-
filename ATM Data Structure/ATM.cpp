#include "ATM.h"

using namespace std;

ATM::ATM(){}


int ATM::getBalance() const
{
    return balance;
}

void ATM::SetAcc()
{
    cout << "Please enter your name: ";
    cin.ignore();
    getline(cin, name);

    cout<< "Please enter Account Number: ";
    cin>>accNum;

    cout <<"Please enter balance: R";
    cin>>balance;
}

void ATM::ShowAcc()
{
    cout << "Your name is: " << name<<endl;
    cout <<"Your balance is: R" << balance <<endl;
    cout << "Your account number is: " << accNum << endl;
}

void ATM::deposit()
{
    cout << "Please enter amount you wish to deposit: R";
    cin>>dblDeposit;
    balance = balance + dblDeposit;
    cout << "You have deposited: R" <<balance << endl;
}

void ATM::withdraw()
{
    cout << "Please enter amount you wish to Withdraw: R";
    cin>>dblWithdraw;
    balance = balance - dblWithdraw;
    cout << "You have withdrew: R" <<balance << endl;
}

string ATM::display()
{
     cout << "Hi, please select the options below." << endl;
    cout <<"***************************************************" <<endl;
    cout <<"***************************************************" <<endl;
    cout <<"1.SET YOUR ACCOUNT\n"<<
         "2.SHOW YOUR ACCOUNT\n"<<
         "3.DEPOSIT CASH\n" <<
         "4. WITHDRAW CASH" <<endl;
    cout <<"***************************************************" <<endl;
    cout <<"***************************************************\n" <<endl;
}

ATM::~ATM(){}
