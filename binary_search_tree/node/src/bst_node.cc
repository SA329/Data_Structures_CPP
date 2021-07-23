#include "../include/bst_node.h"
#include <iostream>
using namespace std;

BstNode::BstNode () :
_num(0), // 0 indicated not yet used
_left(NULL), 
_right(NULL), 
_parent(NULL)
{
}

BstNode::BstNode (int i) :
_num(i),
_left(NULL), 
_right(NULL), 
_parent(NULL)
{
}

BstNode::~BstNode ()
{
    clear();
}

void BstNode::clear ()
{
    _num = 0;
    _left = NULL;
    _right = NULL;
    _parent = NULL;
}

void BstNode::display ()
{
    cout << "this = " << this
         << ", _num = " << _num 
         << ", _left = " << _left
         << ", _right = " << _right
         << ", _parent = " << _parent
         << "." << endl;
}

int BstNode::num ()
{
    return _num;
}

BstNode * BstNode::left ()
{
    return _left;
}

BstNode * BstNode::right ()
{
    return _right;
}

BstNode * BstNode::parent ()
{
    return _parent;
}

void BstNode::addLeft (class BstNode * n)
{
    _left = n;
}

void BstNode::addRight (class BstNode * n)
{
    _right = n;
}

void BstNode::addParent (class BstNode * n)
{
    _parent = n;
}
