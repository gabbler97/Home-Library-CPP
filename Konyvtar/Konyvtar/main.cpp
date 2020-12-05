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
         if(m.isinteger(val)) { istringstream iss(val); iss>>valaszt; }
        else{
            if(!(m.isinteger(val))){
                cout<<"Kerlek valassz az fenti menubol(0 es 4 kozotti szamot)" << endl;
                cin>>val; cout<< endl;
            }
        }
        m.feladat(valaszt,p);
    }
    return 0;
}
