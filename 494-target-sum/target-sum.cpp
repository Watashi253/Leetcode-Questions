class Solution {
public:
int check(int ind, int target, vector<int> &nums, 
vector<unordered_map<int, int>>& dp){
    if(ind==0){
        if (nums[0] == 0 && target == 0) return 2;
        if(nums[ind]==abs(target))return 1;
    
    return 0;
    }
    
    if (dp[ind].count(target)) {
            return dp[ind][target];
        }

    int add=check(ind-1, target-nums[ind], nums, dp);
    int sub=check(ind-1, target+nums[ind], nums, dp);

    return dp[ind][target]=add+sub;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unordered_map<int, int>> dp(n);
        return check(n-1, target, nums, dp);
    }
};