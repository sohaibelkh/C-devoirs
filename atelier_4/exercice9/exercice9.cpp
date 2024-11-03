#include <iostream>

struct Element
{
    int data;
    Element *next;

    Element(int value) : data(value), next(nullptr) {}
};

// Classe pour la liste simplement chaînée
class LinkedList
{
private:
    Element *head; // Pointeur vers le premier élément de la liste

public:
    // Constructeur pour initialiser une liste vide
    LinkedList() : head(nullptr) {}

    // Destructeur pour libérer la mémoire allouée dynamiquement
    ~LinkedList()
    {
        Element *current = head;
        while (current != nullptr)
        {
            Element *nextElement = current->next;
            delete current;
            current = nextElement;
        }
    }

    // Méthode pour ajouter un élément au début de la liste
    void add(int value)
    {
        Element *newElement = new Element(value);
        newElement->next = head;
        head = newElement;
    }

    // Méthode pour supprimer un élément du début de la liste
    void remove()
    {
        if (head != nullptr)
        {
            Element *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            std::cout << "La liste est déjà vide." << std::endl;
        }
    }

    // Méthode pour afficher tous les éléments de la liste
    void display() const
    {
        Element *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

// Exemple d'utilisation de la classe LinkedList
int main()
{
    LinkedList list;

    // Ajouter des éléments
    list.add(10);
    list.add(20);
    list.add(30);

    // Afficher la liste
    std::cout << "Liste après ajouts: ";
    list.display();

    // Supprimer un élément
    list.remove();
    std::cout << "Liste après suppression d'un élément: ";
    list.display();

    return 0;
}
