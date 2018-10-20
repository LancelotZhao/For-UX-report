//
// Created by zhaobowen on 09/03/2018.
//

#ifndef PP_STORE_H
#define PP_STORE_H
#include "IDVeri.h"

using namespace std;

struct Info {
    int Serial;
    string Name;
    string Author;
    string Press;
    int status;
    Info *next;
//    Info(){
//        Serial = 0;
//        Author = "0";
//        Press = "0";
//        status = 1;
//        next = nullptr;
//    }
};

extern int scntI;

void Export();//auto

Info *Import();//auto

Info *search(std::string);

void newBooks();//for root

extern Info *headInfo;
#endif //PP_STORE_H
