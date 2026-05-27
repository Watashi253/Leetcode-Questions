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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> parent;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->right) {
                    q.push(node->right);
                    parent[node->right] = node;
                }
                if (node->left) {
                    q.push(node->left);
                    parent[node->left] = node;
                }
            }
        }

        int d = 0;
        unordered_map<TreeNode*, bool> vis;
        q.push(target);
        vis[target] = true;

        while (!q.empty()) {
            int n = q.size();
            if (d == k)
                break;
            d++;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
               if (node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    q.push(node->left);
                }
               if (node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    q.push(node->right);
                }
              if (parent[node] && !vis[parent[node]]) {
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};