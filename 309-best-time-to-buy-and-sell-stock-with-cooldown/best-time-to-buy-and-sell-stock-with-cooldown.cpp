class Solution {
public:
int f(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
    if(i==prices.size()) return 0;

    if(dp[i][buy]!=-1) return dp[i][buy];
    int profit=0;
    if(buy==0){
        profit=max(-prices[i]+f(i+1, 1, prices, dp), f(i+1, 0, prices, dp));
    }
    else if(buy==1){
        profit=max(+prices[i]+f(i+1, 2, prices, dp), f(i+1, 1, prices, dp));
    }
    else {
        profit=0+f(i+1, 0, prices, dp);
    }
    return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=0, sell=0, cool=0;

        for(int i=n-1; i>=0; i--){
            int hold=buy;
            buy=max(-prices[i]+sell, buy);
            sell=max(+prices[i]+cool, sell);
            cool=hold;
        }
        return buy;
    }
};