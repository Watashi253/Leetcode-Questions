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
class BSTIterator {
public:
stack<TreeNode*> st;
    bool reverse = true;
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushALL(root);
    }
    void pushALL(TreeNode* node) {
        while (node) {
            st.push(node);
            if (reverse) { // before
            node=node->right;
            }
            else 
            node=node->left;
        }
    }
    int next() {
        TreeNode* node=st.top();
        st.pop();
        if(reverse)
        pushALL(node->left);
        else
        pushALL(node->right);
        return node->val;
    }
    bool hasNext() {
        return !st.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false); 
        BSTIterator r(root, true); 
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j ==k) return true;
            else if(i+j< k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};