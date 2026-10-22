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
TreeNode* buildTree(vector<int>& nums, int left, int right){
if (left > right) {
            return nullptr;
        }

    int mx=left;
    for(int i=left; i<=right; i++){
        if(nums[i]>nums[mx]){
            mx=i;
        }
    }

    TreeNode* root = new TreeNode(nums[mx]);
    root->left=buildTree(nums, left, mx-1);
    root->right=buildTree(nums, mx+1, right);

    return root;
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
};