#include "../include/bst_terminal_node.h"
#include <iostream>
using namespace std;

static BstTerminalNode _instance;

BstTerminalNode & BstTerminalNode::instance ()
{
    return _instance;
}

BstTerminalNode & BstTerminalNode::operator = (const BstNodeIf & right)
{
    cout << "entered BstTerminalNode::operator =(...)" << endl;
    return *this;
}

void BstTerminalNode::clear () {}
void BstTerminalNode::display () const 
{
    cout << "Terminal Node" << endl;
}

BstNodeIf & BstTerminalNode::left () const 
{ 
    return BstTerminalNode::instance(); 
}

BstNodeIf & BstTerminalNode::right () const
{ 
    return BstTerminalNode::instance(); 
}

BstNodeIf & BstTerminalNode::parent () const
{ 
    return BstTerminalNode::instance(); 
}

void BstTerminalNode::addLeft (BstNodeIf & n) {}
void BstTerminalNode::addRight (BstNodeIf & n) {}
void BstTerminalNode::addParent (BstNodeIf & n) {}

bool BstTerminalNode::isTerminalNode () const
{
    return true;
}
