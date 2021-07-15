#include "../../../../tst/test.h"
#include "../include/bst_node.h"
using namespace std;

int main ()
{
    class bst_node n1;
    n1.display();
    class bst_node * n2 = new class bst_node;
    n2->display();
    class bst_node n3(100);
    n3.display();

    cout << "finished creating nodes" << endl;
    delete n2;
};
