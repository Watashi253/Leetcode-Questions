class Solution {
public:
int check(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){
    if(i<0) return 0;

if(dp[i][prev]!=-1) return dp[i][prev];
    int take=-1e9;
    int n = nums.size();
    if(prev==n || nums[i]<nums[prev]){
        take=1+check(i-1, i, nums, dp);
    }
    int notake=check(i-1, prev, nums, dp);
    return dp[i][prev]=max(take, notake);
}    
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return check(n-1, n, nums, dp);
    }
};