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
void trying(TreeNode* root,int &cnt, int &ans){
    if(root==NULL) return;
    trying(root->left,cnt, ans);
    cnt--;
    if(cnt==0){
       ans=root->val; 
    }
    trying(root->right,cnt, ans);
}
    int kthSmallest(TreeNode* root, int k) {
        int cnt=k, ans;
        trying(root, cnt, ans);
        return ans;
    }
};