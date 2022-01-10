#include "../include/polygon.h"

Polygon::~Polygon ()
{
}

Triangle::Triangle ()
{
    pair<int,int> p1(0,0);
    pair<int,int> p2(2,2);
    pair<int,int> p3(4,0);

    _lines.push_back(p1);
    _lines.push_back(p2);
    _lines.push_back(p3);
}

Triangle::~Triangle ()
{
}

void Triangle::display () const
{
}

float Triangle::area () const
{
    return 0;
}

float Triangle::perimeter () const
{
    return 0;
}
