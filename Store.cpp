//
// Created by Lancelot on 06/03/2018.
//

#include "Store.h"
Info *headInfo;
int cntI = 0;
void Export() {
    ofstream fout;
    fout.open("/Users/Lancelot/Desktop/LibraryInfo.txt", ios::binary);
    if (!fout.good()) {
        cout << "Fail to export the database!" << endl;
    }
    else {
        auto memo = headInfo;
        memo = headInfo->next;
        while (memo != nullptr) {
            fout.write((char *)memo, sizeof(Info));
            memo = memo->next;
        }
        fout.close();
        cout << "Export database successfully" << endl;
    }
}

Info *Import() {
    ifstream fin;
    fin.open("/Users/Lancelot/Desktop/LibraryInfo.txt");//parameter
    auto memo = headInfo = new Info;
    if (!fin.is_open()) {
        cout << "Fail to import the database!" << endl;
    } else {
        while (fin.peek() != EOF) {
            cntI++;
            memo->next = new Info;
            memo = memo->next;
            fin.read((char *) memo, sizeof(Info));
        }
        fin.close();
        cout << "Import database successfully" << endl;
    }
    return headInfo;
}

void newBooks() {
    int i = 0;
    auto temp = new Info;
    cout << "Name: " << endl;
    cin >> temp->Name;
    cout << "Author: " << endl;
    cin >> temp->Author;
    cout << "Press: " << endl;
    cin >> temp->Press;
    temp->Serial = i;
    cout << "Status: " << endl;
    cin >> temp->status;
    temp->next = headInfo->next;
    headInfo->next = temp;
    cout << "Create successfully" << endl;
}

Info * search(std::string tmp) {
    Info * check = headInfo;
    while (check != nullptr) {
        if (check->Name == tmp) return check;
        check = check->next;
    }
    return nullptr;
}
