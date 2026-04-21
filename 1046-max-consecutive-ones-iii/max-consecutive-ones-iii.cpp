class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int mx = 0, c = 0;
        pair<int, int> ind;
        while (r < nums.size()) {
            if (nums[r] == 0) {
                c++;
            }
            if (c > k) {
                if (nums[l] == 0) {
                    c--;
                }
                l++;
            }
            if (c <= k)
                mx = max(mx, r - l + 1);
            r++;
        }
        return mx;
    }
};