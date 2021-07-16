#include "../include/bst_node.h"
#include <iostream>
using namespace std;

#define CHECK_NULL(n, error_string, ret_value) \
    if (n == NULL) \
    { \
        fprintf(stderr, error_string); \
        return ret_value; \
    }

bst_node::bst_node () :
_num(0), // 0 indicated not yet used
_left(NULL), 
_right(NULL), 
_parent(NULL)
{
    cout << "entered bst_node::ctor() for " << this << endl;
}

bst_node::bst_node (int i) :
_num(i),
_left(NULL), 
_right(NULL), 
_parent(NULL)
{
    cout << "entered bst_node::ctor(int) for " << this << endl;
}

bst_node::~bst_node ()
{
    cout << "entered bst_node::dtor() for " << this << endl;
}

void bst_node::initialize ()
{
    _num = 0;
    _left = NULL;
    _right = NULL;
    _parent = NULL;
}

void bst_node::display ()
{
    cout << "_num is " << _num 
         << ", _left is " << _left
         << ", _right is " << _right
         << ", _parent is " << _parent << endl;
}

int bst_node::num ()
{
    return _num;
}

bst_node * bst_node::left ()
{
    return _left;
}

bst_node * bst_node::right ()
{
    return _right;
}

bst_node * bst_node::parent ()
{
    return _parent;
}

Saumya::Saumya () :
level_of_bunnosity(500000),
level_of_lumposity(500009)
{
    cout << "entered Saumya::ctor() for " << this << endl;
}

Saumya::~Saumya ()
{
    cout << "entered Saumya::dtor() for " << this << endl;
}

void Saumya::display ()
{
    cout << "level_of_bunnosity is " << level_of_bunnosity
         << ", level_of_lumposity is " << level_of_lumposity
         << ", ";

    bst_node::display();
}

/*
void bst_node_clear (struct bst_node * n)
{
    CHECK_NULL(
        n, 
        "WARNING: bst_node_clear(struct bst_node * n): n is NULL!\n",
        ;);

    bst_node_initialize(n); 
}

// Accessors:
void bst_node_set_num (struct bst_node * n, int num)
{
    CHECK_NULL(
        n,
        "ERROR: bst_node_set_num(struct bst_node * n, ...): n is NULL!\n",
        ;);

    n->num = num;
}

void bst_node_set_left (struct bst_node * n, struct bst_node * left)
{
    CHECK_NULL(
        n, 
        "ERROR: bst_node_set_left(struct bst_node * n, ...): n is NULL!\n",
        ;);

    n->left = left;
}

void bst_node_set_right (struct bst_node * n, struct bst_node * right)
{
    CHECK_NULL(
        n,
        "ERROR: bst_node_set_right(struct bst_node * n, ...): n is NULL!\n",
        ;);

    n->right = right;
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
