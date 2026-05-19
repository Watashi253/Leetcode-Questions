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
int check(TreeNode* node, int c){
if(node==NULL) return c;
return c=max(check(node->left,c+1),check(node->right,c+1));
}
    int maxDepth(TreeNode* root) {
        TreeNode* node=root;
        int c=0;
        if(node==NULL) return c;
        return check(node,c);
    }
};