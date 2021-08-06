#include "../include/binary_search_tree.h"
#include "../node/include/bst_node.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define CHECK_NULL(n, error_string, ret_value) \
    if (n == NULL) \
    { \
        fprintf(stderr, error_string); \
        return ret_value; \
    }

Bst::Bst () : _root(NULL), _size(0)
{
}

Bst::~Bst ()
{
}

void Bst::clear ()
{
    clearImpl(_root);
    _root = NULL;
}

void Bst::clearImpl (BstNode * n)
{
   if (n == NULL)
       return; 

    clearImpl(n->left());
    clearImpl(n->right());

    delete n;
    _size--;
}

bool Bst::isEmpty () const
{
    return _size == 0;
}

unsigned int Bst::size () const
{
    return _size;
}

Bst::ReturnCode Bst::insert (int num)
{
    BstNode * n = new BstNode(num);

    ReturnCode result = insertNode(*n);

    if (result == SUCCESS)
        _size++;
    else
        delete n;

    return result;
}

Bst::ReturnCode Bst::insertNode (BstNode & n)
{
    if (isEmpty())
    {
        _root = &n;
        return SUCCESS;
    }

    BstNode * p = getInsertionPoint(n.num());
    if (p == NULL)
        return NODE_DUPLICATE;

    setNode(*p, n);

    return SUCCESS;
}

Bst::ReturnCode Bst::insertNode (BstNode * n)
{
    if (n == NULL)
        return NODE_NULL;

    return insertNode(*n);
}

void Bst::setNode (BstNode & p, BstNode & n)
{
    n.addParent(&p);

    if (n.num() < p.num())
         p.addLeft(&n); // insert left
    else 
         p.addRight(&n); // insert right
}

BstNode * Bst::getInsertionPoint (int num) const
{
   BstNode * p = NULL;
   BstNode * n = _root;
   for (; n != NULL; moveToNextNode(num, &n))
   {
        if (num == n->num())
            return NULL; // signals num is already in tree

        p = n;
   }

   return p;
}

void Bst::moveToNextNode (int num, BstNode ** n) const // *n should never be NULL
{
    if (num < (*n)->num())
        *n = (*n)->left();
    else 
        *n = (*n)->right();
}

Bst::ReturnCode Bst::remove (int num)
{
    if (isEmpty())
        return TREE_EMPTY;

    BstNode * n = findNodeToRemove(num);
    if (n == NULL)
        return NODE_NOT_FOUND;

    ReturnCode result = removeNode(*n);
    if (result != SUCCESS)
        return result;

    _size--;
    delete n;

    return result;
}

BstNode * Bst::findNodeToRemove (int num) const
{
   BstNode * n = _root;
   for (; n != NULL; moveToNextNode(num, &n))
   {
        if (num == n->num())
            break;
   }

   return n;
}

Bst::ReturnCode Bst::removeNode (BstNode & n)
{
    if (isRoot(n))
        return removeRoot(n);
    else
        return removeGeneralCase(n);
}

Bst::ReturnCode Bst::removeRoot (BstNode & n)
{
    if (n.left() != NULL)
        return rootTreeToLeftSubtree(n);
    else
        rootTreeToRightSubtree(n);

    return SUCCESS;
}

Bst::ReturnCode Bst::rootTreeToLeftSubtree (BstNode & n)
{
    setNewRoot(n.left());

    if (n.right() != NULL)
    {
        n.right()->addParent(NULL);
        return insertNode(n.right());
    }

    return SUCCESS;
}

void Bst::setNewRoot (BstNode * n)
{
    _root = n;
    if (_root != NULL)
        _root->addParent(NULL);
}

void Bst::rootTreeToRightSubtree (BstNode & n)
{
    setNewRoot(n.right());
}

Bst::ReturnCode Bst::removeGeneralCase (BstNode & n)
{
    disconnectNodeFromParent(n);
    return reinsertSubtreesOfNode(n);
}

void Bst::disconnectNodeFromParent (BstNode & n)
{
    if (isLeftChild(n))
        n.parent()->addLeft(NULL);
    else
        n.parent()->addRight(NULL);
}

bool Bst::isLeftChild (BstNode & n) const
{
    const BstNode * const left_child_of_n = n.parent()->left();
    if (left_child_of_n == NULL)
        return false;

    return left_child_of_n->num() == n.num();
}

Bst::ReturnCode Bst::reinsertSubtreesOfNode (BstNode & n)
{
    ReturnCode result = SUCCESS;
    if (n.left() != NULL)
        result = insertNode(n.left());

    if (result == SUCCESS && n.right() != NULL) 
        result = insertNode(n.right());

    return result;
}

Bst::ReturnCode Bst::search (int num) const
{
    if (searchImpl(_root, num) != NULL)
        return NODE_FOUND;

    return NODE_NOT_FOUND;
}

const BstNode * Bst::searchImpl (const BstNode * n, int num) const
{
    if (n == NULL)
        return n; 

    if (num < n->num())
        return searchImpl(n->left(), num);
    else if (num > n->num())
        return searchImpl(n->right(), num);
    else // equal
        return n;
}

bool Bst::isRoot (const BstNode &n) const
{
    return n.parent() == NULL;
}

void Bst::display () const
{
    cout << "_size = " << _size << endl;
    displayInorderImpl(_root);
}

void Bst::displayPreorder () const
{
    cout << "_size = " << _size << endl;
    displayPreorderImpl(_root);
}

void Bst::displayPostorder () const
{
    cout << "_size = " << _size << endl;
    displayPostorderImpl(_root);
}

void Bst::displayBfs () const
{
    cout << "_size = " << _size << endl;
    vector<BstNode *> v;
    v.push_back(_root);
    displayBfsImpl(v);
}

void Bst::displayBfsImpl (vector<BstNode *> & v) const
{
    if (v.empty())
        return;

    display(v);

    loadNextLevel(v);

    displayBfsImpl(v);
}

void Bst::display (vector<BstNode *> & v) const
{
    for (vector<BstNode *>::iterator i = v.begin();
         i != v.end();
         ++i)
    {
        (*i)->display();
    }
}

void Bst::loadNextLevel (vector<BstNode *> & dest) const
{
    vector<BstNode *> source;
    dest.swap(source);

    for (vector<BstNode *>::iterator i = source.begin();
         i != source.end();
         ++i)
    {
        if ((*i)->left() != NULL)
            dest.push_back((*i)->left());

        if ((*i)->right() != NULL)
            dest.push_back((*i)->right());
    }
}

void Bst::displayPreorderImpl (const BstNode * n) const
{
    if (n == NULL)
    {
        cout << __LINE__ << ": n was NULL" << endl;
        return;
    }

    n->display();

    if (n->left() != NULL)
        displayPreorderImpl(n->left());

    if (n->right() != NULL)
        displayPreorderImpl(n->right());
}

void Bst::displayPostorderImpl (const BstNode * n) const
{
    if (n == NULL)
    {
        cout << __LINE__ << ": n was NULL" << endl;
        return;
    }

    if (n->left() != NULL)
        displayPostorderImpl(n->left());

    if (n->right() != NULL)
        displayPostorderImpl(n->right());

    n->display();
}

void Bst::displayInorderImpl (const BstNode * n) const
{
    if (n == NULL)
    {
        cout << __LINE__ << ": n was NULL" << endl;
        return;
    }

    if (n->left() != NULL)
        displayInorderImpl(n->left());

    n->display();

    if (n->right() != NULL)
        displayInorderImpl(n->right());
}
