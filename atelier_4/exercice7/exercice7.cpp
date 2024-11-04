#include <iostream>
using namespace std;

class Pile
{
private:
    struct Node
    {
        int data;
        Node *next;
    };

    Node *sommet;

public:
    Pile() : sommet(nullptr) {}

    ~Pile()
    {
        while (sommet != nullptr)
        {
            pop();
        }
    }

    void push(int valeur)
    {
        Node *nouveau = new Node;
        nouveau->data = valeur;
        nouveau->next = sommet;
        sommet = nouveau;
        cout << "Empilé : " << valeur << endl;
    }

    int pop()
    {
        if (sommet == nullptr)
        {
            cout << "Erreur : la pile est vide !" << endl;
            return -1;
        }
        int valeur = sommet->data;
        Node *ancienSommet = sommet;
        sommet = sommet->next;
        delete ancienSommet;
        cout << "Dépilé : " << valeur << endl;
        return valeur;
    }

    bool estVide() const
    {
        return sommet == nullptr;
    }
};

int main()
{

    Pile p1;
    Pile p2;

    p1.push(10);
    p1.push(20);
    p1.push(30);

    while (!p1.estVide())
    {
        p1.pop();
    }

    p2.push(100);
    p2.push(200);

    while (!p2.estVide())
    {
        p2.pop();
    }
}