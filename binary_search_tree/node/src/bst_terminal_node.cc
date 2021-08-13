#include "../include/bst_terminal_node.h"
using namespace std;

static BstTerminalNode _instance;

BstTerminalNode & BstTerminalNode::instance ()
{
    return _instance;
}

void BstTerminalNode::clear () {}
void BstTerminalNode::display () const {}

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
