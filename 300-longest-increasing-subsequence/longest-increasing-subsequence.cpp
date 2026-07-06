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
        vector<int> next(n + 1, 0), cur(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int take = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + next[i+1];
                }
                int notake = next[prev+1];
                cur[prev + 1] = max(take, notake);
            }
            next=cur;
        }
        return next[0];
    }
};