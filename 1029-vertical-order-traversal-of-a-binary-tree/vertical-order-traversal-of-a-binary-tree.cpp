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

    void dfs(TreeNode* root, int row, int col,
            map<int, vector<pair<int,int>>>& mp) {
        
        if(root == NULL) return;

        mp[col].push_back({row, root->val});

        dfs(root->left, row + 1, col - 1, mp);
        dfs(root->right, row + 1, col + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> hash;

        dfs(root,0,0,hash);

        for(auto it: hash){
            vector<pair<int,int>> v = it.second;
            sort(v.begin(), v.end());//sort row wise

            vector<int> temp;

            for(auto p : v) {
                temp.push_back(p.second);
            }

            ans.push_back(temp);
        }
    return ans;
    }
};