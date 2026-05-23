class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> u = nums, num = nums;
        sort(num.begin(), num.end()); // sorted array
        if (u == num)
            return true;

        int c=0;
        for(int i=1; i<nums.size();i++){
            if(nums[i-1]>nums[i]) c++;
        }
        if(nums[nums.size()-1]>nums[0]) c++;
        return c<=1;
    }
};