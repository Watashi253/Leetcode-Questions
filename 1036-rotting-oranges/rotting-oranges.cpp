class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int tm=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue <pair<pair<int, int>, int>> q;
        int fresh=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

            vector<int> dr={-1,0,1,0};
            vector<int> dc={0,1,0,-1};
            int cnt=0;

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();

            tm=max(t, tm);
            vis[row][col]=2;

            for(int i=0; i<4; i++){
                int r=row+dr[i];
                int c=col+dc[i];

                if(r>=0 && r<n && c>=0 && c<m &&
                    !vis[r][c] && grid[r][c]==1){
                    vis[r][c]=1;
                    cnt++;
                    q.push({{r,c},t+1});
                }
            }
        }

        if(cnt!=fresh) return -1;
        return tm;
        
    }
};