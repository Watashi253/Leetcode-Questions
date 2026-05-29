/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
 TreeNode* solve(TreeNode* root, int min, int max) {
        if (!root)
            return root;
        if (root->val < min)
            return solve(root->right, min, max);
        if (root->val > max)
            return solve(root->left, min, max);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, min(p->val, q->val), max(p->val, q->val));
    }
};