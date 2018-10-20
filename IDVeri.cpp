//
// Created by Lancelot on 06/03/2018.
//

#include "IDVeri.h"
#include <unistd.h>
Account *headA;
int cntA = 0;
int verify() { //!!
//int verify(int ID, string Password) {
    cout << "First, please log in the system with your ID" << endl;
    while (true){
        int ID;
        string Password;
        cout << "ID: ";
        cin >> ID;
        cout << "Password: ";
        cin >> Password;
        if (ID == 0) {//needing to build a database for account info
            if (Password == "0") {
                return 0;
            } else {
                cout << "Password is wrong please try again!" << endl;
            }
        } else {
                if (checkAccount(ID, Password)) return ID;//attention
            return -1;
        }
    }
}

void createAccount() {//enter string loop ever
    auto newOne = new Account();
    cout << "Input the account name you are going to create first(Number): " << endl;
    auto i = headA;
    while (i != nullptr){
        while (!(cin >> newOne->ID)) {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "wrong! The account should be number! Please try again." << endl;
        }
        for (i = headA; i != nullptr; i = i->next) {
            if (i->ID == newOne->ID) {
                break;
            }
        }
        if (i != nullptr) {
            cout << "The account has already existed, please try another one." << endl;
        }
    }
    while (true){
        cout << "Input the password you want to set for this account: " << endl;
        cin >> newOne->Password;
        cout << "Please input the password again: " << endl;
        string temp;
        cin >> temp;
        if (newOne->Password == temp) break;
        else cout << "The password you set were not the same. Try again." << endl;
//    sleep(3);
    }
    //consider to use stack,linked list or queue,try array first
    newOne->next = headA->next;
    headA->next = newOne;
    cout << "Succeed to create a new account." << endl;
}//needing to build a database for account info

Account *Load() {
    ifstream fin("/Users/Lancelot/Desktop/AccountInfo.txt");
    auto tmp = headA = new Account;
    if (fin.fail()) {
        cout << "Fail to open the database!" << endl;
    } else {
        while (fin.peek() != EOF) {
            tmp->next = new Account;
            tmp = tmp->next;
            fin >> tmp->ID;
            fin >> tmp->Password;
            fin.get();
            cntA++;
        }
//        delete tmp;
        cout << "Loaded successfully" << endl;
    }
    return headA;
}

void ExportAccount() {
    ofstream fout("/Users/Lancelot/Desktop/AccountInfo.txt");
    if (!fout.good()) {
        cout << "Fail to export the database!" << endl;
    } else {
        auto temp = headA->next;
        while (temp) {
            fout << temp->ID << " " << temp->Password << endl;
            temp = temp->next;
        }
        cout << "Export account information successfully" << endl;
    }
}

void PasswordChange(int ID) {
    auto tmp = headA;
    std::string newOne = "qwe";
    std::string newOne_ = "asd";
//    for (int i = 0; i < cntA; ++i) {//?cntA
    while (tmp != nullptr) {
        if (tmp->ID == ID) {
            while (newOne != newOne_) {
                cout << "Please enter the new password: ";
                cin >> newOne;
                cout<< "Please enter the password again: ";
                cin >> newOne_;
            }
            tmp->Password = newOne;
        }
        tmp = tmp->next;
    }
}//waiting to be checked

bool checkAccount(int ID, std::string password){
    auto tmp = headA->next;//
//    for (int j = 0; j < cntA; ++j) {//?cntA
    while (tmp != nullptr) {
        if (tmp->ID == ID) {
            if (tmp->Password == password)
                return true;
            cout << "Password is wrong! please try again." << endl;
            return false;
        }
        tmp = tmp->next;
    }
    cout << "This account does not existed! Please try again." << endl;
        return false;
}
