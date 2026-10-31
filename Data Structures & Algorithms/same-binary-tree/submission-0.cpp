/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    bool ok = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p, q);
        return ok;
    }
    void dfs(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            if (p || q)
                ok = false;
            return;
        }

        if (p->val != q->val) {
            ok = false;
            return;
        }
        dfs(p->left, q->left);
        dfs(p->right, q->right);
    }
};
