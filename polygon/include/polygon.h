#ifndef CPP_POLYGON_H
#define CPP_POLYGON_H
#include <vector>
#include <utility>
using namespace std;

class PolygonIf
{
    public:
    virtual void display () const = 0;
    virtual float area () const = 0;
    virtual float perimeter () const = 0;
};

class Polygon : public PolygonIf
{
    public:
    virtual ~Polygon ();

    protected:
    vector<pair<float,float> > _coords;
};

#endif
