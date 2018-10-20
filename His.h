//
// Created by zhaobowen on 09/03/2018.
//

#ifndef PP_HIS_H
#define PP_HIS_H

struct his {
    time_t current;
    int ID;
    std::string name;
    his *next;
};

extern his *record;

void history(std::string, int ID);

his *historyIn();

void historyOut();

void showHis();

#endif //PP_HIS_H
