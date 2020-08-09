//
// Created by Brandon Rutch on 11/13/19.
//
#include <iostream>

using namespace std;

#ifndef TORREHANOI_DISCO_H
#define TORREHANOI_DISCO_H


class Disco {
private:
    int num;
    int pos;
public:
    Disco(int num, int pos);

    Disco();

    int getNum() const;

    void setNum(int num);

    int getPos() const;

    void setPos(int pos);

};


#endif //TORREHANOI_DISCO_H
