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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* n= new TreeNode(val);
        if(root==NULL)
            return n;
        TreeNode* node=root;
        TreeNode* prev;
        while(node){
            prev=node;
            if(val>node->val){
                node=node->right;
            }
            else if(val<node->val){
                node= node->left;
            }
        }
        if(val>prev->val) prev->right=n;
        else prev->left=n;

        return root;
    }
};