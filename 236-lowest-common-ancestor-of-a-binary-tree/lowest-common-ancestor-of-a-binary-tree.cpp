/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getAncestor(TreeNode* root, TreeNode* p, vector<TreeNode*> &anc) {
        if (root == NULL)
            return false;

        anc.push_back(root);
        if (root->val == p->val)
            return true;
        if (getAncestor(root->left, p, anc) || getAncestor(root->right, p, anc))
            return true;

        anc.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> panc, qanc;
        getAncestor(root, p, panc);
        getAncestor(root, q, qanc);
        int i=0,j=0;
        TreeNode* lca=root;
        while(i<panc.size() && j<qanc.size()){
            if(panc[i]==qanc[j]){
                lca=panc[i];
                j++;
            }
            i++;
        }
        return lca;
    }
};