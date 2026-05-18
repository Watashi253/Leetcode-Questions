class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int l = 0, r=0, n = nums.size();
        int c = 0, total = 0;
        unordered_map<int,int> freq;
        while(r<n) {
            if (freq[nums[r]] == 0)
                c++;
            freq[nums[r]]++;
            while (c > k) {
                freq[nums[l]]--;
                if(freq[nums[l]]==0)c--;
                l++;
            }
            
                total += r-l+1;
            
            r++;
        }
        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k){
        return atMost(nums,k)-atMost(nums,k-1);
    }
};