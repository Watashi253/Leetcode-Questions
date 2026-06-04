class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int num=0;
        int walk=0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    num++;
                    if(i==0 || j==0 || i==n-1 || j==m-1){
                        vis[i][j]=1;
                        q.push({i,j});
                        walk++;
                    }
                }
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

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                    walk++;
                }
            }
        }

        return num-walk;
    }
};