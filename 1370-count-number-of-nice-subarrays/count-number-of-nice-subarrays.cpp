class Solution {
public:
int atMost(vector<int>& nums, int k){
 int l = 0, r = 0;
        int n = 0, c = 0;
        while (r < nums.size()) {
            if (nums[r] % 2 != 0) {
                c++;
            }
            while(c>k){
                if (nums[l] % 2 != 0){
                    c--;
                }
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