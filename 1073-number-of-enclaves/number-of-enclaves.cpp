class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if(grid[0][i] == 1) {
                vis[0][i]=1;
                q.push({0,i});
            }
            if(grid[m - 1][i] == 1) {
                vis[m-1][i]=1;
                q.push({m-1,i});
            }
        }

        for (int j = 0; j < m; j++) {
            if(grid[j][0] == 1) {
                vis[j][0]=1;
                q.push({j,0});
            }
            if(grid[j][n - 1] == 1) {
                vis[j][n-1]=1;
                q.push({j,n-1});
            }
        }

        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
                !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }

        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vis[i][j]=1;
                    ans++;
                }
            }
        }
        return ans;
    }
};