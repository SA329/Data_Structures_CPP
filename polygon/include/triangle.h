#include "polygon.h"

class Triangle : public Polygon
{
    public:
    Triangle (int); // equilateral
    Triangle (int, int); // right
    Triangle (int, int, double); // general case
    ~Triangle ();

    pair<float,float> find_third_coordinate (
        const pair<float,float> &,
        const pair<float,float> &);
    void display () const;
    float area () const;
    float perimeter () const;

    private:
    void initialize (int, int, double);
};
