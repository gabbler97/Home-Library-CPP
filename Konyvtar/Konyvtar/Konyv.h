#ifndef KONYV_H
#define KONYV_H
#include <string>
#include "memtrace.h"
using namespace std;

class Konyv{
protected:
    string cim;
    string szerzo;
    int ev;
    bool kolcsonben;
public:
    Konyv (string _cim=" ",string _szerzo=" ",int _ev=0,bool _kolcsonben=false):cim(_cim),szerzo(_szerzo),ev(_ev),kolcsonben(_kolcsonben){}
    string getCim()const {return cim;}
    string getSzerzo()const {return szerzo;}
    int    getEv()const {return ev;}
    bool   getKolcsonben()const {return kolcsonben;}
    void   setSzerzo(string _szerzo) {szerzo=_szerzo;}
    void   setCim(string _cim) {cim=_cim;}
    void   setEv(int _ev) {ev=_ev;}
    void   setKolcsonben(bool _kolcsonben) {kolcsonben=_kolcsonben;}
    bool operator==(const Konyv& rhs) const;
    bool operator!=(const Konyv& rhs)const;
    virtual void print() const{};
    virtual ~Konyv(){};

    };
// Nagyobb alosztalyok
class Regeny : public Konyv{
protected:
    int oldalszam;
    string mufaj;
public:
    Regeny(string _cim=" ",string _szerzo=" ",int _ev=0,bool _kolcsonben=false,int _oldalszam=0,string _mufaj=" ")
    :Konyv(_cim,_szerzo,_ev,_kolcsonben),oldalszam(_oldalszam),mufaj(_mufaj){}
    int getOldalszam(){return oldalszam;}
    string getMufaj(){return mufaj;}
    void setOldalszam(int _oldalszam){oldalszam=_oldalszam;}
    void setMufaj(string _mufaj) {mufaj=_mufaj;}
    void print()const;
    ~Regeny(){};
};
class Ismeret:public Konyv{
protected:
    string tudomanyag;
public:
    Ismeret(string _cim=" ",string _szerzo=" ",int _ev=0,bool _kolcsonben=false,string _tudomanyag=" ")
    :Konyv(_cim,_szerzo,_ev,_kolcsonben),tudomanyag(_tudomanyag){}
    string getTudomanyag(){return tudomanyag;}
    void setTudomanyag(string _tudomanyag) {tudomanyag=_tudomanyag;}
    void print()const;
    ~Ismeret(){};
};
class Verses: public Konyv{
    int versszam;
public:
    Verses(string _cim=" ",string _szerzo=" ",int _ev=0,bool _kolcsonben=false,int _versszam=0)
    :Konyv(_cim,_szerzo,_ev,_kolcsonben),versszam(_versszam) {}
    int getVersszam(){return versszam;}
    void setVersszam(int _versszam) {versszam=_versszam;}
    void print()const;
    ~Verses(){};
};
class Korhataros: public Regeny{
    int korhatar;
public:
    Korhataros(string _cim=" ",string _szerzo=" ",int _ev=0,bool _kolcsonben=false,int _oldalszam=0,string _mufaj=" ",int _korhatar=0)
    :Regeny(_cim,_szerzo,_ev,_kolcsonben,_oldalszam,_mufaj),korhatar(_korhatar){}
    int getKorhatar(){return korhatar;}
    void setKorhatar(int _korhatar) {korhatar=_korhatar;}
    void print()const;
    ~Korhataros(){};
};
class Kepesism: public Ismeret{
    bool szines;
public:
    Kepesism(string _cim=" ",string _szerzo=" ",int _ev=0,bool _kolcsonben=false,string _tudomanyag=" ",bool _szines=false)
    :Ismeret(_cim,_szerzo,_ev,_kolcsonben,_tudomanyag),szines(_szines) {}
    bool getSzines(){return szines;}
    void setSzines(bool _szines) {szines=_szines;}
    void print()const;
    ~Kepesism(){};
};


#endif // KONYV_H
