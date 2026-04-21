class Solution {
public:
int applymathidiot(vector<int>& nums, int goal){
 if(goal<0) return 0;
        int l = 0, r = 0;
        int sum = 0, n = 0;
        while (r < nums.size()) {
            sum += nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            n+=r-l+1;
            r++;
        }
        return n;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return applymathidiot(nums,goal)-applymathidiot(nums,goal-1);
    }
};