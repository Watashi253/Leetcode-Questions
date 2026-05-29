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

TreeNode* Find(TreeNode* node){
while(node->right){
    node=node->right;
}
return node;
}

TreeNode* helper(TreeNode* node){
if(!node->left){
    TreeNode* temp=node->right;
    delete node;
    return temp;
}
if(!node->right){
    TreeNode* temp=node->left;
    delete node;
    return temp;
}
TreeNode* leftChild = node->left;
TreeNode* rightChild=node->right;
TreeNode* rightMostofLeft=Find(node->left);
rightMostofLeft->right=rightChild;
delete node;
return leftChild;
}

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key){
            return helper(root);
        }
        TreeNode* node=root;
        while(node){

            if(node->val>key){
                if(node->left && node->left->val==key){
                node->left=helper(node->left);
                break;
                }
                else{
                    node=node->left;
                }
            }
            else{
                if(node->right && node->right->val==key){
                node->right=helper(node->right);
                break;
                }
                else{
                    node=node->right;
                }
            }    
        }
        return root;
    }
};