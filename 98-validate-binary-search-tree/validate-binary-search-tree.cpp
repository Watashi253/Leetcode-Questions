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
void check(TreeNode* root, vector<int> &inorder){
    if(root==NULL) return;
    check(root->left, inorder);
    inorder.push_back(root->val);
    check(root->right, inorder);
}
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        check(root, inorder);
        for(int i=0; i<inorder.size()-1; i++){
        if(inorder[i]>=inorder[i+1])
        return false;
        }
        return true;
    }
};