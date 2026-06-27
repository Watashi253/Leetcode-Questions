class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
        for(int i=0; i<=amount; i++){
            if (i % coins[0] == 0)
            prev[i]= i / coins[0];
            else prev[i]=1e8;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int j = 0; j <= amount; j++) {
                int notake = prev[j];
                int take = 1e8;
                if (coins[ind] <= j) {
                    take = 1 + cur[j - coins[ind]];
                }
                cur[j] = min(take, notake);
            }
            prev=cur;
        }

        return prev[amount] >= 1e8 ? -1 : prev[amount];
    }
};