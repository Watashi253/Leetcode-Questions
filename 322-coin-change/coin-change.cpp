class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for(int i=0; i<=amount; i++){
            if (i % coins[0] == 0)
            dp[0][i]= i / coins[0];
            else dp[0][i]=1e8;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int j = 0; j <= amount; j++) {
                int notake = dp[ind - 1][j];
                int take = 1e8;
                if (coins[ind] <= j) {
                    take = 1 + dp[ind][j - coins[ind]];
                }
                dp[ind][j] = min(take, notake);
            }
        }

        return dp[n-1][amount] >= 1e8 ? -1 : dp[n-1][amount];
    }
};