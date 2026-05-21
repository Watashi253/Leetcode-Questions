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
void sTree(TreeNode* node1, TreeNode* node2, bool &flag){
    if(node1==NULL && node2==NULL) return;
    if(node1 && node2 && node1->val==node2->val){
        sTree(node1->left, node2->right, flag);
        sTree(node1->right, node2->left, flag);
        return;
    }
flag=false;
}
    bool isSymmetric(TreeNode* root) {
        bool flag=true;
        sTree(root->left, root->right, flag);
        return flag;
    }
};