#ifndef CPP_RECTANGLE_H
#define CPP_RECTANGLE_H
#include "polygonif.h"
#include <vector>
#include <utility>
using namespace std;

class Rectangle : public PolygonIf
{
    public:
    Rectangle ();
    Rectangle (float, float);
    virtual ~Rectangle ();

    void display () const;
    float area () const;
    float perimeter () const;

    private:
    void initialize (float, float);
    vector<pair<float,float> > _coords;
};

#endif
