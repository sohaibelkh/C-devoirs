#include "point.h"
#include <iostream>
using namespace std;

int main()
{
    Point p(5, 7);
    p.affiche();
    p.deplace(10, 8);
    p.affiche();

    return 0;
}
