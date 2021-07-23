#include "../include/binary_search_tree.h"
#include "../node/include/bst_node.h"
#include <stdlib.h>
#include <stdio.h>

#define CHECK_NULL(n, error_string, ret_value) \
    if (n == NULL) \
    { \
        fprintf(stderr, error_string); \
        return ret_value; \
    }

#define BST_INVALID -1

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

bool Bst::isEmpty ()
{
    return _size == 0;
}

unsigned int Bst::size ()
{
    return _size;
}

Bst::ReturnCode Bst::insert (int num)
{
    BstNode * n = new BstNode(num);

    ReturnCode result = insertNode(n);

    if (result == BST_SUCCESS)
        _size++;
    else
        delete n;

    return result;
}

Bst::ReturnCode Bst::insertNode (BstNode * n)
{
    if (n == NULL)
        return BST_NODE_NULL;

    if (isEmpty())
    {
        _root = n;
        return BST_SUCCESS;
    }

    BstNode * p = getInsertionPoint(n->num());
    if (p == NULL)
        return BST_NODE_DUPLICATE;

    setNode(p, n);

    return BST_SUCCESS;
}

void Bst::setNode (BstNode * p, BstNode * n)
{
    n->addParent(p);

    if (n->num() < p->num())
         p->addLeft(n); // insert left
    else 
         p->addRight(n); // insert right
}

BstNode * Bst::getInsertionPoint (int num)
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

void Bst::moveToNextNode (int num, BstNode ** n) // *n should never be NULL
{
    if (num < (*n)->num())
        *n = (*n)->left();
    else 
        *n = (*n)->right();
}

/*
// Forward Declarations:
struct bst_node * bst_search_impl (struct bst_node *, int);
Bst_Return_Code bst_remove_node (struct bst *, struct bst_node *);
struct bst_node * bst_find_node_to_remove (struct bst *, int);
Bst_Return_Code bst_remove_node (struct bst *, struct bst_node *);
Bst_Return_Code bst_remove_root (struct bst *, struct bst_node *);
void bst_root_tree_to_right_subtree (struct bst *, struct bst_node *);
Bst_Return_Code bst_root_tree_to_left_subtree (struct bst *, struct bst_node *);
Bst_Return_Code bst_remove_general_case (struct bst *, struct bst_node *);
Bst_Return_Code bst_reinsert_subtrees_of_node (struct bst *, struct bst_node *);
void bst_disconnect_node_from_parent (struct bst_node *);

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
        return BST_TREE_NULL;

    if (bst_search_impl(t->root, num) != NULL)
        return BST_NODE_FOUND;

    return BST_NODE_NOT_FOUND;
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
    Bst_Return_Code result = BST_SUCCESS;
    if (bst_node_left(n) != NULL)
        result = bst_insert_node(t, bst_node_left(n));

    if (result == BST_SUCCESS && bst_node_right(n) != NULL) 
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

    return BST_SUCCESS;
}

Bst_Return_Code bst_remove_root (struct bst * t, struct bst_node * n)
{
    if (bst_node_left(n) != NULL)
        return bst_root_tree_to_left_subtree(t, n);
    else
        bst_root_tree_to_right_subtree(t, n);

    return BST_SUCCESS;
}

Bst_Return_Code bst_remove_node (struct bst * t, struct bst_node * n)
{
    if (bst_is_root(n))
        return bst_remove_root(t, n);
    else
        return bst_remove_general_case(t, n);
}

Bst_Return_Code bst_remove (struct bst * t, int num)
{
    if (t == NULL)
        return BST_TREE_NULL;

    if (bst_is_empty(t))
        return BST_TREE_EMPTY;

    struct bst_node * n = bst_find_node_to_remove(t, num);
    if (n == NULL)
        return BST_NODE_NOT_FOUND;

    Bst_Return_Code result = bst_remove_node(t, n);
    if (result != BST_SUCCESS)
        return result;

    t->size--;
    bst_node_delete(&n);

    return result;
}

#include "bst_display_functions.c"
#include "bst_check_integrity_functions.c"
*/
