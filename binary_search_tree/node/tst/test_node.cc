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

int test_add_left ()
{
    BstNode n;
    BstNode * dummy = (BstNode *) DUMMY_POINTER_LEFT;
    n.add_left(dummy);
    ASSERT(n.left()==dummy);

    return 0;
}

int test_add_right ()
{
    BstNode n;
    BstNode * dummy = (BstNode *) DUMMY_POINTER_RIGHT;
    n.add_right(dummy);
    ASSERT(n.right()==dummy);

    return 0;
}

int test_add_parent ()
{
    BstNode n;
    BstNode * dummy = (BstNode *) DUMMY_POINTER_PARENT;
    n.add_parent(dummy);
    ASSERT(n.parent()==dummy);

    return 0;
}

int main (int argc, char * argv[])
{
    ASSERT(test_BstNode()==0);
    ASSERT(test_clear()==0);
    ASSERT(test_add_left()==0);
    ASSERT(test_add_right()==0);
    ASSERT(test_add_parent()==0);

    return 0;
}
