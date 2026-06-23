class Solution {
public:
    int check(int row, int col, int m, int n, vector<vector<int>> &dp) {
        if (row == m-1 && col == n-1)
            return dp[m-1][n-1]=1;

if(dp[row][col]!=-1) return dp[row][col];

        int r = 0;
        int d = 0;

        if (col + 1 < n)
            r = check(row, col + 1, m, n, dp);
        if (row + 1 < m)
            d = check(row + 1, col, m, n, dp);

        return dp[row][col]= r + d;
    }
    int uniquePaths(int m, int n) { 
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return check(0, 0, m, n, dp); 
        }
};