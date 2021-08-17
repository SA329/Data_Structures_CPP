#include "../include/bst_node_if.h"

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
