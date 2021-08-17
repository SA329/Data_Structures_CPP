#include <cstdbool>

class BstNodeIf
{
    public:
    virtual bool isTerminalNode () const = 0;

    virtual void clear () = 0;
    virtual void display () const = 0;

    // getters:
    virtual BstNodeIf & left () const = 0;
    virtual BstNodeIf & right () const = 0;
    virtual BstNodeIf & parent () const = 0;

    // setters:
    virtual void addLeft (BstNodeIf &) = 0;
    virtual void addRight (BstNodeIf &) = 0;
    virtual void addParent (BstNodeIf &) = 0;
};

bool operator == (const BstNodeIf &, const BstNodeIf &);
