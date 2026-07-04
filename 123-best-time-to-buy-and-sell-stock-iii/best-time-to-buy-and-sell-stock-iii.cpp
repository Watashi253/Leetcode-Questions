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
        vector<vector<int>> next(2, vector<int>(3,0)), cur(2, vector<int>(3,0));

        for(int i=n-1; i>=0; i--){
            for(int tr=1; tr<3; tr++){
                cur[1][tr]=max(-prices[i]+ next[0][tr], next[1][tr]);
                cur[0][tr]=max(+prices[i]+next[1][tr-1], next[0][tr]);
                next=cur;
            }
        }
        return next[1][2];
    }
};