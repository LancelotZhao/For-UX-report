#include <iostream>
#include "IDVeri.h"
#include "His.h"
//#include "Store.h"
using namespace std;
int main() {
//    int ID;
//    string Password;
    //The name of root account is 000000 and the default password is 00000000
    bool Loaded = true;
    Account *test = nullptr;
    Info *test2 = nullptr;
    his *test3 = nullptr;
    while (true){
        int first;
        clear();
        cout << "----------------------------------------------------" << endl;
        cout << "| Enter 1 for Log In                               |" << endl;
        cout << "| Enter 2 for Create a new account                 |" << endl;
        cout << "| Enter 0 for Power off the system                 |" << endl;
        cout << "----------------------------------------------------" << endl;
        if (Loaded) {
            test = Load();
            test2 = Import();
            test3 = historyIn();
            Loaded = false;
        }
        cin >> first;
    if (first == 1) {
        int AccountType;
        AccountType = verify();
        if (AccountType == 0) administrator();
        else if (AccountType == -1) cout << "Invalid account!" << endl;
        else {
//            cout << "Hello, " << AccountType << endl;
            guest(AccountType);
        }
    } else if (first == 2) createAccount();
    else if (first == 0) {
        ExportAccount();
        Export();
        historyOut();
        break;
    }
    else cout << "Wrong Command! Try again!" << endl;
}

    return 0;
}

/*
If the database is too huge, maybe the methods of OOP may occupy too much space in main memory thinking...
 add: the time for books borrowed should be set!!!
 the number of one kind may be store as an attribute in the struct!!
 */