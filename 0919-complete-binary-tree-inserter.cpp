// 919. Complete Binary Tree Inserter
// Number nodes level by level starting from 1: the parent of idx is idx / 2,
// and idx is a left child if even, a right child if odd.
class CBTInserter {
    TreeNode* root;
    int cnt;                                  // current number of nodes

    int countNodes(TreeNode* x) {
        return x ? 1 + countNodes(x->left) + countNodes(x->right) : 0;
    }

    TreeNode* nodeAt(int idx) {
        if (idx == 1) return root;
        TreeNode* parent = nodeAt(idx / 2);
        return idx % 2 == 0 ? parent->left : parent->right;
    }

public:
    CBTInserter(TreeNode* root) : root(root), cnt(countNodes(root)) {}

    int insert(int val) {
        int idx = ++cnt;                      // index of the new node
        TreeNode* parent = nodeAt(idx / 2);
        TreeNode* node = new TreeNode(val);

        if (idx % 2 == 0) parent->left = node;
        else              parent->right = node;

        return parent->val;
    }

    TreeNode* get_root() { return root; }
};
