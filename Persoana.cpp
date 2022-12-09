//
// Created by cioca on 11/26/2022.
//

#include "Persoana.h"
#include <string>
#include <iostream>

Persoana::Persoana(std::string n, std::string p,int v):nume(std::move(n)),prenume(std::move(p)),varsta(v)
{

}

Persoana::Persoana(const Persoana &p): Persoana(p.nume, p.prenume, p.varsta){

}


std::string Persoana::get_nume() const
{
    return nume;
};


void Persoana::set_nume(std::string s)
{
    nume=s;
};


std::string Persoana::get_prenume() const
{
    return prenume;
};


void Persoana::set_prenume(std::string s)
{
    prenume=s;
};


int Persoana::get_varsta() const
{
    return varsta;
};


void Persoana::set_varsta(int v)
{
    varsta=v;
};


std::istream& operator>>(std::istream& is, Persoana& n) {

    std::cout << "Introduceti numele:";
    is >> n.nume;

    std::cout << "Introduceti prenumele:";
    is >> n.prenume;

    std::cout << "Introduceti varsta:";
    is >> n.varsta;

    return is;

}
bool Persoana::operator==(const Persoana &crt) const
{
    return nume==crt.nume && prenume==crt.prenume && varsta==crt.varsta;

}
bool Persoana::operator!=(const Persoana &crt) const
{
    return !(*this==crt);

}
void Persoana::print(std::ostream &os) const {
    os<<"Nume:"<<nume<<std::endl<<"Prenume:"<<prenume<<" \n"<<"Varsta:" <<varsta;

}
Persoana::~Persoana()=default;

