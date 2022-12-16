//
// Created by cioca on 11/26/2022.
//

#include "Echipa.h"
#include <string>
#include <iostream>
#include "EroareCautareNume.h"
#include "EroareJucatori.h"

std::vector<std::shared_ptr <Persoana> > Echipa::p;
int Echipa::get_nrpers() const {
    return numar_pers;
}

Echipa ::Echipa(std::string s):nume(s)
{
    numar_jucatori=0;
    numar_staff=0;
    numar_pers=0;
};
void Echipa::set_nume(std::string s)
{
    nume=s;
};
std::string Echipa::get_nume(){
    return nume;
};

void Echipa::citire_jucatori(int n) {
    if(n+numar_jucatori<18)
    {
        for (int j = 0; j < n; j++) {
            auto m = std::make_shared<Jucator>();
            std::cin >> *m;
            add_pers(m);
        }
    }
    else
        throw EroareJucatori();
}

void Echipa::add_pers(std::shared_ptr<Persoana> prs) {
        p.push_back(prs);
        numar_pers++;
        auto juc = std::dynamic_pointer_cast<Jucator>(prs);
        if (juc == nullptr)
            numar_staff++;
        else
            numar_jucatori++;

}
int Echipa::get_nrjucatori() const {
   return numar_jucatori;
}
int Echipa::get_nrstaff() const {
    return numar_staff;
}


void Echipa::af_pers() const {
    for(auto &Persoana: p)
    {
        std::cout<<Persoana<<std::endl;
    }
}

std::vector<std::shared_ptr<Jucator>> Echipa::FindAllJucator() {
    std::vector<std::shared_ptr<Jucator>> j;
    std::cout<<"JUCATORI"<< std::endl;
    for(auto &Persoana: p)
    {
        if(typeid(*Persoana) == typeid(Jucator))
        {
            std::cout<<Persoana<<std::endl<<"-------------------------------------------------------"<<std::endl;
            auto juc = std::dynamic_pointer_cast<Jucator>(Persoana);
            j.push_back(juc);
        }
    }
    return j;
}
std::vector<std::shared_ptr<Membru_Staff>> Echipa::FindAllStaff() {
    std::vector<std::shared_ptr<Membru_Staff>> j;
    std::cout<<"Membrii Staff"<< std::endl;
    for(auto &Persoana: p)
    {
        if(typeid(*Persoana) == typeid(Membru_Staff))
        {
            std::cout<<Persoana<<std::endl<<"-------------------------------------------------------"<<std::endl;
            auto juc = std::dynamic_pointer_cast<Membru_Staff>(Persoana);
            j.push_back(juc);
        }
    }
    return j;
}

std::shared_ptr<Persoana> Echipa::af_dupa_nume(const std::string& name)
{
    for(auto &Persoana: p)
    {
        if(Persoana->get_nume()==name)
            return Persoana;
    }
    throw EroareCautareNume();
}

Echipa:: ~Echipa()
{
    /*for(int i=0; i<numar_jucatori;i++)
        delete j[i];
    for(int i=0; i<numar_staff;i++)
        delete m[i];*/
};