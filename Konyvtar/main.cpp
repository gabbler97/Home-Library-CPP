#include <iostream>
#include "memtrace.h"
#include "Konyv.h"
#include "Polc.h"
#include "Menu.h"
#include <string>
#include <cstring>
#include <sstream>

using namespace std;
Menu m;
int valaszt=10;
string val=" ";
int main()
{
    Polc p;
    while(valaszt != 0)
    {
        m.menukiir();
        cin>>val;
        while(!(m.isinteger(val))){
            cout<<"Kerlek 0 es 4 kozotti szamot adjk meg!"<<endl;
            cin>>val;
        }
         istringstream iss(val); iss>>valaszt;
                 m.feladat(valaszt,p);
    }

        return 0;
    }
