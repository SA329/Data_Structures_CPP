#include "polygon.h"

class Triangle : public Polygon
{
    public:
    Triangle (int); // equilateral
    //Triangle (int, int, ); TODO: find difference between isoceles and right triangle.
    ~Triangle ();

    pair<float,float> find_third_coordinate (
        const pair<float,float> &,
        const pair<float,float> &);
    void display () const;
    float area () const;
    float perimeter () const;

    private:
};
