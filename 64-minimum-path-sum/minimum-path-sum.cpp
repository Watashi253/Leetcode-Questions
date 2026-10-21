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
        vector<vector<int>> dp(n+1, vector<int>(m+1,1e8));
        dp[n-1][m-1]=grid[n-1][m-1];

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 && j==m-1){
                    dp[i][j]=grid[i][j];
                }
                else dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }

        return dp[0][0];
    }
};