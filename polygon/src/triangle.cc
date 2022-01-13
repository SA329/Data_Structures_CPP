#include "../include/triangle.h"

Triangle::Triangle (int l)
{
    pair<float,float> p1(0,0);
    pair<float,float> p2(l/2,2);
    pair<float,float> p3(l,0);

    _coords.push_back(p1);
    _coords.push_back(p2);
    _coords.push_back(p3);
}

Triangle::~Triangle ()
{
}

pair<float,float> Triangle::find_third_coordinate (
    const pair<float,float> & p1,
    const pair<float,float> & p2)
{
    //TODO
    return make_pair<float,float> (0,0);
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
