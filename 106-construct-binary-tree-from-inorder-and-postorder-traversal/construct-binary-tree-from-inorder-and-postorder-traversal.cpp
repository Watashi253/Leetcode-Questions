/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(int postStart, int postEnd, vector<int>& postorder,
                    int inStart, int inEnd, vector<int>& inorder,
                    map<int, int> &hash){
        if(postStart>postEnd || inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot=hash[root->val];
        int leftsize=inRoot-inStart;

        root->left=build(postStart, postStart+leftsize-1, postorder,
        inStart, inRoot-1, inorder, hash);
        root->right=build(postStart+leftsize, postEnd-1,postorder,
        inRoot+1, inEnd, inorder, hash);

        return root;    
        }            
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> hash;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            hash[inorder[i]] = i;
        }
        TreeNode* root=build(0,n-1,postorder, 0,n-1,inorder, hash);
        return root;
    }
};