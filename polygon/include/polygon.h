#include <vector>
using namespace std;

class PolygonIf
{
    public:
    virtual ~PolygonIf ();

    virtual void display () const = 0;
    virtual float area () const = 0;
    virtual float perimeter () const = 0;
};

class Polygon : public class PolygonIf
{
    public:
    virtual ~Polygon ();

    protected:
    vector<Line> _lines;
};

class Triangle : public class Polygon
{
    public:
    Triangle ();
    ~Triangle ();

    void display () const;
    float area () const;
    float perimeter () const;

    private:
};

class Rectangle : public class Polygon
{
    public:
    Rectangle ();
    ~Rectangle ();

    void display () const;
    float area () const;
    float perimeter () const;

    private:
};
