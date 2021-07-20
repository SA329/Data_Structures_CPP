#include <stdbool.h>

class bst_node
{
    public:
    bst_node ();
    bst_node (int);
    virtual ~bst_node ();

    void clear ();
    virtual void display ();

    // getters:
    int num ();
    bst_node * left ();
    bst_node * right ();
    bst_node * parent ();

    // setters:
    void add_left (class bst_node *);
    void add_right (class bst_node *);
    void add_parent (class bst_node *);

    private:
    void initialize ();

    private:
    int _num;
    class bst_node * _left;
    class bst_node * _right;
    class bst_node * _parent;
};
