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

bool BstNode::operator == (const BstNode & n) const
{
    return _num == n.num() && ::operator ==(*this, n);
}

BstNode & BstNode::operator = (const BstNode & right)
{
    cout << "entered assignment operator '='" << endl;
    if (*this == right)
        return *this;
    
    _num = right._num;
    _left = right._left;
    _right = right._right;
    _parent = right._parent;

    return *this;
}

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
