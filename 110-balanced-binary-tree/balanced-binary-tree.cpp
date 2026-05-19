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
int depth(TreeNode* node, int c){
if(node==NULL) return c;
c=max(depth(node->left,c+1),depth(node->right,c+1));
return c;
}
bool check(TreeNode* node){
if(node==NULL) return true;

int diff=depth(node->left,0)-depth(node->right,0);//1-2
if(diff>1 || diff<-1) return false;

else if(check(node->left) && check(node->right))
return true;

return false;
}
    bool isBalanced(TreeNode* root) {
        TreeNode* node=root;
        if(node==NULL) return true;        
        return check(node);
    }
};