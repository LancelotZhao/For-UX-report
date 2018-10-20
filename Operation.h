//
// Created by zhaobowen on 09/03/2018.
//

#ifndef PP_OPERATION_H
#define PP_OPERATION_H

#include "IDVeri.h"
#include "Store.h"
#include "EditSys.h"

void administrator();

void guest(int);

void returning(int ID);

void borrowing(std::string, int ID);

void deleting(std::string);

void manageAccount();

void showBooks();

void clear();
#endif //PP_OPERATION_H
