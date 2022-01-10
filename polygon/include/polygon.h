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
    vector<pair<int,int> > _lines;
};

class Triangle : public Polygon
{
    public:
    Triangle ();
    ~Triangle ();

    void display () const;
    float area () const;
    float perimeter () const;

    private:
};

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
