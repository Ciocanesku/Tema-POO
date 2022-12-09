//
// Created by Ciocan on 12/9/2022.
//

#include "MENIU.h"
#include <iostream>
using namespace std;
#include "Persoana.h"
#include "Jucator.h"
#include "Membru_Staff.h"
#include "Echipa.h"
#include "EroareCautareNume.h"
#include <memory>
#include "EroareJucatori.h"

void MENIU::RUN()
{
    Echipa e("STEAUA");
    int i=4;
    while(i!=100)
    {
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"CE DORITI SA FACETI?"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"0.Iesire"<<endl;
        cout<<"1.Adaugare n Membrii Staff"<<endl;
        cout<<"2.Adaugare n Jucatori"<<endl;
        cout<<"3.Afisare Membrii Staff"<<endl;
        cout<<"4.Afisare Jucatori"<<endl;
        cout<<"5.Cautare persoana dupa nume"<<endl;
        cout<<endl<<"-----------------------------------------------------------"<<endl;
        cout<<"Introduceti numarul actiunii dorite:";
        cin>>i;
        cout<<endl<<"-----------------------------------------------------------"<<endl;

        if(i==1)
        {
            int nr;
            cout<<"Introduceti numarul: ";
            cin>>nr;
            cout<<"-----------------------------------------------------------"<<endl;
            for (int j = 0; j < nr; j++) {
                auto m = std::make_shared<Membru_Staff>();
                cin >> *m;
                e.add_pers(m);
            }

        }
        if(i==2)
        {
            int nr;
            cout<<"Introduceti numarul: ";
            cin>>nr;
            cout<<"-----------------------------------------------------------"<<endl;
            try{
                e.citire_jucatori(nr);
            }
            catch (const EroareJucatori& err)
            {
                cout<<endl<<err<<endl;
            }

        }
        if(i==3)
        {
            cout<<"NUMAR MEMBRII STAFF:"<<e.get_nrstaff()<<endl;
            e.FindAllStaff();
        }
        if(i==4)
        {
            cout<<"NUMAR JUCATORI:"<<e.get_nrjucatori()<<endl;
            e.FindAllJucator();
        }
        if(i==5)
        {
            string s;
            cout<<"Introduceti numele:";
            cin>>s;
            cout<<"-----------------------------------------------------------"<<endl;

            try {
                cout << e.af_dupa_nume(s);
            }
            catch(const EroareCautareNume& err)
            {
                cout<<endl<<err<<endl;
            }

        }
        if(i==0)
            i=100;



    }
}