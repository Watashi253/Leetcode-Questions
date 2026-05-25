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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            long long mn=q.front().second;
            long long first=0, last=0;
            for(int i=0; i<n; i++){
                auto it=q.front();
                q.pop();
                TreeNode* node=it.first;
                long long ind=it.second-mn;

                if(i==0)first=ind;
                if(i==n-1)last=ind;

                if(node->left)q.push({node->left, 2*ind+1});
                if(node->right)q.push({node->right,2*ind+2});
            }
            ans=max(ans, last-first+1);
        }
        return (int)ans;
    }
};