#include "ATM.h"
#include <stdlib.h>

using namespace std;

int main()
{

    ATM bankAcc;
    int select;
    while(1)
    {
        bankAcc.display();

        cin>>select;

        switch(select)
        {
           case 1:
            bankAcc.SetAcc();
            break;

        case 2:
            bankAcc.ShowAcc();
            break;

        case 3:
            bankAcc.deposit();
            break;

        case 4:
            bankAcc.withdraw();
            break;

        case 5:
            exit(1);
            break;

        default:
            cout << "Invalid choice, please choose again\n";
            break;

        }



    }


    return 0;
}


