#include "../include/triangle.h"
#include <iostream>
#define RIGHT_ANGLE 90
#define EQUILATERAL_ANGLE 60

Triangle::Triangle (int l)
{
    cout << "Inside Triangle::Triangle (int)" << endl;
    initialize(l, l, EQUILATERAL_ANGLE);
}

Triangle::Triangle (int a, int b)
{
    cout << "Inside Triangle::Triangle (int, int)" << endl;
    initialize(a, b, RIGHT_ANGLE);
}

Triangle::Triangle (int a, int b, double angle)
{
    cout << "Inside Triangle::Triangle (int, int, double)" << endl;
    initialize(a, b, angle);
}

Triangle::~Triangle ()
{
    cout << "Inside Triangle::~Triangle ()" << endl;
}

void Triangle::initialize (int a, int b, double angle)
{
    //a2 = b2 + c2 − 2bc cosA TODO: use this formula and other stuff to figure out the third coordinate given two sides and an angle.

    /*
    pair<float,float> p1(0,0);
    pair<float,float> p2(0,0);
    pair<float,float> p3(0,0);

    _coords.push_back(p1);
    _coords.push_back(p2);
    _coords.push_back(p3);
    */
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
    cout << "Inside Triangle::display() const;" << endl;
}

float Triangle::area () const
{
    cout << "Inside Triangle::area() const;" << endl;
    return 0;
}

float Triangle::perimeter () const
{
    cout << "Inside Triangle:perimeter() const;" << endl;
    return 0;
}
