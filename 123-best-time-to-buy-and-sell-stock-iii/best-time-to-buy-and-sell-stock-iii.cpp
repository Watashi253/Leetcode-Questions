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
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

        for(int i=n-1; i>=0; i--){
            for(int tr=1; tr<3; tr++){
                dp[i][1][tr]=max(-prices[i]+ dp[i+1][0][tr], dp[i+1][1][tr]);
                dp[i][0][tr]=max(+prices[i]+dp[i+1][1][tr-1], dp[i+1][0][tr]);
            }
        }
        return dp[0][1][2];
    }
};