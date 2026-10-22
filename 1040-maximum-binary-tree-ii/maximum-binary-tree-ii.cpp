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
vector<int> inorder(TreeNode* root){
    stack<TreeNode*> st;
        TreeNode* node=root;
        vector<int> ans;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty())break;
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
}
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        vector<int> graph=inorder(root);
        graph.push_back(val);
        return buildTree(graph, 0, graph.size()-1);
    }
};