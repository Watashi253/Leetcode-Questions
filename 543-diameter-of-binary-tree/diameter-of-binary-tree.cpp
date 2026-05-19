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
    int maxDepth(TreeNode* node, int &diameter) {
        if (node == NULL)
            return 0;
        int left=maxDepth(node->left, diameter);
        int right=maxDepth(node->right, diameter);
        diameter= max(diameter, left+right);
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        maxDepth(root, diameter);
        return diameter;
    }
};