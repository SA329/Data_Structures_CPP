#include "../../../tst/test.h"
#include "../include/binary_search_tree.h"
#include "../include/integrity_checker.h"

IntegrityChecker gc;
Bst * gt; // our global binary search tree

#define NBR_TREE_DATA_ELEMENTS 15
int treeData[NBR_TREE_DATA_ELEMENTS] =
{
    10, 5, 1, 7, 9, 6, 20, 18, 30, 25, 22, 28, 35, 33, 40
};
#define EXTRA_DATA_NUM 99

bool loadTree (Bst & t)
{
    for (int i = 0; i < NBR_TREE_DATA_ELEMENTS; ++i)
    {
        if (t.insert(treeData[i]) != Bst::SUCCESS)
            return false;
    }

    return gc.execute(t);
}

bool setup ()
{
    gt = new Bst;
    return gt != NULL;
}
 
bool teardown ()
{
    delete gt;
    gt = NULL;
    return true;
}

int testBstCreate ()
{
    Bst t;
    ASSERT(t.isEmpty());
    ASSERT(gc.execute(t));

    /*
    //Commenting this because it generates 2 errors. Uncomment this if you want to see them.

    // broken root node's parent
    Bst r;
    ASSERT(r.isEmpty());
    ASSERT(gc.execute(r));

    ASSERT(loadTree(r));
    gc.breakParent(&r, 0);
    ASSERT(!(gc.execute(r)));

    // broken non-root node's parent
    ASSERT(setup());

    ASSERT(loadTree(*gt));
    gc.breakParent(gt, treeData[8]);
    ASSERT(!(gc.execute(*gt)));

    ASSERT(teardown());
    */

    return 0;
}

int testBstClear ()
{
    ASSERT(setup());

    // empty tree
    gt->clear();
    ASSERT(gc.execute(*gt));
    ASSERT(gt->isEmpty());

    // size 1 tree
    ASSERT(gt->insert(EXTRA_DATA_NUM) == Bst::SUCCESS);
    gt->clear();
    ASSERT(gt->isEmpty());
    ASSERT(gc.execute(*gt));

    ASSERT(loadTree(*gt));

    // default
    gt->clear();
    ASSERT(gt->isEmpty());
    ASSERT(gc.execute(*gt));

    ASSERT(teardown());

    return 0;
}

int testBstSize ()
{
    ASSERT(setup());
    ASSERT(gt->size()==0);

    ASSERT(loadTree(*gt));
    ASSERT(gt->size()==NBR_TREE_DATA_ELEMENTS);

    ASSERT(teardown());

    return 0;
}

int testBstIsEmpty ()
{
    ASSERT(setup());
    ASSERT(loadTree(*gt));
    ASSERT(!gt->isEmpty());

    gt->clear();
    ASSERT(gt->isEmpty());

    ASSERT(teardown());

    return 0;
}

int testBstInsert ()
{
    ASSERT(setup());

    // empty tree:
    ASSERT(gt->isEmpty());
    ASSERT(gt->insert(EXTRA_DATA_NUM)==Bst::SUCCESS);
    ASSERT(gc.execute(*gt));
    ASSERT(gt->size()==1);

    ASSERT(gt->remove(EXTRA_DATA_NUM)==Bst::SUCCESS);
    ASSERT(gc.execute(*gt));
    ASSERT(gt->isEmpty());

    // general case:
    ASSERT(loadTree(*gt));
    ASSERT(gt->size()==NBR_TREE_DATA_ELEMENTS);

    // duplicate node:
    ASSERT(gt->insert(treeData[5]) == Bst::NODE_DUPLICATE);
    ASSERT(gc.execute(*gt));
    ASSERT(gt->size()==NBR_TREE_DATA_ELEMENTS);

    ASSERT(teardown());

    return 0;
}

int testBstRemove ()
{
    ASSERT(setup());

    // removing node in empty tree:
    ASSERT(gt->isEmpty());
    ASSERT(gt->remove(treeData[0]) == Bst::TREE_EMPTY);
    ASSERT(gc.execute(*gt));
    ASSERT(gt->isEmpty());

    // removing node in tree with size 1:
    ASSERT(gt->insert(treeData[0]) == Bst::SUCCESS);
    ASSERT(gt->remove(treeData[0]) == Bst::SUCCESS);
    ASSERT(gt->isEmpty());
    ASSERT(gc.execute(*gt));

    ASSERT(loadTree(*gt));

    // removing root when size > 1:
    int size = NBR_TREE_DATA_ELEMENTS;
    ASSERT(gt->remove(treeData[0]) == Bst::SUCCESS);
    ASSERT(gt->search(treeData[0]) == Bst::NODE_NOT_FOUND);
    ASSERT(gc.execute(*gt));
    ASSERT(gt->size()==size-1);
    size--;

    // attempt to remove node not in tree
    ASSERT(gt->remove(EXTRA_DATA_NUM) == Bst::NODE_NOT_FOUND);

    // general case:
    ASSERT(gt->remove(treeData[8]) == Bst::SUCCESS);
    ASSERT(gt->search(treeData[8]) == Bst::NODE_NOT_FOUND);
    ASSERT(gc.execute(*gt));
    ASSERT(gt->size()==size-1);
    size--;

    // remove leaf node:
    ASSERT(gt->remove(treeData[14]) == Bst::SUCCESS);
    ASSERT(gt->search(treeData[14]) == Bst::NODE_NOT_FOUND);
    ASSERT(gc.execute(*gt));
    ASSERT(gt->size()==size-1);

    ASSERT(teardown());

    return 0;
}

int testBstSearch ()
{
    ASSERT(setup());

    ASSERT(loadTree(*gt));
    for (int i = 0; i < NBR_TREE_DATA_ELEMENTS; ++i)
    {
        ASSERT(gt->search(treeData[i]));
    }

    ASSERT(teardown());

    return 0;
}

int main (int argc, char * argv[])
{
    ASSERT(testBstCreate()==0);
    ASSERT(testBstClear()==0);
    ASSERT(testBstSize()==0);
    ASSERT(testBstIsEmpty()==0);
    ASSERT(testBstInsert()==0);
    ASSERT(testBstRemove()==0);
    ASSERT(testBstSearch()==0);

    return 0;
}
