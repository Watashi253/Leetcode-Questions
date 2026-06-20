class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[1]=1;
        int prev=1, prev2=1;
        for(int i=2; i<=n; i++){
            dp[i]=prev+prev2;
            prev2=prev;
            prev=dp[i];
        }
        return dp[n];
    }
};