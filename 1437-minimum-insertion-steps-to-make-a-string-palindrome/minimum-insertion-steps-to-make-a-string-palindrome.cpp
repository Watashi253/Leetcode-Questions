class Solution {
public:
int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<int> prev(n2 + 1, 0), cur(n2 + 1, 0);
        for (int i = 0; i <= n2; i++) {
            prev[i] = 0;
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                int take = -1e9, notake = -1e9;
                if (text1[i-1] == text2[j-1]) {
                    take = 1 + prev[j - 1];
                } else {
                    notake = max(prev[j], cur[j - 1]);
                }
                cur[j] = max(take, notake);
            }
            prev = cur;
        }
        return prev[n2];
    }
    int minInsertions(string s) {
        string s2=s;
        reverse(s.begin(), s.end());
        int m= longestCommonSubsequence(s, s2); 
        return s.size()-m;
    }
};