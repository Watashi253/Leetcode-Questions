class Solution {
public:
int f(int i, int buy, int &fee, vector<int>& prices, vector<vector<int>>& dp){
    if(i==prices.size()) return 0;

    if(dp[i][buy]!=-1) return dp[i][buy];

    int profit=0;
    if(buy){
        profit=max(-prices[i]+f(i+1, 0, fee, prices, dp), f(i+1, 1, fee, prices, dp));
    }
    else{
        profit=max(+prices[i]-fee +f(i+1, 1, fee, prices, dp), f(i+1, 0, fee, prices, dp));
    }
    return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> next(2,0), cur(2,0);

        for(int i=n-1; i>=0; i--){
            cur[1]=max(-prices[i]+next[0], next[1]);
            cur[0]=max(prices[i]-fee+next[1], next[0]);
            next=cur;
        }
        return next[1];
    }
};