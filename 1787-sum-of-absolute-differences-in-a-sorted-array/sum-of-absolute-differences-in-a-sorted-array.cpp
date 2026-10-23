class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);

        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;
        for(int i=0; i<n; i++){
            int rightSum = totalSum - leftSum - nums[i];

            ans[i]=(nums[i] * i) - leftSum + rightSum - (nums[i] * (n - 1 - i));
            leftSum += nums[i];
        }

        return ans;
    }
};