#include "../include/binary_search_tree.h"
#include "../node/include/bst_node.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

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
    displayBfsImpl(_root);
}

void Bst::displayBfsImpl (const BstNode * n) const
{
    // TODO
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

/*
struct bst_node * bst_search_impl (struct bst_node * n, int num)
{
    if (n == NULL)
        return n; 

    if (num < bst_node_num(n))
        return bst_search_impl(bst_node_left(n), num);
    else if (num > bst_node_num(n))
        return bst_search_impl(bst_node_right(n), num);
    else // equal
        return n;
}

Bst_Return_Code bst_search (struct bst * t, int num)
{
    if (t == NULL)
        return TREE_NULL;

    if (bst_search_impl(t->root, num) != NULL)
        return NODE_FOUND;

    return NODE_NOT_FOUND;
}

struct bst_node * bst_find_node_to_remove (
    struct bst * t, // t is NOT empty
    int num)
{
   struct bst_node * n = t->root;
   for (; n != NULL; bst_move_to_next_node(num, &n))
   {
        if (num == bst_node_num(n))
            break;
   }

   return n;
}

bool bst_is_left_child (struct bst_node * n)
{
    struct bst_node * left_child_of_n = bst_node_left(bst_node_parent(n));
    if (left_child_of_n == NULL)
        return false;

    return bst_node_num(left_child_of_n) == bst_node_num(n);
}

Bst_Return_Code bst_reinsert_subtrees_of_node (
    struct bst * t, struct bst_node * n)
{
    Bst_Return_Code result = SUCCESS;
    if (bst_node_left(n) != NULL)
        result = bst_insert_node(t, bst_node_left(n));

    if (result == SUCCESS && bst_node_right(n) != NULL) 
        result = bst_insert_node(t, bst_node_right(n));

    return result;
}

void bst_disconnect_node_from_parent (struct bst_node * n)
{
    if (bst_is_left_child(n))
        bst_node_set_left(bst_node_parent(n), NULL);
    else
        bst_node_set_right(bst_node_parent(n), NULL);
}

Bst_Return_Code bst_remove_general_case (
    struct bst * t, 
    struct bst_node * n)
{
    bst_disconnect_node_from_parent(n);
    return bst_reinsert_subtrees_of_node(t, n);
}

bool bst_is_root (struct bst_node * n)
{
    return bst_node_parent(n) == NULL;
}

void bst_set_new_root (struct bst * t, struct bst_node * n)
{
    t->root = n;
    if (t->root != NULL)
        bst_node_set_parent(t->root, NULL);
}

void bst_root_tree_to_right_subtree (
    struct bst * t, struct bst_node * n)
{
    bst_set_new_root(t, bst_node_right(n));
}

Bst_Return_Code bst_root_tree_to_left_subtree (
    struct bst * t, struct bst_node * n)
{
    bst_set_new_root(t, bst_node_left(n));

    if (bst_node_right(n) != NULL)
    {
        bst_node_set_parent(bst_node_right(n), NULL);
        return bst_insert_node(t, bst_node_right(n));
    }

    return SUCCESS;
}

Bst_Return_Code bst_remove_root (struct bst * t, struct bst_node * n)
{
    if (bst_node_left(n) != NULL)
        return bst_root_tree_to_left_subtree(t, n);
    else
        bst_root_tree_to_right_subtree(t, n);

    return SUCCESS;
}

Bst_Return_Code bst_remove_node (struct bst * t, struct bst_node * n)
{
    if (bst_is_root(n))
        return bst_remove_root(t, n);
    else
        return bst_remove_general_case(t, n);
}

#include "bst_display_functions.c"
#include "bst_check_integrity_functions.c"
*/
