class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<int> &vis, int num) {
        queue<int> q;
        q.push(num);
        vis[num] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : graph[node]) {
                if (vis[it] == -1) {
                    vis[it] = !vis[node];
                    q.push(it);
                } else if (vis[it] == vis[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        for(int i=0; i<graph.size(); i++){
            if(vis[i]==-1){
            if(bfs(graph, vis, i)==false){
                return false;
            }
            }
        }
        return true;
    }
};