#include "../include/bst_node.h"
#include "../include/bst_terminal_node.h"
#include <iostream>
using namespace std;

BstNode::BstNode () :
_num(0), // 0 indicated not yet used
_left(BstTerminalNode::instance()), 
_right(BstTerminalNode::instance()),
_parent(BstTerminalNode::instance())
{
}

BstNode::BstNode (int i) :
_num(i),
_left(BstTerminalNode::instance()), 
_right(BstTerminalNode::instance()), 
_parent(BstTerminalNode::instance())
{
}

BstNode::~BstNode ()
{
    clear();
}

/*
bool BstNode::operator == (const BstNode & n) const
{
    cout << "inside BstNode::operator == (...)" << endl;
    return 
        _num == n.num() && 
        _left == n.left() && 
        _right == n.right() && 
        _parent == n.parent();
}
*/

void BstNode::clear ()
{
    _num = 0;
    _left = BstTerminalNode::instance();
    _right = BstTerminalNode::instance();
    _parent = BstTerminalNode::instance();
}

void BstNode::display () const
{
    cout << "this = " << this
         << ", _num = " << _num 
         /*
         << ", _left = " << _left
         << ", _right = " << _right
         << ", _parent = " << _parent
         */
         << "." << endl;
}

int BstNode::num () const
{
    return _num;
}

BstNodeIf & BstNode::left () const
{
    return _left;
}

BstNodeIf & BstNode::right () const
{
    return _right;
}

BstNodeIf & BstNode::parent () const
{
    return _parent;
}

void BstNode::addLeft (BstNodeIf & n)
{
    _left = n;
}

void BstNode::addRight (BstNodeIf & n)
{
    _right = n;
}

void BstNode::addParent (BstNodeIf & n)
{
    _parent = n;
}

bool BstNode::isTerminalNode () const
{
    return false;
}
