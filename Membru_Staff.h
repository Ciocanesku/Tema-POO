//
// Created by cioca on 11/26/2022.
//

#ifndef UNTITLED1_MEMBRU_STAFF_H
#define UNTITLED1_MEMBRU_STAFF_H
#include <string>
#include "Persoana.h"
#include <iostream>


class Membru_Staff : public Persoana{
    std::string rol;
    int salariu;
public:
    ///CONSTRUCTORI
    Membru_Staff(std::string n="null", std::string p="null",int v=0, std::string r="null", int salariu=-1);
    Membru_Staff(Membru_Staff &j)=default;
    ///SET-GET
    std::string get_rol() const;
    int get_salariu() const;
    void set_rol(std::string r);
    void set_salariu(int s);
    ///OPERATORI
    friend std::istream& operator>>(std::istream& is, Membru_Staff& c);
    bool operator==(const Membru_Staff& rMembr);
    bool operator!=(const Membru_Staff& rMembr);
    Membru_Staff &operator=(const Membru_Staff &rhs);
    ///ALTELE
    using Persoana::print;
    void print(std::ostream &os) const override;
    virtual PersoanaType PType() const override;

};


#endif //UNTITLED1_MEMBRU_STAFF_H
