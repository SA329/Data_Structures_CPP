#include "../../../../tst/test.h"
#include "../include/bst_node.h"

int test_BstNode ()
{
    BstNode n;
    ASSERT(n.num()==0);
    ASSERT(n.left().isTerminalNode());
    ASSERT(n.right().isTerminalNode());
    ASSERT(n.parent().isTerminalNode());

    BstNode n2(100);
    ASSERT(n2.num()==100);
    ASSERT(n2.left().isTerminalNode());
    ASSERT(n2.right().isTerminalNode());
    ASSERT(n2.parent().isTerminalNode());

    return 0;
}

int test_clear ()
{
    BstNode n;

    n.clear();
    ASSERT(n.num()==0);
    ASSERT(n.left().isTerminalNode());
    ASSERT(n.right().isTerminalNode());
    ASSERT(n.parent().isTerminalNode());

    /*
    BstNode a(100);
    a.display();
    BstNode & r = a;
    r.display();
    BstNode k;
    r = k;
    k.display();
    r.display();
    */

    return 0;
}

int test_addLeft ()
{
    BstNode n;
    BstNode dummy;
    //dummy.display();
    std::cout << "before call to add left" << std::endl;
    n.addLeft(dummy);
    //ASSERT(!(n.left().isTerminalNode()));
    //n.left().display();
    //ASSERT(n.left()==dummy);

    return 0;
}

int test_addRight ()
{
    BstNode n;
    BstNode dummy;
    n.addRight(dummy);
    ASSERT(n.right()==dummy);

    return 0;
}

int test_addParent ()
{
    BstNode n;
    BstNode dummy;
    n.addParent(dummy);
    ASSERT(n.parent()==dummy);

    return 0;
}

int main (int argc, char * argv[])
{
    //ASSERT(test_BstNode()==0);
    //ASSERT(test_clear()==0);
    ASSERT(test_addLeft()==0);
    //ASSERT(test_addRight()==0);
    //ASSERT(test_addParent()==0);

    return 0;
}
