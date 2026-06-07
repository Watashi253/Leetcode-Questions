class Solution {
public:
bool dfs(vector<vector<int>> &graph, vector<int> &ans, vector<int> &vis,
vector<int> &path, int num){
vis[num]=1;
path[num]=1;
for(auto it: graph[num]){
    if(!vis[it]){
        if(dfs(graph, ans, vis, path, it)==true)
        return true;
    }
    else if(path[it]){
        return true;
    }
}
path[num]=0;
ans.push_back(num);
return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> path(n,0);
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(graph, ans, vis, path, i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
        }
};