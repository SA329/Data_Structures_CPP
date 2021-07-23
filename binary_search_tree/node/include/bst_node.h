#include <stdbool.h>

class BstNode
{
    public:
    BstNode ();
    BstNode (int);
    virtual ~BstNode ();

    void clear ();
    virtual void display ();

    // getters:
    int num ();
    BstNode * left ();
    BstNode * right ();
    BstNode * parent ();

    // setters:
    void add_left (class BstNode *);
    void add_right (class BstNode *);
    void add_parent (class BstNode *);

    private:
    void initialize ();

    private:
    int _num;
    class BstNode * _left;
    class BstNode * _right;
    class BstNode * _parent;
};
