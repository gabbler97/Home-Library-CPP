#include <iostream>
#include "memtrace.h"
#include "Polc.h"
#include "Konyv.h"

Konyv& Polc::operator[](size_t ix) {
    return *konyvek[ix];
}

const Konyv& Polc::operator[](size_t ix)const {
    return *konyvek[ix];
}
Konyv* Polc::keres(const Konyv& k)const {
    for(size_t i=0;i<this->db;++i){
        if(*(this->konyvek[i])==k)
            return konyvek[i];
    }
    Konyv *Ures = new Konyv("ures", "ures");
    return Ures;
}

void Polc::listaz(){
    if(db!=0){
        for(size_t i=0;i<this->db;++i){
                konyvek[i]->print();
                cout << endl;
        }
    }
    else cout<< "Ez ures:(" << endl;
}


size_t Polc::keresix(const Konyv& k){
    for(size_t i=0;i<this->db;++i){
        if(*(this->konyvek[i])==k)
            return i;
    }
    return -1;
}

void Polc::torol(const Konyv &mit){
    size_t ix=keresix(mit);
    size_t overflow=-1;
    if(ix!=overflow && db != 0){
            delete konyvek[ix];
        for(size_t i=ix; i<this->db-1; ++i){
            konyvek[i] = konyvek[i+1];

        }
        this->db-=1;
    }


}
void Polc::hozzaad(Konyv* mit){
    if (db == ActualMax)
    {
        ActualMax += 30;
        Konyv **Temp = new Konyv*[ActualMax];
        for(size_t i=0; i<db; i++)
        {
            Temp[i] = konyvek[i];
        }
        delete[] konyvek;
        konyvek = Temp;

    }
    konyvek[db++] = mit;
}

