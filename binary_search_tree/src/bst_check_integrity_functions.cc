// Forward Declarations:
bool bst_check_empty_tree_integrity (struct bst *);
void bst_break_parent_of_root_node (struct bst *);
void bst_break_parent_of_non_root_node (struct bst *, int);
struct bst_node * bst_find_node_to_break (struct bst *, int);
bool bst_check_integrity_less_than (struct bst_node *, int);
bool bst_check_less_than (struct bst_node *, int);
bool bst_check_integrity_greater_than (struct bst_node *, int);
bool bst_check_greater_than (struct bst_node *, int);
bool bst_check_parent_integrity (struct bst *, struct bst_node *);
bool bst_node_parent_is_not_null (struct bst *, struct bst_node *);
bool bst_root_node_parent_is_null (struct bst *, struct bst_node *);
bool bst_check_order_integrity_impl (struct bst_node *);
bool bst_check_order_integrity (struct bst_node *);
bool bst_check_parent_integrity (struct bst *, struct bst_node *);

// Public Functions:
bool bst_check_integrity (struct bst * t)
{
    if (t == NULL)
        return true;

    if (bst_is_empty(t))
        return bst_check_empty_tree_integrity(t);

    if (!bst_check_parent_integrity(t, t->root))
        return false;

    if (!bst_check_order_integrity(t->root))
        return false;

    return true;
}

void bst_break_parent_integrity (struct bst * t, int num)
{
    if (t == NULL)
        return;

    if (num == 0)
        bst_break_parent_of_root_node(t);
    else
        bst_break_parent_of_non_root_node(t, num);
}

// Private Functions:
bool bst_check_empty_tree_integrity (struct bst * t)
{
    if (t->root != NULL)
    {
        fprintf(stderr, "ERROR: bst_check_integrity(...): tree is empty but root is not NULL!\n");
        return false;
    }

    if (bst_size(t) != 0)
    {
        fprintf(stderr, "ERROR: bst_check_integrity(...): tree is empty but size is not 0!\n");
        return false;
    }

    return true;
}

void bst_break_parent_of_root_node (struct bst * t)
{
    struct bst_node * dummy = (struct bst_node *) 0x123;
    bst_node_set_parent(t->root, dummy);
}

void bst_break_parent_of_non_root_node (struct bst * t, int num)
{
    struct bst_node * n = bst_find_node_to_break(t, num);

    if (n != NULL)
        bst_node_set_parent(n, NULL);
}

struct bst_node * bst_find_node_to_break (struct bst * t, int num)
{
    struct bst_node * result = NULL;
    struct bst_node * n = t->root;

    while (n != NULL)
    {
        if (num == bst_node_num(n))
        {
            result = n;
            break;
        }

        if (num < bst_node_num(n))
            n = bst_node_left(n);
        else 
            n = bst_node_right(n);
    }

    return result;
}

bool bst_check_integrity_less_than (struct bst_node * s, int num)
{
    if (s == NULL)
        return true;

    if (!bst_check_less_than(s, num))
        return false;

    return 
        bst_check_integrity_less_than(bst_node_left(s), num) && 
        bst_check_integrity_less_than(bst_node_right(s), num);
}

bool bst_check_less_than (struct bst_node * n, int num)
{
    if (n == NULL)
        return true;

    if (bst_node_num(n) > num)
    {
        fprintf(stderr, "ERROR: bst_check_less_than(...): expected %d < %d\n", bst_node_num(n), num);
        return false;
    }

    return true;
}

bool bst_check_integrity_greater_than (struct bst_node * s, int num)
{
    if (s == NULL)
        return true;

    if (!bst_check_greater_than(s, num))
        return false;

    return 
        bst_check_integrity_greater_than(bst_node_left(s), num) && 
        bst_check_integrity_greater_than(bst_node_right(s), num);
}

bool bst_check_greater_than (struct bst_node * n, int num)
{
    if (n == NULL)
        return true;

    if (bst_node_num(n) < num)
    {
        fprintf(stderr, "ERROR: bst_check_greater_than(...): expected %d > %d\n", bst_node_num(n), num);
        return false;
    }

    return true;
}

bool bst_check_parent_integrity (struct bst * t, struct bst_node * n)
{
    if (t == NULL)
        return true;

    if (n == NULL)
        return true;

    if (!(bst_root_node_parent_is_null(t, n) && 
          bst_node_parent_is_not_null(t, n)))
        return false;

    return 
        bst_check_parent_integrity(t, bst_node_left(n)) && 
        bst_check_parent_integrity(t, bst_node_right(n));
}

bool bst_node_parent_is_not_null (
    struct bst * t, struct bst_node * n)
{
    if (n != t->root)
    {
        if (bst_node_parent(n) == NULL)
        {
            fprintf(stderr, "ERROR: bst_check_order_integrity(...): node's parent is NULL (%p)\n", bst_node_parent(n));
            return false;
        }
    }

    return true;
}

bool bst_root_node_parent_is_null (struct bst * t, struct bst_node * n)
{
    if (n == t->root)
    {
        if (bst_node_parent(n) != NULL)
        {
            fprintf(stderr, "ERROR: bst_check_order_integrity(...): root's parent is not NULL (%p)\n", bst_node_parent(n));
            return false;
        }
    }

    return true;
}

bool bst_check_order_integrity_impl (struct bst_node * p)
{
    if (p == NULL)
        return true;

    int p_num = bst_node_num(p);
    struct bst_node * left = bst_node_left(p);
    struct bst_node * right = bst_node_right(p);

    if (!(bst_check_less_than(left, p_num) && 
          bst_check_greater_than(right, p_num)))
        return false;

    return bst_check_order_integrity_impl(left) &&
           bst_check_order_integrity_impl(right);
}

bool bst_check_order_integrity (struct bst_node * p)
{
    int num = bst_node_num(p);

    return bst_check_integrity_less_than(bst_node_left(p), num) &&
           bst_check_integrity_greater_than(bst_node_right(p), num) &&
           bst_check_order_integrity_impl(p);
}
