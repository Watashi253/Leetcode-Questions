class Solution {
public:
    int climb(int i, int n, vector<int>& costs, vector<int>& dp) {

        if(i>n) return 1e8;
        if (i == n) return 0;
            
    if(dp[i]!=-1) return dp[i];

int add1=1e8, add2=1e8, add3=1e8;
    if(i+1<=n) add1=climb(i + 1, n, costs, dp)+1+costs[i];
    if(i+2<=n) add2=climb(i + 2, n, costs, dp)+4+costs[i+1];
    if(i+3<=n) add3=climb(i + 3, n, costs, dp)+9+costs[i+2];

return dp[i]=min(add1, min(add2, add3));
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, 1e8);

        dp[n] = 0;

        for(int i=n-1; i>=0; i--){
            
       int add1=1e8, add2=1e8, add3=1e8;
    if(i+1<=n) add1=dp[i + 1]+1+costs[i];
    if(i+2<=n) add2=dp[i + 2]+4+costs[i+1];
    if(i+3<=n) add3=dp[i + 3]+9+costs[i+2];

    dp[i]=min({add1, add2, add3});
        }

return dp[0];
    }
};