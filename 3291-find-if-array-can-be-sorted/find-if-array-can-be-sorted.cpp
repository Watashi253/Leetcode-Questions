class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int prevmax = 0, 
        currbits = __builtin_popcount(nums[0]), 
        currmin = nums[0], currmax = nums[0];

        for (int i = 1; i < n; i++) {
            int c = __builtin_popcount(nums[i]);

            if (c == currbits) {
                    currmax = max(currmax, nums[i]);
                    currmin = min(currmin, nums[i]);
            } 
            else {
                if (prevmax > currmin)
                    return false;

                currbits = c;
                prevmax = currmax;
                currmin = nums[i];
                currmax = nums[i];
            }
        }

        return prevmax <= currmin;
    }
};