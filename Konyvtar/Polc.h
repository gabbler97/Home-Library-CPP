#ifndef POLC_H
#define POLC_H
#include "memtrace.h"
#include "Konyv.h"
class Polc
{
    size_t db;
    size_t ActualMax;
    Konyv **konyvek;
public:
    Polc(size_t db=0, size_t AMax = 1) : db(db), ActualMax(AMax){ konyvek = new Konyv*[ActualMax]; }
    size_t getDb(){return db;}
    size_t getDb()const {return db;}
    size_t getActualMax(){return ActualMax;}
    void hozzaad(Konyv *mit);
    Konyv* keres(const Konyv &mit) const;
    size_t keresix(const Konyv &mit);
    void torol(const Konyv &mit);
    void listaz();
    Konyv& operator[](size_t ix);
    const Konyv& operator[](size_t ix)const;
    ~Polc(){for(size_t i=0;i<db;i++){delete konyvek[i];}delete[] konyvek;}

};
#endif // POLC_H
//kivetelkezeles menuben
//Konyv osztaly lefedettsege
