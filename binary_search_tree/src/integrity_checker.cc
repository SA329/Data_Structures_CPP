#include "../include/integrity_checker.h"
#include "../include/binary_search_tree.h"
#include "../node/include/bst_node.h"
#include <iostream>
using namespace std;

// Public Methods:
IntegrityChecker::IntegrityChecker ()
{
}

IntegrityChecker::~IntegrityChecker ()
{
}

bool IntegrityChecker::execute (const Bst & t) const
{
    if (t.isEmpty())
        return checkEmptyTree(t);

    if (!checkParent(t, t._root))
        return false;

    if (!checkOrder(*(t._root)))
        return false;

    return true;
}

void IntegrityChecker::breakParent (Bst * t, int num)
{
    if (t == NULL)
        return;

    if (num == 0)
        breakParentOfRootNode(t);
    else
        breakParentOfNonRootNode(t, num);
}

// Private Methods:
bool IntegrityChecker::checkEmptyTree (const Bst & t) const
{
    if (t._root != NULL)
    {
        cerr << "ERROR: IntegrityChecker::execute(...): tree is empty but root is not NULL!" << endl;
        return false;
    }

    if (t.size() != 0)
    {
        cerr << "ERROR: IntegrityChecker::execute(...): tree is empty but size is not 0!" << endl;
        return false;
    }

    return true;
}

void IntegrityChecker::breakParentOfRootNode (Bst * t)
{
    BstNode * const dummy = (BstNode *) 0x123;
    t->_root->addParent(dummy);
}

void IntegrityChecker::breakParentOfNonRootNode (Bst * t, int num)
{
    BstNode * const n = findNodeToBreak(*t, num);

    if (n != NULL)
        n->addParent(NULL);
}

BstNode * IntegrityChecker::findNodeToBreak (const Bst & t, int num) const
{
    BstNode * result = NULL;
    BstNode * n = t._root;

    while (n != NULL)
    {
        if (num == n->num())
        {
            result = n;
            break;
        }

        if (num < n->num())
            n = n->left();
        else 
            n = n->right();
    }

    return result;
}

bool IntegrityChecker::checkLessThan (const BstNode * s, int num) const
{
    if (s == NULL)
        return true;

    if (!isLessThan(*s, num))
    {
        cerr << "failed in checkLessThan(...)" << endl;
        return false;
    }

    return 
        checkLessThan(s->left(), num) && checkLessThan(s->right(), num);
}

bool IntegrityChecker::isLessThan (const BstNode & n, int num) const
{
    if (n.num() > num)
    {
        cerr << "ERROR: IntegrityChecker::isLessThan(...): expected " << n.num() << " < " << num << endl;
        return false;
    }

    return true;
}

bool IntegrityChecker::checkGreaterThan (const BstNode * s, int num) const
{
    if (s == NULL)
        return true;

    if (!isGreaterThan(*s, num))
    {
        cerr << "failed in checkGreaterThan(...)" << endl;
        return false;
    }

    return 
        checkGreaterThan(s->left(), num) && 
        checkGreaterThan(s->right(), num);
}

bool IntegrityChecker::isGreaterThan (const BstNode & n, int num) const
{
    if (n.num() < num)
    {
        cerr << "ERROR: IntegrityChecker::isGreaterThan(...): expected " << n.num() << " > " << num << endl;
        return false;
    }

    return true;
}

bool IntegrityChecker::checkParent (const Bst & t, const BstNode * n) const
{
    if (n == NULL)
        return true;

    if (!(rootNodeParentIsNull(t, *n) && nodeParentIsNotNull(t, *n)))
        return false;

    return checkParent(t, n->left()) && 
           checkParent(t, n->right());

    return true;
}

bool IntegrityChecker::nodeParentIsNotNull (
    const Bst & t, 
    const BstNode & n) const
{
    if (&n != t._root)
    {
        if (n.parent() == NULL)
        {
            cerr << "ERROR: IntegrityChecker::execute(...): node's parent is NULL! " << n.parent() << endl;
            return false;
        }
    }

    return true;
}

bool IntegrityChecker::rootNodeParentIsNull (
    const Bst & t, const BstNode & n) const
{
    if (&n == t._root)
    {
        if (n.parent() != NULL)
        {
            cerr << "ERROR: IntegrityChecker:: execute(...): root's parent is not NULL! " << n.parent() << endl;
            return false;
        }
    }

    return true;
}

bool IntegrityChecker::checkOrderImpl (const BstNode * p) const
{
    if (p == NULL)
        return true;

    int p_num = p->num();
    if (p->left() != NULL)
    {
        const BstNode & leftNode = *(p->left());
    }
    BstNode * left = p->left();
    BstNode * right = p->right();

    if (left == NULL)
    {
        if (right == NULL)
            return true;
        else // left null; right !null
        {
            if (!isGreaterThan(*right, p_num))
                return false;
            // else: keep going
        }
    }
    else
    {
        if (right == NULL) // left !null; right null
            return isLessThan(*left, p_num);
        else // both !null
        {
            if (!(isLessThan(*left, p_num) && isGreaterThan(*right, p_num)))
                return false;
            // else: keep going
        }
    }

    return checkOrderImpl(left) && checkOrderImpl(right);
}

bool IntegrityChecker::checkOrder (const BstNode & p) const
{
    int num = p.num();

    return checkLessThan(p.left(), num) &&
           checkGreaterThan(p.right(), num) &&
           checkOrderImpl(&p);
}
