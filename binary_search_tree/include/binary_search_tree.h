#include <stdbool.h>

struct bst;

enum bst_return_code {
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

typedef enum bst_return_code Bst_Return_Code;

/* Public Interface: */
struct bst * bst_create ();

void bst_delete (struct bst **);
Bst_Return_Code bst_clear (struct bst *);
bool bst_is_empty (struct bst *);
int bst_size (struct bst *);

Bst_Return_Code bst_insert (struct bst *, int);
Bst_Return_Code bst_remove (struct bst *, int);

// Search:
Bst_Return_Code bst_search (struct bst *, int);

#include "bst_helper_functions.h"
