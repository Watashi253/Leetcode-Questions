class Solution {
public:
int chori(int i, vector<int>& nums, vector<int>& dp){

if(i>=nums.size()) return 0;

if(dp[i]!=-1) return dp[i];

return dp[i]=max(chori(i+2, nums, dp)+nums[i], chori(i+1, nums, dp));
}
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, -1);
        return chori(0, nums, dp);
    }
};