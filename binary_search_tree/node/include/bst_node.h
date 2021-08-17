#ifndef BST_NODE_IF_H
#define BST_NODE_IF_H 1
#include "bst_node_if.h"
#endif

class BstNode : public BstNodeIf
{
    public:
    BstNode ();
    BstNode (int);
    virtual ~BstNode ();

    bool operator == (const BstNode &) const;

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

    int num () const;

    private:
    void initialize ();

    int _num;
    BstNodeIf & _left;
    BstNodeIf & _right;
    BstNodeIf & _parent;
};
