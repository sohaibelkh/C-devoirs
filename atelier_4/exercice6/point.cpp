#include <iostream>
#include <cmath>
#include <point.h>
using namespace std;

void Point ::deplace(float x, float y)
{
    p1 += x;
    p2 += y;
}

void Point ::affiche()
{
    cout << "(" << p1 << ", " << p2 << ")" << endl;
}
