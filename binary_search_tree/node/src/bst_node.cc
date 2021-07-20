#include "../include/bst_node.h"
#include <iostream>
using namespace std;

bst_node::bst_node () :
_num(0), // 0 indicated not yet used
_left(NULL), 
_right(NULL), 
_parent(NULL)
{
}

bst_node::bst_node (int i) :
_num(i),
_left(NULL), 
_right(NULL), 
_parent(NULL)
{
}

bst_node::~bst_node ()
{
    clear();
}

void bst_node::clear ()
{
    _num = 0;
    _left = NULL;
    _right = NULL;
    _parent = NULL;
}

void bst_node::display ()
{
    cout << "this = " << this
         << ", _num = " << _num 
         << ", _left = " << _left
         << ", _right = " << _right
         << ", _parent = " << _parent
         << "." << endl;
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

void bst_node::add_left (class bst_node * n)
{
    _left = n;
}

void bst_node::add_right (class bst_node * n)
{
    _right = n;
}

void bst_node::add_parent (class bst_node * n)
{
    _parent = n;
}
