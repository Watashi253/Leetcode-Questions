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
void find(TreeNode* root, vector<int> & inorder){
   if(root==NULL) return;
   find(root->left, inorder);
   inorder.push_back(root->val);
   find(root->right, inorder);
}
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        find(root, inorder);
        int l = 0, r = inorder.size() - 1;
        while (l < r) {
            int sum = inorder[l] + inorder[r];

            if (sum == k) return true;
            if (sum < k) l++;
            else r--;
        }
        return false;
    }
};