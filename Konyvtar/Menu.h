#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "memtrace.h"
#include "Konyv.h"
#include "Polc.h"

using namespace std;

struct Menu{
void menukiir();
void feladat(int valszt,Polc &p);
Polc& add(int tipus,Polc &p);
void keres(const Konyv &mit,const Polc &p);
Polc& torol(const Konyv &mit,Polc &p);
bool isinteger(const string &bemenet);
};


#endif // MENU_H
