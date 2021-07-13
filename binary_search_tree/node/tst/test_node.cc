#include "../../../../tst/test.h"
#include "../include/bst_node.h"

#define DUMMY_POINTER_LEFT 0x12345
#define DUMMY_POINTER_RIGHT 0x67891
#define DUMMY_POINTER_PARENT 0x01357

struct bst_node * gn = NULL; // our global node

bool setup ()
{
    gn = bst_node_create();
    return gn != NULL;
}
 
bool teardown ()
{
    bst_node_delete(&gn);
    return gn == NULL;
}

int test_bst_node_create ()
{
    struct bst_node * n = bst_node_create();
    ASSERT(n!=NULL);
    ASSERT(bst_node_check_integrity(n));

    bst_node_delete(&n);
    ASSERT(n==NULL);

    return 0;
}

int test_bst_node_clear ()
{
    bst_node_clear(NULL); // just making sure it doesn't blow up

    ASSERT(setup());

    bst_node_set_num(gn, 6);
    ASSERT(bst_node_check_integrity(gn));

    bst_node_clear(gn);
    ASSERT(gn!=NULL);
    ASSERT(bst_node_check_integrity(gn));

    // Testing for when already clear.
    bst_node_clear(gn);
    ASSERT(gn!=NULL);
    ASSERT(bst_node_check_integrity(gn));

    ASSERT(teardown());

    return 0;
}

int test_bst_node_delete ()
{
    bst_node_delete(NULL); // just making sure it doesn't blow up

    ASSERT(setup());

    bst_node_set_num(gn, 6);
    ASSERT(bst_node_check_integrity(gn));

    bst_node_delete(&gn);
    ASSERT(gn==NULL);

    ASSERT(teardown());

    return 0;
}

int test_bst_node_num ()
{
    ASSERT(bst_node_num(NULL)==0);

    ASSERT(setup());

    bst_node_set_num(gn, 6);
    ASSERT(bst_node_num(gn)==6);
    
    ASSERT(teardown());

    return 0;
}

int test_bst_node_left ()
{
    ASSERT(bst_node_left(NULL)==NULL);

    ASSERT(setup());

    struct bst_node * dummy_ptr = (struct bst_node *) DUMMY_POINTER_LEFT;

    bst_node_set_left(gn, dummy_ptr);
    ASSERT(bst_node_left(gn)==dummy_ptr);
    
    ASSERT(teardown());

    return 0;
}

int test_bst_node_right ()
{
    ASSERT(bst_node_right(NULL)==NULL);

    ASSERT(setup());

    struct bst_node * dummy_ptr = (struct bst_node *) DUMMY_POINTER_RIGHT;

    bst_node_set_right(gn, dummy_ptr);
    ASSERT(bst_node_right(gn)==dummy_ptr);
    
    ASSERT(teardown());

    return 0;
}

int test_bst_node_parent ()
{
    ASSERT(bst_node_parent(NULL)==NULL);

    ASSERT(setup());

    struct bst_node * dummy_ptr = (struct bst_node *) DUMMY_POINTER_PARENT;

    bst_node_set_parent(gn, dummy_ptr);
    ASSERT(bst_node_parent(gn)==dummy_ptr);
    
    ASSERT(teardown());

    return 0;
}

int main (int argc, char * argv[])
{
    ASSERT(test_bst_node_create()==0);

    ASSERT(test_bst_node_clear()==0);
    ASSERT(test_bst_node_delete()==0);

    ASSERT(test_bst_node_num()==0);

    ASSERT(test_bst_node_left()==0);
    ASSERT(test_bst_node_right()==0);

    ASSERT(test_bst_node_parent()==0);

    return 0;
}
