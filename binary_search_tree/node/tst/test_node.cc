#include "../../../../tst/test.h"
#include "../include/bst_node.h"

#define DUMMY_POINTER_LEFT 0x12345
#define DUMMY_POINTER_RIGHT 0x67891
#define DUMMY_POINTER_PARENT 0x01357

int test_BstNode ()
{
    BstNode n;
    ASSERT(n.num()==0);
    ASSERT(n.left()==NULL);
    ASSERT(n.right()==NULL);
    ASSERT(n.parent()==NULL);

    BstNode n2(100);
    ASSERT(n2.num()==100);
    ASSERT(n2.left()==NULL);
    ASSERT(n2.right()==NULL);
    ASSERT(n2.parent()==NULL);

    return 0;
}

int test_clear ()
{
    BstNode n;

    n.clear();
    ASSERT(n.num()==0);
    ASSERT(n.left()==NULL);
    ASSERT(n.right()==NULL);
    ASSERT(n.parent()==NULL);

    return 0;
}

int test_addLeft ()
{
    BstNode n;
    BstNode * dummy = (BstNode *) DUMMY_POINTER_LEFT;
    n.addLeft(dummy);
    ASSERT(n.left()==dummy);

    return 0;
}

int test_addRight ()
{
    BstNode n;
    BstNode * dummy = (BstNode *) DUMMY_POINTER_RIGHT;
    n.addRight(dummy);
    ASSERT(n.right()==dummy);

    return 0;
}

int test_addParent ()
{
    BstNode n;
    BstNode * dummy = (BstNode *) DUMMY_POINTER_PARENT;
    n.addParent(dummy);
    ASSERT(n.parent()==dummy);

    return 0;
}

int main (int argc, char * argv[])
{
    ASSERT(test_BstNode()==0);
    ASSERT(test_clear()==0);
    ASSERT(test_addLeft()==0);
    ASSERT(test_addRight()==0);
    ASSERT(test_addParent()==0);

    return 0;
}
