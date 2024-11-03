#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Traitement
{
private:
    vector<int> vecteur;

public:
    // Méthode pour initialiser le vecteur avec 15 entiers pairs non nuls
    void initialise()
    {
        int count = 0;
        while (count < 15)
        {
            int valeur;
            cout << "Saisissez un entier pair non nul : ";
            cin >> valeur;

            if (cin.fail())
            {
                cin.clear();                                         // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Entrée invalide. Veuillez saisir un entier pair non nul.\n";
                continue;
            }

            if (valeur != 0 && valeur % 2 == 0)
            {
                vecteur.push_back(valeur);
                count++;
            }
            else
            {
                cout << "La valeur doit être un entier pair non nul.\n";
            }
        }
    }

    // Méthode récursive pour afficher les éléments du vecteur
    void show(size_t index = 0) const
    {
        if (index < vecteur.size())
        {
            cout << vecteur[index] << " ";
            show(index + 1);
        }
        else if (index == 0)
        {
            cout << "Le vecteur est vide.\n";
        }
    }

    // Déclaration des fonctions amies
    friend double moyenne(const Traitement &t);
    friend double median(const Traitement &t);
};

// Fonction amie pour calculer la moyenne des éléments du vecteur
double moyenne(const Traitement &t)
{
    if (t.vecteur.empty())
        return 0.0;

    int sum = 0;
    for (int val : t.vecteur)
    {
        sum += val;
    }
    return static_cast<double>(sum) / t.vecteur.size();
}

// Fonction amie pour calculer la médiane des éléments du vecteur
double median(const Traitement &t)
{
    if (t.vecteur.empty())
        return 0.0;

    vector<int> sortedVect = t.vecteur;
    sort(sortedVect.begin(), sortedVect.end());

    size_t size = sortedVect.size();
    if (size % 2 == 0)
    {
        // Si la taille est paire, la médiane est la moyenne des deux éléments centraux
        return (sortedVect[size / 2 - 1] + sortedVect[size / 2]) / 2.0;
    }
    else
    {
        // Si la taille est impaire, la médiane est l'élément central
        return sortedVect[size / 2];
    }
}

int main()
{
    Traitement traitement;
    traitement.initialise();

    cout << "Éléments du vecteur : ";
    traitement.show();
    cout << endl;

    cout << "Moyenne des éléments : " << moyenne(traitement) << endl;
    cout << "Médiane des éléments : " << median(traitement) << endl;

    return 0;
}
