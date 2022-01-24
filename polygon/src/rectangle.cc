#include "../include/rectangle.h"
#include <iostream>
#include <ostream>

Rectangle::Rectangle ()
{
    cout << "Inside Rectangle::Rectangle ()" << endl;
    initialize(3, 6);
}

Rectangle::Rectangle (float l, float w)
{
    cout << "Inside Rectangle::Rectangle (float, float)" << endl;
    initialize(l, w);
}

void Rectangle::initialize (float l, float w)
{
    /*
    pair<int,int> p1(0,0);
    pair<int,int> p2(0,2);
    pair<int,int> p3(4,2);
    pair<int,int> p4(4,0);

    _lines.push_back(p1);
    _lines.push_back(p2);
    _lines.push_back(p3);
    _lines.push_back(p4);
    */
}

Rectangle::~Rectangle ()
{
    cout << "Inside Rectangle::~Rectangle ()" << endl;
}

void Rectangle::display () const
{
    cout << "Inside Rectangle::display() const" << endl;
}

float Rectangle::area () const
{
    cout << "Inside Rectangle::area() const" << endl;
    return 0;
}

float Rectangle::perimeter () const
{
    cout << "Inside Rectangle::perimeter() const" << endl;
    return 0;
}
