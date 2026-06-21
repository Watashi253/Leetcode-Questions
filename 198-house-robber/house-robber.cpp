class Solution {
public:
int check(int n, vector<int>& nums, vector<int>& dp){
    if(n==0) return dp[0]=nums[0];
    if(n<0) return 0;

if(dp[n]!=-1) return dp[n];

int pick=check(n-2, nums,dp)+nums[n];
int dontpick=check(n-1, nums, dp);

return dp[n]=max(pick, dontpick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);
        return check(n-1, nums, dp);
    }
};