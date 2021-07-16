#include <stdbool.h>

class bst_node
{
    public:
    bst_node ();
    bst_node (int);
    virtual ~bst_node ();

    void set_left (class bst_node *);
    virtual void display ();

    // getters:
    int num ();
    bst_node * left ();
    bst_node * right ();
    bst_node * parent ();
    /*
    void bst_node_clear (class bst_node *);
    void bst_node_set_num (class bst_node *, int); 
    void bst_node_set_left (class bst_node *, class bst_node *);
    void bst_node_set_right (class bst_node *, class bst_node *);
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

class Saumya : public bst_node
{
    public:
    Saumya ();
    ~Saumya ();

    void display ();

    private:
    int level_of_bunnosity;
    int level_of_lumposity;
};

#include "helper_functions.h"
