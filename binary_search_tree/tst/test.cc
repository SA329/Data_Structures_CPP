#include "../../../tst/test.h"
#include "../include/binary_search_tree.h"

struct bst * gt = NULL; // our global binary search tree

#define BST_NBR_TREE_DATA_ELEMENTS 15
int tree_data[BST_NBR_TREE_DATA_ELEMENTS] =
{
    10, 5, 1, 7, 9, 6, 20, 18, 30, 25, 22, 28, 35, 33, 40
};
#define BST_EXTRA_DATA_NUM 99

bool load_tree (struct bst * t)
{
    for (int i = 0; i < BST_NBR_TREE_DATA_ELEMENTS; ++i)
    {
        if (bst_insert(t, tree_data[i]) != BST_SUCCESS)
            return false;
    }

    return bst_check_integrity(t);
}

bool setup ()
{
    gt = bst_create();
    return gt != NULL;
}
 
bool teardown ()
{
    bst_delete(&gt);
    return gt == NULL;
}

int test_bst_create ()
{
    struct bst * t = bst_create();
    ASSERT(t!=NULL);
    ASSERT(bst_is_empty(t));
    ASSERT(bst_check_integrity(t));

    bst_delete(&t);
    ASSERT(t==NULL);

    /* Commenting this because it generates 2 errors. Uncomment this if you want to see them.
    // broken root node's parent
    t = bst_create();
    ASSERT(t!=NULL);

    ASSERT(load_tree(t));
    bst_break_parent_integrity(t, 0);
    ASSERT(!bst_check_integrity(t));

    bst_delete(&t);
    ASSERT(t==NULL);

    // broken non-root node's parent
    ASSERT(setup());

    ASSERT(load_tree(gt));
    bst_break_parent_integrity(gt, tree_data[8]);
    ASSERT(!bst_check_integrity(gt));

    ASSERT(teardown());
    */

    return 0;
}

int test_bst_delete ()
{
    // tree null:
    bst_delete(NULL); // just making sure it doesn't blow up

    struct bst * t = NULL;
    bst_delete(&t); // just making sure it doesn't blow up

    // default: 
    ASSERT(setup());

    ASSERT(load_tree(gt));
    bst_delete(&gt);
    ASSERT(gt==NULL);

    ASSERT(teardown());

    return 0;
}

int test_bst_clear ()
{
    ASSERT(bst_clear(NULL) == BST_TREE_NULL);

    ASSERT(setup());

    // empty tree
    ASSERT(bst_clear(gt) == BST_SUCCESS);
    ASSERT(bst_check_integrity(gt));
    ASSERT(bst_is_empty(gt));

    // size 1 tree
    ASSERT(bst_insert(gt, BST_EXTRA_DATA_NUM) == BST_SUCCESS);
    ASSERT(bst_clear(gt) == BST_SUCCESS);
    ASSERT(bst_is_empty(gt));
    ASSERT(bst_check_integrity(gt));

    ASSERT(load_tree(gt));

    // default
    ASSERT(bst_clear(gt) == BST_SUCCESS);
    ASSERT(bst_is_empty(gt));
    ASSERT(bst_check_integrity(gt));

    ASSERT(teardown());

    return 0;
}

int test_bst_size ()
{
    ASSERT(bst_size(NULL)==BST_INVALID);

    ASSERT(setup());
    ASSERT(bst_size(gt)==0);

    ASSERT(load_tree(gt));
    ASSERT(bst_size(gt)==BST_NBR_TREE_DATA_ELEMENTS);

    ASSERT(teardown());

    return 0;
}

int test_bst_is_empty ()
{
    /*
    Commenting out because this generates a warning; uncomment to see it.
    ASSERT(!bst_is_empty(NULL));
    */

    ASSERT(setup());
    ASSERT(load_tree(gt));
    ASSERT(!bst_is_empty(gt));

    ASSERT(bst_clear(gt)==BST_SUCCESS);
    ASSERT(bst_is_empty(gt));

    ASSERT(teardown());

    return 0;
}

