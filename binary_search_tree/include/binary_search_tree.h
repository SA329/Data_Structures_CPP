#include <stdbool.h>

class BstNode;

class Bst
{
    public:
    enum ReturnCode {
        BST_INVALID = -1,
        BST_SUCCESS = 0,
        BST_NODE_FOUND,
        BST_TREE_NULL,
        BST_NODE_NULL,
        BST_NODE_DUPLICATE,
        BST_NODE_NOT_FOUND,
        BST_TREE_EMPTY,
        BST_MAX_ERROR_CODE
    };

    Bst ();
    virtual ~Bst ();

    void clear ();
    bool isEmpty ();
    unsigned int size ();

    ReturnCode insert (int);
    ReturnCode remove (int);

    ReturnCode search (int);

    private:
    BstNode * _root;
    unsigned int _size;

    void clearImpl (BstNode *);
    ReturnCode insertNode (BstNode *);
    void setNode (BstNode *, BstNode *);
    BstNode * getInsertionPoint (int);
    void moveToNextNode (int, BstNode **);

};

//typedef enum bst_return_code Bst_Return_Code;

#include "bst_helper_functions.h"
