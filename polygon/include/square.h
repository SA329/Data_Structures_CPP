#include "rectangle.h"

class Square : public PolygonIf
{
    public:
    Square ();
    Square (float);
    virtual ~Square ();

    void display () const;
    float area () const;
    float perimeter () const;

    private:
    Rectangle * _r;

    void initialize (float);
};
