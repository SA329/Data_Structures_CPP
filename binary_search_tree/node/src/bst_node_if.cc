#include "../include/bst_node_if.h"
#include <iostream>
using namespace std;

BstNodeIf & BstNodeIf::operator = (const BstNodeIf & right)
{
    cout << "entered BstNodeIf::operator =(...)" << endl;
    return *this;
}

bool operator == (
    const BstNodeIf & left, 
    const BstNodeIf & right)
{
    const bool logicalEquivalence(
        left.isTerminalNode() && 
        right.isTerminalNode());

    const bool physicalEquivalence(
        !logicalEquivalence &&
        left.left()==right.left() && 
        left.right()==right.right() && 
        left.parent()==right.parent());

    return logicalEquivalence || physicalEquivalence;
}
