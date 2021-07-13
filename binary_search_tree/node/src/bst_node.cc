#include "../include/bst_node.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK_NULL(n, error_string, ret_value) \
    if (n == NULL) \
    { \
        fprintf(stderr, error_string); \
        return ret_value; \
    }

// Private Functions:
/*
void bst_node_initialize (struct bst_node * n)
{
    n->num = 0; // 0 indicated not yet used
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
}
*/

// Public Interfaces:
bst_node::bst_node ()
{
    initialize();
}

bst_node::~bst_node ()
{
    // TODO: do we want to delete child/parent nodes?
    //       We suspect we do not, because I don't think this object creates children/parent.
    if (_left != NULL)
    {
        delete _left;
        _left = NULL;
    }

    if (_right != NULL)
    {
        delete _right;
        _right = NULL;
    }

    if (_parent != NULL)
    {
        delete _parent;
        _parent = NULL;
    }
}

void bst_node::initialize ()
{
    _num = 0; // 0 indicated not yet used
    _left = NULL;
    _right = NULL;
    _parent = NULL;
}

/*
struct bst_node * bst_node_create ()
{
    struct bst_node * n = (struct bst_node *) malloc(sizeof(struct bst_node));
    CHECK_NULL(
        n, 
        "WARNING: bst_node_create(): malloc returned NULL!\n", 
        NULL);

    bst_node_initialize(n);

    return n;
}

void bst_node_clear (struct bst_node * n)
{
    CHECK_NULL(
        n, 
        "WARNING: bst_node_clear(struct bst_node * n): n is NULL!\n",
        ;);

    bst_node_initialize(n); 
}

void bst_node_delete (struct bst_node ** n)
{
    CHECK_NULL(
        n,
        "WARNING: bst_node_delete(struct bst_node ** n): n is NULL!\n",
        ;);

    free(*n);
    *n = NULL;
}

// Accessors:
int bst_node_num (struct bst_node * n)
{
    CHECK_NULL(
        n,
        "WARNING: bst_node_num(struct bst_node * n): n is NULL!\n",
        0);

    return n->num;
}

void bst_node_set_num (struct bst_node * n, int num)
{
    CHECK_NULL(
        n,
        "ERROR: bst_node_set_num(struct bst_node * n, ...): n is NULL!\n",
        ;);

    n->num = num;
}

struct bst_node * bst_node_left (struct bst_node * n)
{
    CHECK_NULL(
        n,
        "WARNING: bst_node_left(struct bst_node * n): n is NULL!\n",
        NULL);

    return n->left;
}

void bst_node_set_left (struct bst_node * n, struct bst_node * left)
{
    CHECK_NULL(
        n, 
        "ERROR: bst_node_set_left(struct bst_node * n, ...): n is NULL!\n",
        ;);

    n->left = left;
}

struct bst_node * bst_node_right (struct bst_node * n)
{
    CHECK_NULL(
        n,
        "WARNING: bst_node_right(struct bst_node * n): n is NULL!\n",
        NULL);

    return n->right;
}

void bst_node_set_right (struct bst_node * n, struct bst_node * right)
{
    CHECK_NULL(
        n,
        "ERROR: bst_node_set_right(struct bst_node * n, ...): n is NULL!\n",
        ;);

    n->right = right;
}

struct bst_node * bst_node_parent (struct bst_node * n)
{
    CHECK_NULL(
        n,
        "WARNING: bst_node_parent(struct bst_node * n): n is NULL!\n",
        NULL);

    return n->parent;
}

void bst_node_set_parent (struct bst_node * n, struct bst_node * p)
{
    CHECK_NULL(
        n,
        "ERROR: bst_node_set_parent(struct bst_node * n, ...): n is NULL!\n",
        ;);

    n->parent = p;
}

// Helper Functions:
void bst_node_display (struct bst_node * n)
{
   CHECK_NULL(
        n,
        "ERROR: bst_node_display(struct bst_node * n): n is NULL!\n",
        ;);

   printf("n->num = %d\n", n->num); 
}

void bst_node_debug_display (struct bst_node * n)
{
   CHECK_NULL(
        n,
        "ERROR: bst_node_debug_display(struct bst_node * n): n is NULL!\n",
        ;);

   printf("n = %p\n", n);
   printf("n->num = %d\n", n->num); 
   printf("n->left = %p\n", n->left); 
   printf("n->right = %p\n", n->right); 
   printf("n->parent = %p\n", n->parent); 
}

bool bst_node_check_integrity (struct bst_node * n)
{
    if (n == NULL)
        return false;

    return true;
}
*/
