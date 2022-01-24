#ifndef CPP_POLYGONIF_H
#define CPP_POLYGONIF_H

class PolygonIf
{
    public:
    virtual void display () const = 0;
    virtual float area () const = 0;
    virtual float perimeter () const = 0;
};

#endif
