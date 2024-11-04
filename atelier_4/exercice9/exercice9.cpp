#include <iostream>

struct Element
{
    int data;
    Element *next;

    Element(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Element *head;

public:
    LinkedList() : head(nullptr) {}

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

    void add(int value)
    {
        Element *newElement = new Element(value);
        newElement->next = head;
        head = newElement;
    }

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

int main()
{
    LinkedList list;

    list.add(10);
    list.add(20);
    list.add(30);

    std::cout << "Liste après ajouts: ";
    list.display();

    list.remove();
    std::cout << "Liste après suppression d'un élément: ";
    list.display();

    return 0;
}
