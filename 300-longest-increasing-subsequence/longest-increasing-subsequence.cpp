class Solution {
public:
    int check(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size())
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + check(i + 1, i, nums, dp);
        }
        int notake = check(i + 1, prev, nums, dp);
        return dp[i][prev + 1] = max(take, notake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLIS=1;

        for (int i = 1; i <n; i++) {
            for (int prev = 0; prev <i; prev++) {
                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[i], 1+dp[prev]);
                }
            }
            maxLIS = max(maxLIS, dp[i]);
        }
        return maxLIS;
    }
};