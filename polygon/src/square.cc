#include "../include/square.h"
#include <iostream>
#include <ostream>

Square::Square ()
{
    cout << "Inside Square::Square ()" << endl;
    initialize(10);
}

Square::Square (float s)
{
    cout << "Inside Square::Square (float)" << endl;
    initialize(s);
}

void Square::initialize (float s)
{
    _r = new Rectangle(s, s);
}

Square::~Square ()
{
    cout << "Inside Square::~Square ()" << endl;
    if (_r != NULL)
    {
        delete _r;
        _r = NULL;
    }
}

void Square::display () const
{
    cout << "Inside Square::display() const" << endl;
    _r->display();
}

float Square::area () const
{
    cout << "Inside Square::area() const" << endl;
    return _r->area();
}

float Square::perimeter () const
{
    cout << "Inside Square::perimeter() const" << endl;
    return _r->perimeter();
}
