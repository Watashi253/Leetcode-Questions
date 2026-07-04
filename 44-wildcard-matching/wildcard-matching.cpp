class Solution {
public:
    bool check(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return true;
        if (j == 0 && i > 0)
            return false;
        if (i == 0 && j > 0) {
            for (int k = 1; k <= j; k++) {
                if (p[k-1] != '*')
                    return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if (s[i-1] == p[j-1] || p[j-1] == '?')
            return dp[i][j]=check(i - 1, j - 1, s, p, dp);
        if (p[j-1] == '*') {
            return dp[i][j]=check(i - 1, j, s, p, dp) || check(i, j - 1, s, p, dp);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return check(m, n, s, p, dp);
    }
};