#ifndef BST_NODE_IF_H
#define BST_NODE_IF_H 1
#include "bst_node_if.h"
#endif

class BstTerminalNode : public BstNodeIf
{
    public:
    static BstTerminalNode & instance ();
    BstTerminalNode & operator = (const BstNodeIf &);

    // BstNodeIf Implementation:
    void clear ();
    virtual void display () const;
    BstNodeIf & left () const;
    BstNodeIf & right () const;
    BstNodeIf & parent () const;
    void addLeft (BstNodeIf &);
    void addRight (BstNodeIf &);
    void addParent (BstNodeIf &);
    bool isTerminalNode () const;
};
