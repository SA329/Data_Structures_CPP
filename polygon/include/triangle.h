#include "polygonif.h"
#include <vector>
#include <utility>
using namespace std;

class Triangle : public PolygonIf
{
    public:
    Triangle (int); // equilateral
    Triangle (int, int); // right
    Triangle (int, int, double); // general case
    virtual ~Triangle ();

    pair<float,float> find_third_coordinate (
        const pair<float,float> &,
        const pair<float,float> &);
    void display () const;
    float area () const;
    float perimeter () const;

    private:
    void initialize (int, int, double);
    vector<pair<float,float> > _coords;
};
