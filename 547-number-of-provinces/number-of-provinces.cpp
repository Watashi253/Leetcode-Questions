class Solution {
public:
void dfs(vector<vector<int>>& isConnected, vector<int> &vis, int num){
    vis[num]=1;
    int n = isConnected.size();

    for(int j=0; j<n; j++){
        if(isConnected[num][j]==1 && !vis[j]){
            dfs(isConnected, vis, j);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int c=0;
        vector<int> vis(n);
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                c++;
                dfs(isConnected, vis, i);
            }
        }
        return c;
    }
};