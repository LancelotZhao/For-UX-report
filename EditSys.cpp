//
// Created by Lancelot on 06/03/2018.
//

#include "EditSys.h"
#include "IDVeri.h"
using std::cout;
using std::cin;
using std::endl;
void editInfo() {
    cout << "Please enter the name of the book that you want to edit: ";
    std::string name;
    cin >> name;
    Info *tmp = search(name);
    if (tmp != nullptr) {
        cout << tmp->Name << endl;
        cout << tmp->Author << endl;
        cout << tmp->Press << endl;
        cout << "Press E again to edit the info" << endl;
        char instruction;
        cin >> instruction;
        if (instruction == 'E') {
            cout << "Name: ";
            cin >> tmp->Name;
            cout << "Author: ";
            cin >> tmp->Author;
            cout << "Press: ";
            cin >> tmp->Press;
            cout << "Status: ";
            cin >> tmp->status;
            cout << "Succeed to change the information" << endl;
        }
        else return;
    } else {
        cout << "The book you want to edit doesn't exist in the system. Fail to change!" << endl;
        cot << "This is " << end;
    }
}
