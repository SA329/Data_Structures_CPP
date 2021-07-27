#include <stdbool.h>

class BstNode
{
    public:
    BstNode ();
    BstNode (int);
    virtual ~BstNode ();

    void clear ();
    virtual void display () const;

    // getters:
    int num () const;
    BstNode * left () const;
    BstNode * right () const;
    BstNode * parent () const;

    // setters:
    void addLeft (BstNode *);
    void addRight (BstNode *);
    void addParent (BstNode *);

    private:
    void initialize ();

    private:
    int _num;
    BstNode * _left;
    BstNode * _right;
    BstNode * _parent;
};
