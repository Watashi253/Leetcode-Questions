class Solution {
public:
// int check(int row, int col, int pror, int prod, vector<vector<int>>& grid){

//     pror*=check(row+1, col, pror, prod, grid);
//     prod*=chck(row, col+1, pror, prod, grid);
//     return max(pror, prod);
// }
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;

        vector<vector<long long>> max_dp(m, vector<long long>(n, 0));
        vector<vector<long long>> min_dp(m, vector<long long>(n, 0));

        max_dp[0][0] = grid[0][0];
        min_dp[0][0] = grid[0][0];

        for(int j = 1; j < n; j++) {
            max_dp[0][j] = max_dp[0][j-1] * grid[0][j];
            min_dp[0][j] = min_dp[0][j-1] * grid[0][j];
        }

        for(int i = 1; i < m; i++) {
            max_dp[i][0] = max_dp[i-1][0] * grid[i][0];
            min_dp[i][0] = min_dp[i-1][0] * grid[i][0];
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                long long val = grid[i][j];
                
                long long p1 = max_dp[i-1][j] * val; // Max from above
                long long p2 = min_dp[i-1][j] * val; // Min from above
                long long p3 = max_dp[i][j-1] * val; // Max from left
                long long p4 = min_dp[i][j-1] * val; // Min from left
                
                // Store the new max and min
                max_dp[i][j] = max({p1, p2, p3, p4});
                min_dp[i][j] = min({p1, p2, p3, p4});
            }
        }

        long long ans = max_dp[m-1][n-1];
        if (ans < 0) return -1;
        return ans % MOD;
    }
};