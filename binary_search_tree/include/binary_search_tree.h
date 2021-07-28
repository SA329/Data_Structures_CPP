#include <stdbool.h>

class BstNode;

class Bst
{
    public:
    enum ReturnCode {
        INVALID = -1,
        SUCCESS = 0,
        NODE_FOUND,
        TREE_NULL,
        NODE_NULL,
        NODE_DUPLICATE,
        NODE_NOT_FOUND,
        TREE_EMPTY,
        MAX_ERROR_CODE
    };

    Bst ();
    virtual ~Bst ();

    void clear ();
    bool isEmpty () const;
    unsigned int size () const;

    ReturnCode insert (int);
    ReturnCode remove (int);

    ReturnCode search (int) const;

    private:
    BstNode * _root;
    unsigned int _size;

    void clearImpl (BstNode *);
    void disconnectNodeFromParent (BstNode &);
    BstNode * findNodeToRemove (int) const;
    BstNode * getInsertionPoint (int) const;
    ReturnCode insertNode (BstNode &);
    ReturnCode insertNode (BstNode *);
    bool isLeftChild (BstNode &) const;
    void moveToNextNode (int, BstNode **) const;
    ReturnCode removeGeneralCase (BstNode &);
    ReturnCode removeNode (BstNode &);
    ReturnCode removeRoot (BstNode &);
    ReturnCode reinsertSubtreesOfNode (BstNode &);
    ReturnCode rootTreeToLeftSubtree (BstNode &);
    void rootTreeToRightSubtree (BstNode &);
    const BstNode * searchImpl (BstNode *, int) const;
    void setNewRoot (BstNode *);
    void setNode (BstNode &, BstNode &);
    bool isRoot (const BstNode &) const;

};

#include "bst_helper_functions.h"
