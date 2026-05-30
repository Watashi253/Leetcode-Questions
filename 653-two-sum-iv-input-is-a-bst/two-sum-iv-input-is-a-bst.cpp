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
        set<int> look;
        find(root, inorder);
        // look.push_back(k-inorder[0]);
        for(int i=0; i<inorder.size(); i++){
            int sum=k-inorder[i];
            if(look.find(sum)!=look.end())
            return true;
            look.insert(inorder[i]);
        }
        return false;
    }
};