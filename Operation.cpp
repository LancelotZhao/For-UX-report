//
// Created by Lancelot on 09/03/2018.
//

#include <iomanip>
#include "Operation.h"
#include "Store.h"
#include "His.h"
using namespace std;
void administrator() {
    bool cmd = true;
    clear();
    while (cmd) {
        cout << "----------------------------------------------------" << endl;
        cout << "| Hello, dear administrator!                       |" << endl;
        cout << "| Now, please choose the command that you need.    |"<< endl;
        cout << "| A: add new books to the database.                |" << endl;
        cout << "| E: edit the info of the existing books.          |" << endl;
        cout << "| M: manage the guests' accounts.                  |" << endl;
        cout << "| S: show books.                                   |" << endl;
        cout << "| H: show history.                                 |" << endl;
        cout << "| D: delete the useless books.                     |" << endl;
        cout << "| C: change the password.                          |" << endl;
        cout << "| Q: sign out this account.                        |" << endl;
        cout << "----------------------------------------------------" << endl;
        char operation;
        cin >> operation;
        switch (operation) {
            default:
                cout << "Invalid input!please try again." << endl;
                break;
            case 'A':
                newBooks();
                break;
            case 'E':
                editInfo();
                break;
            case 'M':
                manageAccount();
                break;
            case 'S':
                showBooks();
                break;
            case 'H':
                showHis();
                break;
            case 'D': {
                cout << "Please enter the name of the book you want to delete: ";
                string name;
                cin >> name;
                deleting(name);
                break;
            }
            case 'C':
            {
                cout << "please enter your account: ";
                int tmp;
                cin >> tmp;
                PasswordChange(tmp);
                break;
            }
            case 'Q':
            {
                cmd = false;
                break;
            }
        }
    }
}

void guest(int account) {
    char operation;
    bool cmd = true;
    clear();
    while(cmd) {
        cout << "----------------------------------------------------" << endl;
        cout << "| Hello, dear ";
        cout.width(37);
        cout << setiosflags(ios::left) << account << "|" << endl;
        cout << "| Now, please choose the command that you need.    |" << endl;
        cout << "| B: borrow books                                  |" << endl;
        cout << "| C: change the password.                          |" << endl;
        cout << "| R: return books                                  |" << endl;
        cout << "| F: search books                                  |" << endl;
        cout << "| Q: sign out this account.                        |" << endl;
        cout << "----------------------------------------------------" << endl;
        cin >> operation;
        switch (operation) {
            default:
                cout << "Invalid input!please try again." << endl;
                break;
            case 'F'://finding books
            {
                string name;
                cout << "Please enter the name of the book you are finding: ";
                cin >> name;
                Info * result = search(name);
                if (result == nullptr) {
                    cout << "The book you are searching does not exist." << endl;
                } else {
                    cout << "Do you want to borrow this book?" << endl;
                    borrowing(name, account);
                }
                break;
            }
            case 'C': {
                PasswordChange(account);
                break;
            }
            case 'R'://returning books
                returning(account);
                break;
            case 'B': {//borrowing books
                cout << "Please enter the name of the book you are finding: ";
                string find;
                cin >> find;
                borrowing(find, account);
                break;
            }
            case 'Q':
            {
                cmd = false;
                break;
            }
        }
    }
}

void returning(int ID) {
    string name;
    cout << "Please enter the name of the book you borrowed: ";
    cin >> name;
    Info *borrowed = search(name);
    if (borrowed != nullptr) {
        borrowed->status++;
        auto cnt = record;
        while (cnt->next != nullptr) {
            if (cnt->next->ID == ID && cnt->next->name == name) {
                his *tmp = cnt->next->next;
                delete (cnt->next);
                cnt->next = tmp;
                break;
            }
            cnt = cnt->next;
        }
    } else {
        cout << "The book doesn't exist. Please check the name." << endl;
    }
}

void borrowing(string name, int account) {
    auto result = search(name);
    if (result == nullptr) cout << "This book does not exist!" << endl;
    else {
        cout << "Name: " <<result->Name << endl;
        cout << "Author: " << result->Author << endl;
        cout << "Press: " << result->Press << endl;
        cout << "Status: " << result->status << endl;
        cout << "Enter Y for borrowing or N for not: ";
        char status;
        cin >> status;
        if (status == 'Y') {
            if (result->status > 0) {
                result->status--;
            } else {
                cout << "All of the books has been borrowed. Please choose another one." << endl;
                return;
            }
            history(name, account);
        }
        if (status == 'N') return;
    }
}

void deleting(string name) {
    Info *result = nullptr;
    for (Info *check = headInfo; check->next != nullptr; check = check->next) {
        if (check->next->Name == name) {
            cout << "Are you sure you want to delete the information of this book?" << endl;
            cout << "Enter Y for delete or N for not: ";
            char sure;
            cin >> sure;
            if (sure == 'Y') {
                auto tmp = check->next->next;
                delete check->next;
                result = check->next = tmp;
                break;
            }
            if (sure == 'N') return;
        }
    }
    if (result == nullptr) {
        cout << "The book doesn't exist.! Please check the name." << endl;
    }

}

void manageAccount() {//attention!!!
    auto tmp = headA->next;
    for (int i = 0; tmp != nullptr; ++i) {
        cout << i << ":" << tmp->ID << " " << tmp->Password << endl;
        tmp = tmp->next;
    }
    cout << "Which one do you want to delete(enter 0 to quit)?" << endl;
    int account;
    cin >> account;
    if (account == 0) return;
    Account *result = nullptr;
    for (auto check = headA; check != nullptr; check = check->next) {
        if (check->next->ID == account) {
            cout << "Are you sure you want to delete this account?" << endl;
            cout << "Enter Y for delete or N for not: ";
            char sure;
            cin >> sure;
            if (sure == 'Y') {
                auto tmp = check->next->next;
                delete check->next;
                result = check->next = tmp;
                break;
            }
            if (sure == 'N') return;
        }
    }
    if (result == nullptr) {
        cout << "The account doesn't exist.! Please check the ID." << endl;
    }

}

void showBooks(){
    auto tmp = headInfo->next;
    for (int i = 0; tmp!= nullptr; ++i) {
        cout << i << " Name: " << tmp->Name << " Author: " << tmp->Author << " Press: " << tmp->Press << " Status: "
             << tmp->status << endl;
        tmp = tmp->next;//if() break;
    }
}

void clear() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<< endl;
}