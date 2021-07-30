#include <stdbool.h>

class Bst;
class BstNode;

class IntegrityChecker
{
    public:
    IntegrityChecker ();
    virtual ~IntegrityChecker ();

    bool execute (const Bst &) const;
    void breakParent(Bst *, int);

    private:
    bool checkEmptyTree (const Bst &) const;
    void breakParentOfRootNode (Bst *);
    void breakParentOfNonRootNode (Bst *, int);
    BstNode * findNodeToBreak (const Bst &, int) const;
    bool checkLessThan (const BstNode *, int) const;
    bool isLessThan (const BstNode &, int) const;
    bool checkGreaterThan (const BstNode *, int) const;
    bool isGreaterThan (const BstNode &, int) const;
    bool checkParent (const Bst &, const BstNode *) const;
    bool nodeParentIsNotNull (const Bst &, const BstNode &) const;
    bool rootNodeParentIsNull (const Bst &, const BstNode &) const;
    bool checkOrderImpl (const BstNode *) const;
    bool checkOrder (const BstNode &) const;
};
