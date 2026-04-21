class Solution {
public:
int atMost(vector<int>& nums, int k){
 int l = 0, r = 0;
        int n = 0, sum = 0;
        while (r < nums.size()) {
           sum+=nums[r]%2;
            while(sum>k){
                sum-=nums[l]%2;
                l++;
            }
            n+=r-l+1;  
            r++;
        }
        return n;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
       return atMost(nums,k)-atMost(nums,k-1);
    }
};