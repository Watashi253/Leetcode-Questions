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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        //(col,row)
        map<int,map<int,multiset<int>>> hash;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        
while(!q.empty()){
    auto it=q.front();
    q.pop();
    TreeNode* node=it.first;
    int col=it.second.first, row=it.second.second;
    hash[col][row].insert(node->val);
    if(node->left){
        q.push({node->left,{col-1,row+1}});
    }
    if(node->right){
        q.push({node->right,{col+1,row+1}});
    }
}

for(auto i:hash){
    vector<int> cols;
    for(auto j: i.second){
        cols.insert(cols.end(), j.second.begin(),j.second.end());
    }
    ans.push_back(cols);
}
        return ans;
    }
};