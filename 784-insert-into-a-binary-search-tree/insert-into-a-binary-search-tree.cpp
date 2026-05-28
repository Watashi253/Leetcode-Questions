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
        while(node){
            if(val>node->val){
                if(!node->right){
                    node->right=n;
                    break;
                }
                node=node->right;
            }
            else if(val<node->val){
                if(!node->left){
                    node->left=n;
                    break;
                }
                node= node->left;
            }
        }
        return root;
    }
};