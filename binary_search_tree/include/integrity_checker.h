#include <stdbool.h>

class Bst;
class BstNode;

class IntegrityChecker
{
    public:
    IntegrityChecker ();
    virtual ~IntegrityChecker ();

    bool checkIntegrity (const Bst &) const;
    void breakParentIntegrity(Bst *, int);

    private:
    bool checkEmptyTreeIntegrity (const Bst &) const;
    void breakParentOfRootNode (Bst *);
    void breakParentOfNonRootNode (Bst *, int);
    BstNode * findNodeToBreak (const Bst &, int) const;
    bool checkIntegrityLessThan (const BstNode &, int) const;
    bool checkLessThan (const BstNode &, int) const;
    bool checkIntegrityGreaterThan (const BstNode &, int) const;
    bool checkGreaterThan (const BstNode &, int) const;
    bool checkParentIntegrity (const Bst &, const BstNode *) const;
    bool nodeParentIsNotNull (const Bst &, const BstNode &) const;
    bool rootNodeParentIsNull (const Bst &, const BstNode &) const;
    bool checkOrderIntegrityImpl (const BstNode &) const;
    bool checkOrderIntegrity (const BstNode &) const;
};
