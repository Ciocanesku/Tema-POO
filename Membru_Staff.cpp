//
// Created by cioca on 11/26/2022.
//

#include "Membru_Staff.h"
#include <string>
#include <iostream>

Membru_Staff::Membru_Staff(std::string n, std::string p,int v, std::string r, int salariu):Persoana(std::move(n),std::move(p),v), rol(std::move((r))),salariu(salariu)
{

};

std::string Membru_Staff::get_rol() const
{
    return rol;
};
int Membru_Staff::get_salariu() const
{
    return salariu;
};
void Membru_Staff::set_rol(std::string r)
{
    rol=r;
};
void Membru_Staff::set_salariu(int s)
{
    salariu=s;
};


std::istream& operator>>(std::istream& is, Membru_Staff& n) {
    is>> static_cast< Persoana& > (n);
    std::cout<<"Introduceti rol:";
    is>>n.rol;
    std::cout<<"Introduceti salariu:";
    is>>n.salariu;
    return is;


}
bool Membru_Staff::operator==(const Membru_Staff& rMembr)
{

    return (Persoana::operator==(rMembr)) && (salariu == rMembr.salariu) && rol==rMembr.rol;
}
bool Membru_Staff::operator!=(const Membru_Staff& rMembr)
{

    return !(*this==rMembr);
}
void Membru_Staff::print(std::ostream &os) const {
    Persoana::print(os);
    os << "\n" <<"Rol: "<<rol << "\n"<<"Salariu: "<<salariu << "\n";

}

Membru_Staff &Membru_Staff::operator=(const Membru_Staff &rhs) {
    Persoana::operator=(rhs);
    rol=rhs.rol;
    salariu=rhs.salariu;
    return *this;
}
PersoanaType Membru_Staff::PType() const {return PersoanaType::Membru_Staff;}
;