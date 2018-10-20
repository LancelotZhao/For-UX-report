//
// Created by zhaobowen on 09/03/2018.
//

#ifndef PP_IDVERI_H
#define PP_IDVERI_H

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include "EditSys.h"
#include "Store.h"
#include "Operation.h"
#include "encrypt.h"
using namespace std;
struct Account{
    int ID;
    string Password;
    Account *next = nullptr;
    Account(){
        ID = 0;
        next = nullptr;
    };
//    Account(int ID, string Password){
//        this->ID = ID;
//        this->Password = Password;
//        this->next = nullptr;
//    }
};

//extern Account LoadedAccount[];

int verify();

Account *Load();

void createAccount();

void PasswordChange(int);

void ExportAccount();

bool checkAccount(int ID, std::string);

extern Account *headA;

extern int cntA;

#endif //PP_IDVERI_H
