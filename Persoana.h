//
// Created by cioca on 11/26/2022.
//

#ifndef UNTITLED1_PERSOANA_H
#define UNTITLED1_PERSOANA_H
#include <iostream>
#include <string>
#include "IOStream.h"
#include "PersoanaType.h"

class Persoana : public IOStream {
    std::string nume;
    std::string prenume;
    int varsta;
public:
    //CONSTRUCTORI
    Persoana(std::string n="null", std::string p="null",int v=0);
    Persoana(const Persoana &p);
    virtual ~Persoana();
    ///SET-GET
    std::string get_nume() const;
    void set_nume(std::string s);
    std::string get_prenume() const;
    void set_prenume(std::string s);
    int get_varsta() const;
    void set_varsta(int v);
    ///OPERATORI
    friend std::istream& operator>>(std::istream& is, Persoana& n);
    bool operator==(const Persoana &crt) const;
    bool operator!=(const Persoana &crt) const;
    ///ALTE FUNCTII
    virtual void print(std::ostream& os) const;
    virtual PersoanaType PType() const=0;

};


#endif //UNTITLED1_PERSOANA_H
