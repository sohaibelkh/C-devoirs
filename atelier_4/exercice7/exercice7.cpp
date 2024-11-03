#include <iostream>
using namespace std;

class Pile
{
private:
    // Structure pour représenter un nœud de la pile
    struct Node
    {
        int data;   // Contient la valeur à stocker
        Node *next; // Pointeur vers le prochain nœud
    };

    Node *sommet; // Pointeur vers le sommet de la pile

public:
    // Constructeur qui initialise une pile vide
    Pile() : sommet(nullptr) {}

    // Destructeur pour libérer la mémoire de la pile
    ~Pile()
    {
        while (sommet != nullptr)
        {
            pop(); // Vide la pile
        }
    }

    // Fonction push pour empiler un élément
    void push(int valeur)
    {
        Node *nouveau = new Node; // Crée un nouveau nœud
        nouveau->data = valeur;   // Assigne la valeur au nœud
        nouveau->next = sommet;   // Lien vers l'ancien sommet
        sommet = nouveau;         // Met à jour le sommet de la pile
        cout << "Empilé : " << valeur << endl;
    }

    // Fonction pop pour dépiler un élément
    int pop()
    {
        if (sommet == nullptr)
        {
            cout << "Erreur : la pile est vide !" << endl;
            return -1; // Renvoie une valeur spéciale en cas d'erreur
        }
        int valeur = sommet->data;   // Sauvegarde la valeur à retirer
        Node *ancienSommet = sommet; // Garde un pointeur vers l'ancien sommet
        sommet = sommet->next;       // Met à jour le sommet
        delete ancienSommet;         // Libère la mémoire de l'ancien sommet
        cout << "Dépilé : " << valeur << endl;
        return valeur; // Renvoie la valeur dépilée
    }

    // Fonction pour vérifier si la pile est vide
    bool estVide() const
    {
        return sommet == nullptr;
    }
};

int main()
{
    // Création de deux piles p1 et p2
    Pile p1;
    Pile p2;

    // Empilement d'éléments sur la pile p1
    p1.push(10);
    p1.push(20);
    p1.push(30);

    // Dépilement des éléments de la pile p1
    while (!p1.estVide())
    {
        p1.pop();
    }

    // Empilement d'éléments sur la pile p2
    p2.push(100);
    p2.push(200);

    // Dépilement des éléments de la pile p2
    while (!p2.estVide())
    {
        p2.pop();
    }
}