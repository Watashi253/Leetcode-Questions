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
void dfs(TreeNode* node, int l, vector<int> &ans){
    if(node==NULL) return;
        if(l==ans.size()) ans.push_back(node->val);

        dfs(node->right, l+1,ans);
        dfs(node->left, l+1,ans);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        dfs(root,0,ans);
        return ans;
    }
};