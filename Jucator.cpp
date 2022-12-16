//
// Created by cioca on 11/26/2022.
//

#include "Jucator.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>


Jucator::Jucator(std::string n, std::string p,int v,std::string poz, int nt, int sal):Persoana(n,p,v),pozitie(poz),numar_tricou(nt),salariu(sal)
{

};


void Jucator::set_pozitie(std::string poz)
{
    pozitie=poz;
};


void Jucator::set_numar_tricou(int nr)
{
    numar_tricou=nr;
};


void Jucator::set_salariu(int nr)
{
    salariu=nr;
};


std::string Jucator::get_pozitie()
{
    return pozitie;
};


int Jucator::get_numar_tricou() const
{

    return numar_tricou;
}

int Jucator::get_salariu() const
{
    return salariu;
};

std::istream& operator>>(std::istream& is, Jucator& n) {
    is>> static_cast< Persoana& > (n);
    std::cout<<"Introduceti pozitie:";
    is>>n.pozitie;
    std::cout<<"Introduceti salariu:";
    is>>n.salariu;
    std::cout<<"Introduceti numar tricou:";
    is>>n.numar_tricou;
    std::cout<<std::endl;
    return is;


}
bool Jucator::operator==(const Jucator& rMembr) const
{

    return (Persoana::operator==(rMembr)) && (salariu == rMembr.salariu) && pozitie==rMembr.pozitie;
}
bool Jucator::operator!=(const Jucator& rMembr) const
{

    return !(*this==rMembr);
}
void Jucator::print(std::ostream &os) const  {
    Persoana::print(os);
    os << "\n" <<"Pozitie: "<< pozitie << "\n"<<"Salariu: "<< salariu << "\n"<<"Numar tricou:"<<numar_tricou<<std::endl;

}
Jucator &Jucator::operator=(const Jucator &rhs)
{
    Persoana::operator=(rhs);
    pozitie=rhs.pozitie;
    numar_tricou=rhs.numar_tricou;
    salariu=rhs.salariu;
    return *this;
}

PersoanaType Jucator::PType() const {return PersoanaType::Jucator;}
;