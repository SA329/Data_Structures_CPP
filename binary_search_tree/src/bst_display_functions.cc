// Forward Declarations:
void bst_debug_display_impl (struct bst_node *);
void bst_display_inorder_impl (struct bst_node *);
void bst_display_preorder_impl (struct bst_node *);
void bst_display_postorder_impl (struct bst_node *);

// Public Functions:
void bst_debug_display (struct bst * t)
{
    if (t != NULL)
    {
        printf("t->size = %d\n", t->size);
        bst_debug_display_impl(t->root);
    }
}

void bst_display (struct bst * t)
{
    if (t != NULL)
    {
        printf("t->size = %d\n", t->size);
        bst_display_inorder_impl(t->root);
    }
}

void bst_display_preorder (struct bst * t)
{
    if (t != NULL)
    {
        printf("t->size = %d\n", t->size);
        bst_display_preorder_impl(t->root);
    }
}

void bst_display_postorder (struct bst * t)
{
    if (t != NULL)
    {
        printf("t->size = %d\n", t->size);
        bst_display_postorder_impl(t->root);
    }
}

// TODO: display bfs

// Private Functions:
void bst_debug_display_impl (struct bst_node * n)
{
    if (n == NULL)
    {
        printf("%d: n was null\n", __LINE__);
        return;
    }

    if (bst_node_left(n) != NULL)
        bst_debug_display_impl(bst_node_left(n));

    bst_node_debug_display(n);

    if (bst_node_right(n) != NULL)
        bst_debug_display_impl(bst_node_right(n));
}

void bst_display_preorder_impl (struct bst_node * n)
{
    if (n == NULL)
    {
        printf("%d: n was null\n", __LINE__);
        return;
    }
    
    bst_node_display(n);

    if (bst_node_left(n) != NULL)
        bst_display_preorder_impl(bst_node_left(n));

    if (bst_node_right(n) != NULL)
        bst_display_preorder_impl(bst_node_right(n));
}

void bst_display_postorder_impl (struct bst_node * n)
{
    if (n == NULL)
    {
        printf("%d: n was null\n", __LINE__);
        return;
    }
    
    if (bst_node_left(n) != NULL)
        bst_display_postorder_impl(bst_node_left(n));

    if (bst_node_right(n) != NULL)
        bst_display_postorder_impl(bst_node_right(n));

    bst_node_display(n);
}

void bst_display_inorder_impl (struct bst_node * n)
{
    if (n == NULL)
    {
        printf("%d: n was null\n", __LINE__);
        return;
    }
    
    if (bst_node_left(n) != NULL)
        bst_display_inorder_impl(bst_node_left(n));

    bst_node_display(n);

    if (bst_node_right(n) != NULL)
        bst_display_inorder_impl(bst_node_right(n));
}
