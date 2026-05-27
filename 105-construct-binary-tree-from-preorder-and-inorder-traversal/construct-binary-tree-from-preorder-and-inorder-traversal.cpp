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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
    vector<int>& inorder, int inStart, int inEnd, map<int, int> &hash) {
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);

        int inroot=hash[root->val];
        int leftsize=inroot-inStart;

        root->left=build(preorder, preStart+1, preStart+leftsize,
        inorder, inStart, inroot-1, hash);        
        root->right=build(preorder, preStart+leftsize+1, preEnd,
        inorder, inroot+1, inEnd, hash);   
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> hash;
        for (int i = 0; i <inorder.size(); i++){
            hash[inorder[i]]=i;
        }
        int n=preorder.size();
        TreeNode* root=build(preorder,0, n-1,
        inorder, 0, n-1, hash);

        return root;
    }
};