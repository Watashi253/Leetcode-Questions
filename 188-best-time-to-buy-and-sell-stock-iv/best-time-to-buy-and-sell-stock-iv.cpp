class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int> buy(k+1,0), sell(k+1,0);

        for(int i=n-1; i>=0; i--){
            for(int tr=1; tr<=k; tr++){
                buy[tr]=max(-prices[i]+ sell[tr], buy[tr]);
                sell[tr]=max(+prices[i]+buy[tr-1], sell[tr]);
            }
        }
        return buy[k];
    }
};