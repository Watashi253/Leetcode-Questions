class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n=nums.size(), l=0, r=0;
        int mx=0;
        
        while(r<n){
            freq[nums[r]]++;

            while(freq[nums[r]]>k){
                freq[nums[l]]--;
                l++;
            }

            mx=max(mx, r-l+1);
            r++;
        }

        return mx;
    }
};