#include <string>
#include <iostream>
using namespace std;

class Voiture
{
    //* Declaration des attributs *//

    string marque;     //* la marque de la voiture.
    string modele;     //* le modèle de la voiture.
    int annee;         //* l'année de fabrication de la voiture.
    float kilometrage; //* le kilométrage actuel de la voiture.
    float vitesse;     //* la vitesse actuelle de la voiture.

    //* Methods *//

    // 1. Constructeur par défaut
    // methode 1 :
    Voiture()
    {
        marque = "Mercedes";
        modele = "Mercedes-Benz E-Class";
        annee = 1993;
        kilometrage = 110000.5;
        vitesse = 80.5;
    }
    // methode 2 :
    Voiture() : marque("Mercedes"), modele("Mercedes-Benz E-Class"), annee(1993), kilometrage(110000.5), vitesse(80.5)
    {
    }
    // 2. Constructeur avec paramètres
    Voiture(string marque, string modele, int annee, float kilometrage, float vitesse)
    {
        this->marque = marque;
        this->modele = modele;
        this->annee = annee;
        this->kilometrage = kilometrage;
        this->vitesse = vitesse;
    }
    // 3. Méthode accelerer
    void accelerer(float valeur)
    {
        vitesse = vitesse + valeur;
    }
    // 4. Méthode freiner
    void freiner(float valeur)
    {

        if (vitesse > 0)
        {
            vitesse = vitesse - valeur;
            if (vitesse < 0)
            {
                vitesse = 0;
            }
        }
    }
    // 5. Méthode afficherInfo()
    void afficherInfo()
    {
        cout << "La marque de la voiture est : " << marque << endl;
        cout << "Le modèle de la voiture est : " << modele << endl;
        cout << "L'année de fabrication de la voiture est : " << annee << endl;
        cout << "Le kilométrage actuel de la voiture est : " << kilometrage << " km" << endl;
        cout << "La vitesse actuelle de la voiture est : " << vitesse << " km/h" << endl;
    }
    // 6. Méthode avancer(float distance)
    void avancer(float distance)
    {
        kilometrage = kilometrage + distance;
    }
    // 7. Destructeur
    ~Voiture()
    {
        cout << "La voiture " << marque << " " << modele << " est détruite." << endl;
    }
};
