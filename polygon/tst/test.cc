#include "../include/rectangle.h"
#include "../include/triangle.h"
#include "../include/square.h"

int main (int argc, char * argv[])
{
    /*
    float p(0);
    float a(0);

    Triangle t(0);
    t.display();
    p = t.perimeter();
    a = t.area();

    Rectangle r;
    r.display();
    p = r.perimeter();
    a = r.area();

    Square s;
    s.display();
    p = s.perimeter();
    a = s.area();
    */

    vector<PolygonIf *> polygons;
    polygons.push_back(new Triangle(3));
    polygons.push_back(new Rectangle(3, 6));
    polygons.push_back(new Rectangle());
    polygons.push_back(new Square(4));

    for (
    vector<PolygonIf *>::const_iterator itr = polygons.begin();
    itr != polygons.end();
    ++itr)
    {
        (*itr)->display();
    }

    //TODO: need to delete the newed pointers

    return 0;
}
