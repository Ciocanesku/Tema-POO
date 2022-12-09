//
// Created by cioca on 11/26/2022.
//

#ifndef UNTITLED1_JUCATOR_H
#define UNTITLED1_JUCATOR_H


#include "Persoana.h"
#include <string>

class Jucator: public Persoana {
    std::string pozitie;
    int numar_tricou;
    int salariu;
public:
    ///CONSTRUCTORI
    Jucator(std::string n="null", std::string p="null",int v=0,std::string poz="null", int nt=-1, int sal=-1);
    Jucator(Jucator &j)=default;
    ///GET-SET
    void set_pozitie(std::string poz);
    void set_numar_tricou(int nr);
    void set_salariu(int nr);
    std::string get_pozitie();
    int get_numar_tricou();
    int get_salariu();
    ///OPERATORI
    friend std::istream& operator>>(std::istream& is, Jucator& c);
    bool operator==(const Jucator& rMembr);
    bool operator!=(const Jucator& rMembr);
    ///ALTE FUNCTII
    using Persoana::print;
    void print(std::ostream &os) const override;
    virtual PersoanaType PType() const override;


};


#endif //UNTITLED1_JUCATOR_H
