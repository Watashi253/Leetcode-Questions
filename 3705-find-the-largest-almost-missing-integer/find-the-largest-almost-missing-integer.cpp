class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size(), mx = INT_MIN, maxi = INT_MIN;
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            mx = max(mx, nums[i]);
        }

        if (k > 1 && k < n) {
            if (freq[nums[0]] > 1 && freq[nums[n-1]]>1) {
                return -1;
            }
            else if(freq[nums[0]] > 1)
            return nums[n-1];
            else if(freq[nums[n-1]] > 1)
            return nums[0];
            else 
            return max(nums[0], nums[n-1]);       
        } else if (k == 1) {
            for (auto& [el, c] : freq) {
                if (c == 1 && el > maxi) {
                    maxi = el;
                }
            }
            return maxi == INT_MIN ? -1 : maxi;
        }
        return mx;
    }
};