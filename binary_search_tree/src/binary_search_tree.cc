#include "../include/binary_search_tree.h"
#include "../node/include/bst_node.h"
#include <stdlib.h>
#include <stdio.h>

#define CHECK_NULL(n, error_string, ret_value) \
    if (n == NULL) \
    { \
        fprintf(stderr, error_string); \
        return ret_value; \
    }

#define BST_INVALID -1

struct bst {
    struct bst_node * root;
    int size;
};

// Forward Declarations:
struct bst_node * bst_search_impl (struct bst_node *, int);
struct bst_node * bst_get_insertion_point (struct bst *, int);
Bst_Return_Code bst_insert_node (struct bst *, struct bst_node *);
void bst_clear_impl (struct bst *, struct bst_node *);
Bst_Return_Code bst_remove_node (struct bst *, struct bst_node *);
void bst_move_to_next_node (int, struct bst_node **);
struct bst_node * bst_find_node_to_remove (struct bst *, int);
void bst_set_node (struct bst_node *, struct bst_node *);
Bst_Return_Code bst_remove_node (struct bst *, struct bst_node *);
Bst_Return_Code bst_remove_root (struct bst *, struct bst_node *);
void bst_root_tree_to_right_subtree (struct bst *, struct bst_node *);
Bst_Return_Code bst_root_tree_to_left_subtree (struct bst *, struct bst_node *);
Bst_Return_Code bst_remove_general_case (struct bst *, struct bst_node *);
Bst_Return_Code bst_reinsert_subtrees_of_node (struct bst *, struct bst_node *);
void bst_disconnect_node_from_parent (struct bst_node *);

struct bst * bst_create ()
{
    struct bst * result = (struct bst *) malloc(sizeof(struct bst));
    return result;
}

void bst_delete (struct bst ** t)
{
    if (t == NULL || *t == NULL)
        return;

    bst_clear_impl(*t, (*t)->root);
    free(*t);
    *t = NULL;
}

Bst_Return_Code bst_clear (struct bst * t)
{
    if (t == NULL)
        return BST_TREE_NULL;

    bst_clear_impl(t, t->root);
    t->root = NULL;

    return BST_SUCCESS;
}

void bst_clear_impl (struct bst * t, struct bst_node * n)
{
   if (n == NULL)
       return; 

    bst_clear_impl(t, bst_node_left(n));
    bst_clear_impl(t, bst_node_right(n));

    bst_node_delete(&n);
    t->size--;
}

int bst_size (struct bst * t)
{
    if (t == NULL)
        return BST_INVALID;

    return t->size;
}

bool bst_is_empty (struct bst * t)
{
    CHECK_NULL(
        t,
        "WARNING: bst_is_empty(struct bst * t): t is NULL!\n",
        false);

    return t->size == 0;
}

struct bst_node * bst_search_impl (struct bst_node * n, int num)
{
    if (n == NULL)
        return n; 

    if (num < bst_node_num(n))
        return bst_search_impl(bst_node_left(n), num);
    else if (num > bst_node_num(n))
        return bst_search_impl(bst_node_right(n), num);
    else // equal
        return n;
}

Bst_Return_Code bst_search (struct bst * t, int num)
{
    if (t == NULL)
        return BST_TREE_NULL;

    if (bst_search_impl(t->root, num) != NULL)
        return BST_NODE_FOUND;

    return BST_NODE_NOT_FOUND;
}

void bst_move_to_next_node (
    int num,
    struct bst_node ** n) // *n should never be NULL
{
    if (num < bst_node_num(*n))
        *n = bst_node_left(*n);
    else 
        *n = bst_node_right(*n);
}

struct bst_node * bst_get_insertion_point (
    struct bst * t, // t is NOT empty
    int num)
{
   struct bst_node * p = NULL;
   struct bst_node * n = t->root;
   for (; n != NULL; bst_move_to_next_node(num, &n))
   {
        if (num == bst_node_num(n))
            return NULL; // signals num is already in tree

        p = n;
   }

   return p;
}

struct bst_node * bst_find_node_to_remove (
    struct bst * t, // t is NOT empty
    int num)
{
   struct bst_node * n = t->root;
   for (; n != NULL; bst_move_to_next_node(num, &n))
   {
        if (num == bst_node_num(n))
            break;
   }

   return n;
}

