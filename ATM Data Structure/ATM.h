#ifndef ATM_H_INCLUDED
#define ATM_H_INCLUDED

#include <iostream>
class ATM
{
public:
    ATM();


    //Accessors
    int getBalance() const;


    //Mutator
    void setBalance(float balance);
    //Operations
    void SetAcc();
    void ShowAcc();
    void deposit();
    void withdraw();
    std::string display();

    ~ATM();

private:
    int accNum;
    float balance;
    std::string name;
    double dblWithdraw;
    double dblDeposit;
};

#endif // ATM_H_INCLUDED
