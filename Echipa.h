//
// Created by cioca on 11/26/2022.
//

#ifndef UNTITLED1_ECHIPA_H
#define UNTITLED1_ECHIPA_H
#include <string>
#include <vector>
#include "Jucator.h"
#include "Membru_Staff.h"
#include <memory>


class Echipa {
    int numar_jucatori;
    int numar_staff;
    int numar_pers;
    std::string nume;
    static std::vector <std::shared_ptr <Persoana> > p;
public:
    Echipa(std::string s);
    void set_nume(std::string s);
    std::string get_nume();

    ~Echipa();
    friend class Persoana;
    ///ALTE FUNCTII
    void citire_staff(int n);
    void citire_jucatori(int n);
    void add_pers(std::shared_ptr<Persoana> prs);
    int get_nrjucatori() const;
    int get_nrstaff() const;
    int get_nrpers() const;
    void af_pers() const;
    static std::vector<std::shared_ptr <Jucator>> FindAllJucator();
    static std::shared_ptr<Persoana> af_dupa_nume(const std::string& name);
    static std::vector<std::shared_ptr<Membru_Staff>> FindAllStaff();

};


#endif //UNTITLED1_ECHIPA_H
