class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }

        bool is_forward = true;
        bool is_reverse = true;

        for (int i = 0; i < n; i++) {
            if (nums[(idx + i) % n] != i) {
                is_forward = false;
            }

            if (nums[(idx - i + n) % n] != i) {
                is_reverse = false;
            }
        }

        int min_ops = 1e9;

        if (is_forward) {
            min_ops = min(min_ops, min(idx, n - idx + 2));
        }
        if (is_reverse) {
            min_ops = min(min_ops, min(n - idx, idx + 2));
        }

        return min_ops == 1e9 ? -1 : min_ops;
    }
};