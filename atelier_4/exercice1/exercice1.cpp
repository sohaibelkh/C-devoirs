#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
public:
    double real;
    double imag;

public:
    Complex conjuguee() const
    {
        return Complex(real, -imag);
    }

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    bool isEqual(Complex other) const
    {
        if (real == other.real && imag == other.imag)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Complex add(Complex other) const
    {
        double result_r = real + other.real;
        double result_i = imag + other.imag;
        Complex result(result_r, result_i);
        return result;
    }

    Complex sous(Complex other) const
    {
        double result_r = real - other.real;
        double result_i = imag - other.imag;
        Complex result(result_r, result_i);
        return result;
    }

    Complex multi(Complex other) const
    {
        double result_r = real * other.real;
        double result_i = imag * other.imag + imag * other.real;
        Complex result(result_r, result_i);
        return result;
    }

    Complex divis(Complex other) const
    {
        Complex conj_b = other.conjuguee();
        Complex numerateur = this->multi(conj_b);
        double denominateur = other.real * other.real + other.imag * other.imag;
        return Complex(numerateur.real / denominateur, numerateur.imag / denominateur);
    }
};

int main()
{
    Complex c1;
    Complex c2;
    int choix;

    cout << "Donner le promier nombre complex : " << endl;
    cout << "Reel : ";
    cin >> c1.real;
    cout << "Imaginaire : ";
    cin >> c1.imag;
    cout << "Donner le deuxieme nombre complex : " << endl;
    cout << "Reel : ";
    cin >> c2.real;
    cout << "Imaginaire : ";
    cin >> c2.imag;

    cout << "voila notre menu, choisir :" << endl;
    cout << "1-Egalite" << endl;
    cout << "2-Addition" << endl;
    cout << "3-Soustraction" << endl;
    cout << "4-Multiplication" << endl;
    cout << "5-Division" << endl;
    cin >> choix;

    switch (choix)
    {
    case 1:
    {
        bool isEqual = c1.isEqual(c2);
        if (isEqual)
        {
            cout << "Les nombres sont egales" << endl;
        }
        else
        {
            cout << "Les nombres ne sont pas egales" << endl;
        }
        break;
    }

    case 2:
    {
        cout << "Addition : ";
        Complex addresult = c1.add(c2);
        cout << addresult.real << " + " << addresult.imag << "i" << endl;
        break;
    }

    case 3:
    {
        cout << "Soustraction : ";
        Complex sousresult = c1.sous(c2);
        cout << sousresult.real << " + " << sousresult.imag << "i" << endl;
        break;
    }

    case 4:
    {
        cout << "Multiplication : ";
        Complex multiresult = c1.multi(c2);
        cout << multiresult.real << " + " << multiresult.imag << "i" << endl;
        break;
    }

    case 5:
    {
        cout << "Division : ";
        Complex divresult = c1.divis(c2);
        cout << divresult.real << " + " << divresult.imag << "i" << endl;
        break;
    }

    default:
        cout << "Choix invalide." << endl;
        break;
    }
}