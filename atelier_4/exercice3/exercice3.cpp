#include <iostream>
using namespace std;

class Personne
{
private:
    string nom;
    string prenom;
    string date_n;

public:
    Personne(string n, string p, string dn) : nom(n), prenom(p), date_n(dn) {}

    virtual void afficher() const
    {
        cout << "Le nom est : " << nom << endl;
        cout << "Le prenom est : " << prenom << endl;
        cout << "La date de naissance est : " << date_n << endl;
    }
};

class Employe : public Personne
{
private:
    double salaire;

public:
    Employe(string n, string p, string dn, double sal) : Personne(n, p, dn), salaire(sal) {}
    void afficher() const
    {
        Personne ::afficher();
        cout << "Le salaire accompagné est : " << salaire << " DH" << endl;
    }
};

class Chef : public Employe
{
private:
    string service;

public:
    Chef(string n, string p, string dn, double sal, string ser) : Employe(n, p, dn, sal), service(ser) {}
    void afficher() const
    {
        Employe ::afficher();
        cout << "Le service accompagné est : " << service << endl;
    }
};

class Directeur : public Chef
{
private:
    string societe;

public:
    Directeur(string n, string p, string dn, double sal, string ser, string soc) : Chef(n, p, dn, sal, ser), societe(soc) {}
    void afficher() const
    {
        Chef ::afficher();
        cout << "La société accompagné est : " << societe << endl;
    }
};

int main()
{
    Directeur direct("Elkhatab", "Sohaib", "09/07/2002", 50.5, "service", "fst");
    Personne *personne = &direct;
    personne->afficher();
}