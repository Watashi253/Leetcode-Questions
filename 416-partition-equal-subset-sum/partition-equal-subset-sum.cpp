class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1)
            return false;
        
        int k=sum/2;
        vector<bool> prev(k + 1, 0), cur(k + 1, 0);
        prev[0] = cur[0] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int j = 1; j <= k; j++) {
                bool notake = prev[j];
                bool take = false;
                if (j >= nums[ind])
                    take = prev[j-nums[ind]];

                cur[j]= notake | take;
            }
            prev=cur;
        }

        return prev[k];
    }
};