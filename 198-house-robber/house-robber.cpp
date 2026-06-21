class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 0);
        dp[0]=nums[0];
        int prev1=dp[0];
        int prev2=0;
        for(int i=1; i<n; i++){
            int pick=nums[i]+prev2;
            int dontpick=prev1;
            dp[i]=max(pick, dontpick);
            prev1=dp[i];
            prev2=dp[i-1];
        }
        return dp[n-1];
    }
};