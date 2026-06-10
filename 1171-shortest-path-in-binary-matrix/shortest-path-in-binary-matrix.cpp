class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        vector<vector<int>> dis(n, vector<int>(n,1e9));

        queue<pair<int, pair<int, int>>> q;
        q.push({1,{0,0}});
        dis[0][0]=1;
        vector<int> dr={-1,-1,0,1,1,1,0,-1};
        vector<int> dc={0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=0; i<8; i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n &&
                dis[nrow][ncol]>d+1 && grid[nrow][ncol]==0){
                    dis[nrow][ncol]=1+d;
                    q.push({dis[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        if(dis[n-1][n-1]==1e9) return -1;
        
        return dis[n-1][n-1];
    }
};