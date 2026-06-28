class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned int> prev(amount + 1, 0);
        prev[0]=1;

        for (int coin: coins) {
            for (int amt = coin; amt<=amount; amt++) {
                prev[amt] += prev[amt-coin];
            }
        }
        return prev[amount];
    }
};