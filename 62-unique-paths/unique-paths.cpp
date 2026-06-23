class Solution {
public:
    int check(int row, int col, vector<vector<int>> &dp) {
        if (row == 0 && col == 0)
            return dp[0][0]=1;

if(dp[row][col]!=-1) return dp[row][col];

        int r = 0;
        int d = 0;

        if (col - 1 >= 0)
            r = check(row, col - 1, dp);
        if (row - 1 >= 0)
            d = check(row - 1, col, dp);

        return dp[row][col]= r + d;
    }
    int uniquePaths(int m, int n) { 
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return check(m-1, n-1, dp); 
        }
};