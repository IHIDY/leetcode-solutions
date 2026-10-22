// 687. Longest Univalue Path
// dfs(x) = longest downward chain (in edges) of nodes equal to x->val.
// Answer is updated with left + right chain (x as the turning point);
// only one side is returned to the parent.
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;

        auto dfs = [&](this auto&& dfs, TreeNode* x) -> int {
            if (!x) return 0;

            int l = dfs(x->left), r = dfs(x->right);
            l = (x->left  && x->left->val  == x->val) ? l + 1 : 0;
            r = (x->right && x->right->val == x->val) ? r + 1 : 0;

            ans = max(ans, l + r);
            return max(l, r);
        };

        dfs(root);
        return ans;
    }
};
