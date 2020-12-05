#include <iostream>
#include "memtrace.h"
#include "Konyv.h"

//Konyv osztaly metodusa
bool Konyv::operator==(const Konyv& rhs) const{
if(this->cim==rhs.getCim() && this->szerzo==rhs.getSzerzo()) return true;
else return false;
}
bool Konyv::operator!=(const Konyv& k)const{
return!((*this)==k);
}

//Regeny osztay metodusai

void Regeny::print()const{
    string kolcson;
    if(kolcsonben) kolcson="igen";
    else kolcson="nem";
    cout<<"Cim: "<<cim<<endl<<"Szerzo: "<< szerzo<< endl<<"Kiadas eve: "<<ev<<endl<<"Kolcsonben van?: "<<kolcson
    <<endl<<"Oldalszam: "<<oldalszam<<endl<<"Mufaj: "<<mufaj << endl;
}


//Ismeret metódusai



void Ismeret::print()const{
    string kolcson;
    if(kolcsonben) kolcson="igen";
    else kolcson="nem";
    cout<<"Cim: "<<cim<<endl<<"Szerzo: "<< szerzo<< endl<<"Kiadas eve: "<<ev<<endl<<"Kolcsonben van?: "<<kolcson
    <<endl<<"Tudomanyag:" << tudomanyag << endl;
}


//Verses metodusok


void Verses::print()const{
    string kolcson;
    if(kolcsonben) kolcson="igen";
    else kolcson="nem";
    cout<<"Cim: "<<cim<<endl<<"Szerzo: "<< szerzo<< endl<<"Kiadas eve: "<<ev<<endl<<"Kolcsonben van?: "<<kolcson
    <<endl<<"Versek szama:" << versszam << endl;
}

//Korhataros metodusok


void Korhataros::print()const{
    string kolcson;
    if(kolcsonben) kolcson="igen";
    else kolcson="nem";
    cout<<"Cim: "<<cim<<endl<<"Szerzo: "<< szerzo<< endl<<"Kiadas eve: "<<ev<<endl<<"Kolcsonben van?: "<<kolcson
    <<endl<<"Oldalszam: "<<oldalszam<<endl<<"Mufaj: "<<mufaj << endl << "Korhatar:" << korhatar << endl;
}


//Kepesismereto


void Kepesism::print()const{
    string kolcson="nem";
    string szin="nem";
    if(kolcsonben) kolcson="igen";
    if(szines) szin="igen";
    cout<<"Cim: "<<cim<<endl<<"Szerzo: "<< szerzo<< endl<<"Kiadas eve: "<<ev<<endl<<"Kolcsonben van?: "<<kolcson
    <<endl<<"Tudomanyag:" << tudomanyag << endl;
}
