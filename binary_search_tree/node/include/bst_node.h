#include <stdbool.h>

class bst_node
{
    public:
    bst_node ();
    ~bst_node ();

    /*
    void bst_node_clear (class bst_node *);
    int bst_node_num (class bst_node *);
    void bst_node_set_num (class bst_node *, int); 
    class bst_node * bst_node_left (class bst_node *);
    void bst_node_set_left (class bst_node *, class bst_node *);
    class bst_node * bst_node_right (class bst_node *);
    void bst_node_set_right (class bst_node *, class bst_node *);
    class bst_node * bst_node_parent (class bst_node *);
    void bst_node_set_parent (class bst_node *, class bst_node *);
    */

    private:
    void initialize ();

    private:
    int _num;
    class bst_node * _left;
    class bst_node * _right;
    class bst_node * _parent;
};

#include "helper_functions.h"
