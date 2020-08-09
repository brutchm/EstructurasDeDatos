//
// Created by Brandon Rutch on 11/13/19.
//
#include <iostream>
using namespace std;
#include "Disco.h"

Disco::Disco(int num, int pos) : num(num), pos(pos) {}

Disco::Disco() {}

int Disco::getNum() const {
    return num;
}

void Disco::setNum(int num) {
    Disco::num = num;
}

int Disco::getPos() const {
    return pos;
}

void Disco::setPos(int pos) {
    Disco::pos = pos;
}