void bst_set_node (struct bst_node * p, struct bst_node * n)
{
    bst_node_set_parent(n, p);

    if (bst_node_num(n) < bst_node_num(p))
         bst_node_set_left(p, n); // insert left
    else 
         bst_node_set_right(p, n); // insert right
}

Bst_Return_Code bst_insert_node (struct bst * t, struct bst_node * n)
{
    if (n == NULL)
        return BST_NODE_NULL;

    if (bst_is_empty(t))
    {
        t->root = n;
        return BST_SUCCESS;
    }

    struct bst_node * p = bst_get_insertion_point(t, bst_node_num(n));
    if (p == NULL)
        return BST_NODE_DUPLICATE;

    bst_set_node(p, n);

    return BST_SUCCESS;
}

Bst_Return_Code bst_insert (struct bst * t, int num)
{
    if (t == NULL)
        return BST_TREE_NULL;

    struct bst_node * n = bst_node_create();
    bst_node_set_num(n, num);

    Bst_Return_Code result = bst_insert_node(t, n);

    if (result == BST_SUCCESS)
        t->size++;
    else
        bst_node_delete(&n);

    return result;
}

bool bst_is_left_child (struct bst_node * n)
{
    struct bst_node * left_child_of_n = bst_node_left(bst_node_parent(n));
    if (left_child_of_n == NULL)
        return false;

    return bst_node_num(left_child_of_n) == bst_node_num(n);
}

Bst_Return_Code bst_reinsert_subtrees_of_node (
    struct bst * t, struct bst_node * n)
{
    Bst_Return_Code result = BST_SUCCESS;
    if (bst_node_left(n) != NULL)
        result = bst_insert_node(t, bst_node_left(n));

    if (result == BST_SUCCESS && bst_node_right(n) != NULL) 
        result = bst_insert_node(t, bst_node_right(n));

    return result;
}

void bst_disconnect_node_from_parent (struct bst_node * n)
{
    if (bst_is_left_child(n))
        bst_node_set_left(bst_node_parent(n), NULL);
    else
        bst_node_set_right(bst_node_parent(n), NULL);
}

Bst_Return_Code bst_remove_general_case (
    struct bst * t, 
    struct bst_node * n)
{
    bst_disconnect_node_from_parent(n);
    return bst_reinsert_subtrees_of_node(t, n);
}

bool bst_is_root (struct bst_node * n)
{
    return bst_node_parent(n) == NULL;
}

void bst_set_new_root (struct bst * t, struct bst_node * n)
{
    t->root = n;
    if (t->root != NULL)
        bst_node_set_parent(t->root, NULL);
}

void bst_root_tree_to_right_subtree (
    struct bst * t, struct bst_node * n)
{
    bst_set_new_root(t, bst_node_right(n));
}

Bst_Return_Code bst_root_tree_to_left_subtree (
    struct bst * t, struct bst_node * n)
{
    bst_set_new_root(t, bst_node_left(n));

    if (bst_node_right(n) != NULL)
    {
        bst_node_set_parent(bst_node_right(n), NULL);
        return bst_insert_node(t, bst_node_right(n));
    }

    return BST_SUCCESS;
}

Bst_Return_Code bst_remove_root (struct bst * t, struct bst_node * n)
{
    if (bst_node_left(n) != NULL)
        return bst_root_tree_to_left_subtree(t, n);
    else
        bst_root_tree_to_right_subtree(t, n);

    return BST_SUCCESS;
}

Bst_Return_Code bst_remove_node (struct bst * t, struct bst_node * n)
{
    if (bst_is_root(n))
        return bst_remove_root(t, n);
    else
        return bst_remove_general_case(t, n);
}

Bst_Return_Code bst_remove (struct bst * t, int num)
{
    if (t == NULL)
        return BST_TREE_NULL;

    if (bst_is_empty(t))
        return BST_TREE_EMPTY;

    struct bst_node * n = bst_find_node_to_remove(t, num);
    if (n == NULL)
        return BST_NODE_NOT_FOUND;

    Bst_Return_Code result = bst_remove_node(t, n);
    if (result != BST_SUCCESS)
        return result;

    t->size--;
    bst_node_delete(&n);

    return result;
}

#include "bst_display_functions.c"
#include "bst_check_integrity_functions.c"
