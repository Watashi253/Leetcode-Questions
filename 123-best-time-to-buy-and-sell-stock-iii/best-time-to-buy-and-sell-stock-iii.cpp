class Solution {
public:
int f(int i, int buy, int tr, vector<int>& prices, vector<vector<vector<int>>>& dp){
    if(tr==0 || i==prices.size()) return 0;

    if(dp[i][buy][tr]!=-1) return dp[i][buy][tr];

        if(buy){
            dp[i][buy][tr]=max(-prices[i]+ f(i+1, 0, tr, prices, dp), f(i+1, 1, tr, prices, dp));
        }
        else{
            dp[i][buy][tr]=max(+prices[i]+f(i+1, 1, tr-1, prices, dp), f(i+1, 0, tr, prices, dp));
        }
    return dp[i][buy][tr];
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy1=0, buy2=0, sell1=0, sell2=0;

        for(int i=n-1; i>=0; i--){
                buy1=max(-prices[i]+ sell1, buy1);
                sell1=max(+prices[i]+0, sell1);
                buy2=max(-prices[i]+ sell2, buy2);
                sell2=max(+prices[i]+buy1, sell2);
        }
        return buy2;
    }
};