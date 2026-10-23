class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int idx = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool asc = true;
        bool desc = true;

        for (int i = 1; i < n; i++) {
            
            int c=nums[(idx + i) % n];

            if (c != i) {
                asc = false;
            }

            if (c !=n-i) {
                desc = false;
            }

            if (!asc && !desc) {
                return -1;
            }
        }

        if (asc) {
            return min(idx, n - idx + 2);
        }

        return min(n - idx, idx + 2);
    }
};