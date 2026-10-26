class Solution {
public:
void dfs(int r, int c, vector<vector<int>>& grid, long long& total){
    total+=grid[r][c];
    grid[r][c] = 0;
    int row=grid.size();
    int col=grid[0].size();

    int delr[]={-1, 0, 1, 0};
    int delc[]={0, 1, 0, -1};

    for(int i=0; i<4; i++){
        int nr=r+delr[i];
        int nc=c+delc[i];

        if(nr<row && nr>=0 && nc<col && nc>=0 && grid[nr][nc]!=0){
            dfs(nr, nc, grid, total);
        }
    }
}
    int countIslands(vector<vector<int>>& grid, int k) {
        int r=grid.size();
        int c=grid[0].size();

        int cnt=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]!=0){
                    long long t=0;
                    dfs(i, j, grid, t);
                    if(t%k==0)
                    cnt++;
                }
            }
        }

        return cnt;
    }
};