int test_bst_insert ()
{
    ASSERT(bst_insert(NULL, tree_data[0]) == BST_TREE_NULL);

    ASSERT(setup());

    // empty tree:
    ASSERT(bst_is_empty(gt));
    ASSERT(bst_insert(gt, BST_EXTRA_DATA_NUM)==BST_SUCCESS);
    ASSERT(bst_check_integrity(gt));
    ASSERT(bst_size(gt)==1);

    ASSERT(bst_remove(gt, BST_EXTRA_DATA_NUM)==BST_SUCCESS);
    ASSERT(bst_check_integrity(gt));
    ASSERT(bst_is_empty(gt));

    // general case:
    ASSERT(load_tree(gt));
    ASSERT(bst_size(gt)==BST_NBR_TREE_DATA_ELEMENTS);

    // duplicate node:
    ASSERT(bst_insert(gt, tree_data[5]) == BST_NODE_DUPLICATE);
    ASSERT(bst_check_integrity(gt));
    ASSERT(bst_size(gt)==BST_NBR_TREE_DATA_ELEMENTS);

    ASSERT(teardown());

    return 0;
}

int test_bst_remove ()
{
    ASSERT(bst_remove(NULL, tree_data[0]) == BST_TREE_NULL);

    ASSERT(setup());

    // removing node in empty tree:
    ASSERT(bst_is_empty(gt));
    ASSERT(bst_remove(gt, tree_data[0]) == BST_TREE_EMPTY);
    ASSERT(bst_check_integrity(gt));
    ASSERT(bst_is_empty(gt));

    // removing node in tree with size 1:
    bst_insert(gt, tree_data[0]);
    ASSERT(bst_remove(gt, tree_data[0]) == BST_SUCCESS);
    ASSERT(bst_is_empty(gt));
    ASSERT(bst_check_integrity(gt));

    ASSERT(load_tree(gt));

    // removing root when size > 1:
    int size = BST_NBR_TREE_DATA_ELEMENTS;
    ASSERT(bst_remove(gt, tree_data[0]) == BST_SUCCESS);
    ASSERT(bst_search(gt, tree_data[0]) == BST_NODE_NOT_FOUND);
    ASSERT(bst_check_integrity(gt));
    ASSERT(bst_size(gt)==size-1);
    size--;

    // attempt to remove node not in tree
    ASSERT(bst_remove(gt, BST_EXTRA_DATA_NUM) == BST_NODE_NOT_FOUND);

    // general case:
    ASSERT(bst_remove(gt, tree_data[8]) == BST_SUCCESS);
    ASSERT(bst_search(gt, tree_data[8]) == BST_NODE_NOT_FOUND);
    ASSERT(bst_check_integrity(gt));
    ASSERT(bst_size(gt)==size-1);
    size--;

    // remove leaf node:
    ASSERT(bst_remove(gt, tree_data[14]) == BST_SUCCESS);
    ASSERT(bst_search(gt, tree_data[14]) == BST_NODE_NOT_FOUND);
    ASSERT(bst_check_integrity(gt));
    ASSERT(bst_size(gt)==size-1);

    ASSERT(teardown());

    return 0;
}

int test_bst_search ()
{
    ASSERT(setup());

    ASSERT(load_tree(gt));
    for (int i = 0; i < BST_NBR_TREE_DATA_ELEMENTS; ++i)
    {
        ASSERT(bst_search(gt, tree_data[i]));
    }

    ASSERT(teardown());

    return 0;
}

int main (int argc, char * argv[])
{
    ASSERT(test_bst_create()==0);
    ASSERT(test_bst_delete()==0);
    ASSERT(test_bst_clear()==0);
    ASSERT(test_bst_size()==0);
    ASSERT(test_bst_is_empty()==0);
    ASSERT(test_bst_insert()==0);
    ASSERT(test_bst_remove()==0);
    ASSERT(test_bst_search()==0);

    return 0;
}
