#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include "memtrace.h"
#include "Menu.h"
#include "Polc.h"
#include "Konyv.h"
using namespace std;
void Menu::menukiir(){

        cout <<endl << "Nezzuk a konyvtarad!" << endl << "1.Konyv hozzaadasa"<< endl << "2.Konyv keresese" << endl << "3.Konyv torlese"
        << endl << "4.Teljes konyvtar kiirasa" << endl << "0.Kilepes" << endl;
}
void Menu::feladat(int valaszt,Polc &p){
    if (valaszt==1){
        cout << "Milyen konyvet adsz hozza?" << endl << "1.Regeny" << endl << "2.Ismeretterjeszto" << endl << "3.Verseskotet"
        << endl << "4.Korhataros regeny" << endl << "5.Ismeetterjeszto kepekkel" << endl;
        int tipus;
        string tip;
        cin>>tip;
        while(!(isinteger(tip))){
              cout<<"Kerlek adj meg egy 0 es 5 kozotti szamot!"<<endl;
              cin>>tip;
        }
        istringstream iss(tip); iss>>tipus;
        Menu::add(tipus,p);

    }
    else if(valaszt==2){
        string cim;
        string szerzo;
        cout<< "Kerlek add meg a cimet es a szerzot!" << endl;
        string nah;
        getline(cin,nah);
        cout << "Cim:"; getline(cin, cim); cout << endl;
        cout << "Szerzo:"; getline(cin, szerzo); cout << endl;
        Konyv mit;
        mit.setCim(cim); mit.setSzerzo(szerzo);
        Menu::keres(mit,p);


    }
    else if(valaszt==3){
        string cim;
        string szerzo;
        cout<< "Kerlek add meg a cimet es a szerzot!" << endl;
        string nah;
        getline(cin,nah);
        cout << "Cim:"; getline(cin, cim); cout << endl;
        cout << "Szerzo:"; getline(cin, szerzo); cout << endl;
        Konyv mit;
        mit.setCim(cim); mit.setSzerzo(szerzo);
        Menu::torol(mit,p);
    }

    else if(valaszt==4){
        p.listaz();
    }
}
Polc& Menu::torol(const Konyv &mit,Polc &p){
    Konyv ures; ures.setCim("ures"); ures.setSzerzo("ures");
    Konyv *talalat=p.keres(mit);
    if(ures!=*talalat){
        int torlie;
        cout << endl << "Biztosan torli?"<< endl<<"1.Torles" << endl << "2.Megtartas" << endl;
        string torli;
        cin>>torli;
        while(!(isinteger(torli))){
            cout<<"1. Torles"<< endl << "2.Megtartas" << endl;
            cin>>torli;
        }
        istringstream iss(torli); iss>>torlie;
        if(torlie==1){
            p.torol(mit);
            cout << "Toroltem!" << endl;
        }
        else{
            cout << "Rendben, megtartom!" << endl;
        }
    }
    else{
        cout<< "Nincs ilyen konyv" << endl;
    }
    return p;
}
void Menu::keres(const Konyv &mit,const Polc &p){
        Konyv* talalat;
        Konyv ures; ures.setCim("ures"); ures.setSzerzo("ures");
        talalat=p.keres(mit);
        if(ures!=*talalat){
            talalat->print();
        }
        else {
            delete talalat;
            cout<< endl << "Nincs ilyen konyv" << endl;
        }
}
Polc & Menu::add(int tipus,Polc &p){
    if(tipus==1){
        string cim,szerzo,mufaj;
        bool kolcsonben = false;
        int ev,oldalszam;
        string kolcson;
        string oldszam;
        string e;
        string nah;
        getline(cin,nah);
        cout << "Cim:"; getline(cin, cim); cout << endl;
        cout << "Szerzo:"; getline(cin, szerzo); cout << endl;
        cout << "Mufaj:"; getline(cin, mufaj); cout << endl;
        cout << "Kolcsonben van?:";getline(cin, kolcson); cout << endl;
        cout << "Kiadas eve:";
        cin >> e;
        while(!(isinteger(e))){
              cout<<"Kerlek adj meg egy egesz szamot"<<endl;
              cin>>e;
        }
        istringstream iss(e); iss>>ev;
        cout << endl;
        cout << "Oldalszam:" << endl;
        cin >> oldszam;
        while(!(isinteger(oldszam))){
              cout<<"Kerlek adj meg egy egesz szamot"<<endl;
              cin>>oldszam;
        }
        istringstream is(oldszam); is>>oldalszam;
        cout << endl;
        if(kolcson=="i" || kolcson=="igen" || kolcson=="Igen" || kolcson=="I" ) kolcsonben=true;
        Regeny *r = new Regeny(cim, szerzo, ev, kolcsonben, oldalszam, mufaj);
        p.hozzaad(r);
        return p;
    }
    else if(tipus==2){
        string cim,szerzo,tudomanyag;
        bool kolcsonben = false;
        int ev;
        string e;
        string kolcson;
        string nah;
        getline(cin,nah);
        cout << "Cim:"; getline(cin, cim); cout << endl;
        cout << "Szerzo:"; getline(cin, szerzo); cout << endl;
        cout << "Tudomanyag:"; getline(cin, tudomanyag); cout << endl;
        cout << "Kolcsonben van?:";getline(cin, kolcson); cout << endl;
        cout << "Kiadas eve:";
        cin >> e;
        while(!(isinteger(e))){
              cout<<"Kerlek adj meg egy egesz szamot"<<endl;
              cin>>e;
        }
        istringstream iss(e); iss>>ev;
        cout << endl;
        if(kolcson=="i" || kolcson=="igen" || kolcson=="Igen" || kolcson=="I" ) kolcsonben=true;
        Ismeret *r = new Ismeret(cim, szerzo, ev, kolcsonben, tudomanyag);
        p.hozzaad(r);
        return p;
    }
    else if(tipus==3){
        string cim,szerzo;
        bool kolcsonben = false;
        int ev,versszam;
        string nah;
        string e;
        string verssz;
        getline(cin,nah);
        string kolcson;
        cout << "Cim:"; getline(cin, cim); cout << endl;
        cout << "Szerzo:"; getline(cin, szerzo); cout << endl;
        cout << "Kolcsonben van?:";getline(cin, kolcson); cout << endl;
        cout << "Versek szama:";
        cin >> verssz;
        while(!(isinteger(verssz))){
              cout<<"Kerlek adj meg egy egesz szamot"<<endl;
              cin>>verssz;
        }
        istringstream is(verssz); is>>versszam;
        cout << endl;
        cout << "Kiadas eve:";
        cin >> e;
        while(!(isinteger(e))){
              cout<<"Kerlek adj meg egy egesz szamot"<<endl;
              cin>>e;
        }
        istringstream iss(e); iss>>ev;
        cout << endl;
       if(kolcson=="i" || kolcson=="igen" || kolcson=="Igen" || kolcson=="I" ) kolcsonben=true;
        Verses *r = new Verses(cim, szerzo, ev, kolcsonben, versszam);
        p.hozzaad(r);
        return p;
    }
    else if(tipus==4){
        string cim,szerzo,mufaj;
        bool kolcsonben = false;
        int ev,oldalszam,korhatar;
        string kolcson;
        string nah;
        string e;
        string oldalsz;
        string korh;
        getline(cin,nah);
        cout << "Cim:"; getline(cin, cim); cout << endl;
        cout << "Szerzo:"; getline(cin, szerzo); cout << endl;
        cout << "Mufaj:"; getline(cin, mufaj); cout << endl;
        cout << "Kolcsonben van?:";getline(cin, kolcson); cout << endl;
        cout << "Kiadas eve:";
        cin >> e;
        while(!(isinteger(e))){
              cout<<"Kerlek adj meg egy egesz szamot"<<endl;
              cin>>e;
        }
        istringstream iss(e); iss>>ev;
        cout << endl;
        cout << "Oldalszam:";
        cin >> oldalsz;
        while(!(isinteger(oldalsz))){
              cout<<"Kerlek adj meg egy egesz szamot"<<endl;
              cin>>oldalsz;
        }
        istringstream is(oldalsz); is>>oldalszam;
        cout << endl;
        cout << "Korhatar:";
        cin >> korh;
        while(!(isinteger(korh))){
              cout<<"Kerlek adj meg egy egesz szamot"<<endl;
              cin>>korh;
        }
        istringstream i(korh); i>>korhatar;
        cout << endl;
        if(kolcson=="i" || kolcson=="igen" || kolcson=="Igen" || kolcson=="I" ) kolcsonben=true;
        Korhataros *r = new Korhataros(cim, szerzo, ev, kolcsonben, oldalszam, mufaj,korhatar);
        p.hozzaad(r);
        return p;
    }
    else if(tipus==5){
        string cim,szerzo,tudomanyag,szin;
        bool kolcsonben = false;
        bool szines=false;
        int ev;
        string kolcson;
        string nah;
        string e;
        getline(cin,nah);
        cout << "Cim:"; getline(cin, cim); cout << endl;
        cout << "Szerzo:"; getline(cin, szerzo); cout << endl;
        cout << "Tudomanyag:"; getline(cin, tudomanyag); cout << endl;
        cout << "Kolcsonben van?:"; getline(cin, kolcson); cout << endl;
        cout << "Szinesek a kepek?:"; getline(cin, szin); cout << endl;
        cout << "Kiadas eve:";
        cin >> e;
        while(!(isinteger(e))){
              cout<<"Kerlek adj meg egy egesz szamot"<<endl;
              cin>>e;
        }
        istringstream iss(e); iss>>ev;
        cout << endl;        if(kolcson=="i" || kolcson=="igen" || kolcson=="Igen" || kolcson=="I" ) kolcsonben=true;
        if(szin=="i" || szin=="igen" || szin=="Igen" || szin=="I") szin=true;
        Kepesism *r = new Kepesism(cim, szerzo, ev, kolcsonben, tudomanyag, szines);
        p.hozzaad(r);
        return p;
    }
    return p;
}
bool Menu::isinteger(const string &bemenet){
    size_t hossz=bemenet.size();
    size_t cnt=0;
    for(size_t i=0;i <hossz ;i++){
        if(isdigit(bemenet[i])) cnt++;
    }
    return cnt==hossz;
}
