class Solution {
public:
    int check(int row, int col, vector<vector<int>>& obstacleGrid,
    vector<vector<int>>& dp) {
        if(obstacleGrid[row][col] == 1)
        return dp[row][col]=0;
        if (row == 0 && col == 0)
            return dp[0][0]=1;

        int l = 0;
        int u = 0;

        if(dp[row][col]!=-1) return dp[row][col];

        if (row - 1 >= 0)
            l += check(row - 1, col, obstacleGrid, dp);

        if (col - 1 >= 0)
            u += check(row, col-1, obstacleGrid, dp);

        return dp[row][col]=l + u;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,-1));
        return check(m - 1, n - 1, obstacleGrid, dp);
    }
};