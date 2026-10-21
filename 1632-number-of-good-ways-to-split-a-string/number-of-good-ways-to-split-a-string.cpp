class Solution {
public:
    int numSplits(string s) {
        int n=s.size();
        int left_count[26] = {0};
        int right_count[26] = {0};

        int distinct_left = 0;
        int distinct_right = 0;
        int good_splits = 0;

        for (char c : s) {
            if (right_count[c - 'a'] == 0) {
                distinct_right++;
            }
            right_count[c - 'a']++;
        }
        

        for(int i = 0; i < s.size() - 1; i++){
            char c = s[i];

            if (left_count[c - 'a'] == 0) {
                distinct_left++;
            }
            left_count[c - 'a']++;

            right_count[c - 'a']--;
            if (right_count[c - 'a'] == 0) {
                distinct_right--;
            }

            if (distinct_left == distinct_right) {
                good_splits++;
            }
        }

        return good_splits;
    }
};