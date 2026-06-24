class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==1) return matrix[0][0];
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = matrix[0][i];
        }

        vector<int> curr(n, 0);
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n; i++) {
                    int d = 1e9, dl = 1e9, dr = 1e9;
                    d = matrix[j][i] + dp[i];
                    if (i - 1 >= 0)
                        dl = matrix[j][i] + dp[i-1];
                    if (i + 1 < n)
                        dr = matrix[j][i] + dp[i+1];

                    curr[i] = min(d, min(dl, dr));                
            }
            dp=curr;
        }
        int minSum = 1e9;
        for (int i = 0; i < n; i++) {
            minSum = min(minSum, dp[i]);
        }
        return minSum;
    }
};