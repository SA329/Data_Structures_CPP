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
    void addLeft (class BstNode *);
    void addRight (class BstNode *);
    void addParent (class BstNode *);

    private:
    void initialize ();

    private:
    int _num;
    class BstNode * _left;
    class BstNode * _right;
    class BstNode * _parent;
};
