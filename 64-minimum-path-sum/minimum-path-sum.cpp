class Solution {
public:
int path(int row, int col, vector<vector<int>>& grid, int n, int m, 
vector<vector<int>>& dp){
    if(row==n-1 && col==m-1) return dp[row][col]=grid[row][col];
    if(row>n-1 || col>m-1) return dp[row][col]=1e8;

    if(dp[row][col]!=-1) return dp[row][col];

    return dp[row][col]=grid[row][col]+
           min(path(row+1,col, grid, n, m, dp), path(row,col+1, grid, n, m, dp));
}
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return path(0,0,grid, n, m, dp);
    }
};