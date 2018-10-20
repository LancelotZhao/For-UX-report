//
// Created by zhaobowen on 09/03/2018.
//

#include <ctime>
#include<fstream>
#include "His.h"
#include <iostream>
using namespace std;
//needing to be consider!!!
his *record;

void historyOut() {
    ofstream fout;
    fout.open("/Users/Lancelot/Desktop/Record.txt", ios::binary);
    if (!fout.is_open()) {
        cout << "Fail to export the records!" << endl;
    } else {
        auto tmp = record;
        tmp = tmp->next;
    while (tmp != nullptr) {
        fout.write((char *) tmp, sizeof(his));
        tmp = tmp->next;
    }
        cout << "Export record successfully" << endl;
        fout.close();
    }
}

his *historyIn() {
    ifstream fin;
    fin.open("/Users/Lancelot/Desktop/Record.txt", ios::binary);
    auto tmp = record = new his;
    if (!fin.is_open()) {
        cout << "Fail to import the records!" << endl;
    } else {
        while (fin.peek() != EOF) {
            tmp->next = new his;
            tmp = tmp->next;
            fin.read((char *) tmp, sizeof(his));
        }
        cout << "Import record successfully" << endl;
        fin.close();
    }
    return record;
}

void history(string name, int account) {//adding to the parts before
    auto tmp = new his;
    tmp->current = time(nullptr);
    tmp->ID = account;
    tmp->name = name;
    tmp->next = record->next;
    record->next = tmp;
}

void showHis() {
    his *cnt = record;
    cnt = cnt->next;
    while (cnt != nullptr) {
//        cout << cnt->name << ":" << cnt->current << endl;
                auto tmp = localtime(&cnt->current);
        cout << cnt->name << " borrowed by " << cnt->ID << " at " << tmp->tm_year + 1900 << "-" << tmp->tm_mon << "-"
             << tmp->tm_mday << " "
             << tmp->tm_hour
             << ": " << tmp->tm_min << endl;//by account?
        cnt = cnt->next;
    }
}