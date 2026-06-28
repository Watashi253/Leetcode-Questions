class Solution {
public:
    int check(int ind, int amt, vector<int>& coins, vector<vector<int>>& dp) {
        if (amt == 0)
            return 1;
        if (ind == 0) {
            if (amt % coins[0] == 0)
                return 1;
            return 0;
        }

        if (dp[ind][amt] != -1)
            return dp[ind][amt];

        int notake = check(ind - 1, amt, coins, dp);
        int take = 0;
        if (coins[ind] <= amt) {
            take = check(ind, amt - coins[ind], coins, dp);
        }
        return dp[ind][amt] = take + notake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
        prev[0]=cur[0]=1;
        for(int i=1; i<=amount; i++){
            if (i % coins[0] == 0) prev[i]=1;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int amt = 1; amt <= amount; amt++) {
                long long notake = prev[amt];
                long long take = 0;
                if (coins[ind] <= amt) {
                    take = cur[amt - coins[ind]];
                }
                cur[amt] = take + notake;
            }
            prev=cur;
        }
        return prev[amount];
    }
};