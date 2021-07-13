void bst_display (struct bst *); // inorder: left, root, right
void bst_display_preorder (struct bst *); // root, left, right
void bst_display_postorder (struct bst *); // left, right, root
void bst_display_bfs (struct bst *);
void bst_debug_display (struct bst *);
bool bst_check_integrity (struct bst *);
void bst_break_parent_integrity (struct bst *, int);
