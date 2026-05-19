/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* node) {
        if (node == NULL)
            return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        if (root == NULL)
            return d;           
        d= maxDepth(root->left) + maxDepth(root->right);
        int dl=diameterOfBinaryTree(root->left);
        int dr=diameterOfBinaryTree(root->right);
        return max(d,max(dl,dr));
    }
};