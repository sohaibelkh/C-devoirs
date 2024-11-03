#include <iostream>
#include <math.h>
using namespace std;

class Vecteur3d
{
private:
    float x;
    float y;
    float z;

public:
    Vecteur3d(float x, float y, float z) : x(0), y(0), z(0) {}

    void afficher() const
    {
        cout << "(" << x << "," << y << "," << z << ")" << endl;
    }

    Vecteur3d somme(Vecteur3d const other) const
    {
        return Vecteur3d(x + other.x, y + other.y, z + other.z);
    }

    // Somme : Retour par adresse
    Vecteur3d *somme_adresse(Vecteur3d *other) const
    {
        return new Vecteur3d(x + other->x, y + other->y, z + other->z);
    }

    // Somme : Retour par référence
    Vecteur3d &somme_reference(Vecteur3d &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    float produit_s(Vecteur3d const other) const
    {
        float result = x * other.x + y * other.y + z * other.z;
        return result;
    }

    bool coincide(Vecteur3d const other) const
    {
        return (x == other.x && y == other.y && z == other.z);
    }

    float norme() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    Vecteur3d normax(Vecteur3d const other) const
    {
        if (norme() > other.norme())
        {
            return *this;
        }
        else
        {
            return other;
        }
    }
};