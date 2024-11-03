#define POINT_H_INCLUDED
#include <iostream>
using namespace std;

class Point
{
private:
    float p1;
    float p2;

public:
    Point(float x, float y) : p1(x), p2(y) {}
    void deplace(float x, float y);
    void affiche();
};