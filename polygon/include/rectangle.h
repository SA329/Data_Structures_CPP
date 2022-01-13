#include "polygon.h"

class Rectangle : public Polygon
{
    public:
    Rectangle ();
    ~Rectangle ();

    void display () const;
    float area () const;
    float perimeter () const;

    private:
};
