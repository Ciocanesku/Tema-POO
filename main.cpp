#include <iostream>
#include <cstring>
using namespace std;

class Carte{
    char *titlu, *autor;
    int an_aparitie;
public:

    Carte(const char *titlu_="x",const char *autor_="x", int an_aparitie_=0){
        size_t len=strlen(titlu_);
        titlu= new char[len+1];
        strcpy(titlu,titlu_);

        size_t len1=strlen(autor_);
        autor=new char[len1+1];
        strcpy(autor,autor_);

        an_aparitie = an_aparitie_;

    };
    ~Carte()
    {
        delete titlu;
        delete autor;
    }

    ///   SET/GET TITLU
    char *gettitlu() const {
        return titlu;
    }
    void settitlu(char* titlu_)
    {delete []titlu;
        size_t len=strlen(titlu_);
        titlu=new char[len + 1];
        strcpy(titlu, titlu_);
    }

    /// SET/GET AUTOR
    char *getautor() const{
        return autor;
    }

    void setautor(char* autor_)
    {
        delete [] autor;
        size_t len = strlen(autor_);
        autor = new char [len+1];
        strcpy(autor, autor_);
    }

    /// GET/SET AN APARITIE
    int getan_aparitie() const{
        return an_aparitie;
    }
    void setan_aparitie(int nr)
    {
        an_aparitie=nr;
    }
    void afis() const
    {
        cout<<titlu<<" "<<autor<<" "<<an_aparitie;    }
    /// CONSTRUCTOR DE COPIERE
    Carte(const Carte &c)
    {
        size_t len=strlen(c.titlu);
        titlu= new char[len+1];
        strcpy(titlu,c.titlu);

        size_t len1=strlen(c.autor);
        autor=new char[len1+1];
        strcpy(autor,c.autor);

        an_aparitie = c.an_aparitie;
    }
    friend class Librarie;

    bool operator==(const Carte &crt) const
    {
        return strcmp(titlu,crt.titlu)==0 && strcmp(autor,crt.autor)==0 && an_aparitie==crt.an_aparitie;

    }
    bool operator!=(const Carte &crt) const
    {
        return strcmp(titlu,crt.titlu)!=0 || strcmp(autor,crt.autor)!=0 || an_aparitie!=crt.an_aparitie;

    }

    Carte& operator=(const Carte &rhs) {

        if (this != &rhs)
        {
            setautor(rhs.autor);
            settitlu(rhs.titlu);
        }

        this->an_aparitie = rhs.an_aparitie;

        return *this;
    }
    friend ostream& operator<<(ostream &os, const Carte& n){
        os<<n.titlu<<" "<<n.autor<<" "<<n.an_aparitie;
        return os;
    }
    friend istream& operator>>(istream& is, Carte& n) {
        char buff[255];
        delete[]n.titlu;
        delete[]n.autor;
        cout<<"Introduceti titlu:";
        is.ignore();
        is.getline(buff,45);
        n.titlu=new char[strlen(buff)+1];
        strcpy(n.titlu,buff);
        cout<<endl;


        cout<<"Introduceti autor:";
        is.getline(buff,45);
        n.autor=new char[strlen(buff)+1];
        strcpy(n.autor,buff);
        cout<<endl;

        cout<<"Introduceti an aparitie:";
        is>>n.an_aparitie;
        return is;

    }
};



////////////////////////////////////////////////////////////////////////////////////



class Librarie{
    int numar_carti;
    Carte* c ;
public:
    Librarie(int nr, Carte *crt)
    {
        numar_carti=nr;
        c=new Carte[nr];
        int i;
        for(i=0;i<nr;i++)
        {
            c[i].titlu=new char [strlen(crt[i].titlu)+1];
            strcpy(c[i].titlu,crt[i].titlu);

            c[i].autor=new char [strlen(crt[i].autor)+1];
            strcpy(c[i].autor,crt[i].autor);

            c[i].an_aparitie=crt[i].an_aparitie;

        }

    }
    Librarie(const Librarie &l)
    {numar_carti=l.numar_carti;
        c=new Carte[numar_carti];
        for(int i=0;i<numar_carti;i++)
            c[i]=l.c[i];
    }
    ~Librarie()
    {
        delete []c;
    }

    int get_nrcarti() const
    {
        return numar_carti;
    }
    void set_nrcarti(int i)
    {
        numar_carti=i;
    }
    void afisCarti()
    {
        int i;
        for(i=0;i<numar_carti;i++)
        {
            cout<<c[i].titlu<<" de "<<c[i].autor<<" aparuta in "<<c[i].an_aparitie<<endl;

        }
    }

    int Cautare_carte(const Carte &crt)
    {
        for(int i=0;i<numar_carti;i++)
        {
            if(c[i]==crt)
                return i;

        }
        return -1;
    }

    Librarie& operator+=(const Carte &rhs)
    {
        Carte *bk;
        bk= new Carte [numar_carti];
        for(int i=0;i<numar_carti;i++)
            bk[i]=c[i];
        delete []c;
        c=new Carte [numar_carti+1];
        for(int i=0;i<numar_carti;i++)
            c[i]=bk[i];
        c[numar_carti]=rhs;
        numar_carti++;
        delete[] bk;
        return *this;
    }

};

int main() {
    Carte c[] = {Carte("Amintiri din Copilarie", "Ion Creanga", 1998),
                 Carte("Harap Alb", "", 1999),
                 Carte("Maitreyi", "Mircea Eliade", 1977),
                 Carte("Ferma Animalelor", "George Orwell", 1966),
                 Carte("Micul print", "Antoine de Saint-Exupery", 1985)};
    Librarie l(5, c);

    int n,i=0;
    while(i<100) {
        cout << "Ce doriti sa faceti?" << endl;
        cout << "Apasati tasta corespunzatoare actiunii dorite:" << endl;
        cout << "1.Afisare carti" << endl;
        cout << "2.Cautare carte" << endl;
        cout << "3.Adaugare carte" << endl;
        cout << "4.Iesire program" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Introduceti tasta: ";
        cin >> n;
        if(n==1)
        {
            l.afisCarti();
            cout<<endl;
            cout << "-----------------------------------------------" << endl;
        }
        if(n==2)
        {
            int an;
            Carte caut;
            cin>>caut;
            an=l.Cautare_carte(caut);
            cout<<"Cartea cautata este pe pozitia: "<<an<<" (-1 inseamna ca nu gasim cartea in librarie)";
            cout<<endl;
            cout << "-----------------------------------------------" << endl;

        }
        if(n==3)
        {

            Carte caut;
            cin>>caut;
            l+=caut;
            cout<<endl;
            cout << "-----------------------------------------------" << endl;
        }
        if(n==4) {
            i = 101;
            cout << "Finalul programului";
        }
    }
    return 0;
}