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

void BstNode::display () const
{
    cout << "this = " << this
         << ", _num = " << _num 
         << ", _left = " << _left
         << ", _right = " << _right
         << ", _parent = " << _parent
         << "." << endl;
}

int BstNode::num () const
{
    return _num;
}

const BstNode * BstNode::left () const
{
    return _left;
}

const BstNode * BstNode::right () const
{
    return _right;
}

const BstNode * BstNode::parent () const
{
    return _parent;
}

void BstNode::addLeft (BstNode * n)
{
    _left = n;
}

void BstNode::addRight (BstNode * n)
{
    _right = n;
}

void BstNode::addParent (BstNode * n)
{
    _parent = n;
}
