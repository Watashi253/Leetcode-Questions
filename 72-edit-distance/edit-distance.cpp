class Solution {
public:
    int check(int i, int j, string& s, string& t, vector<vector<int>>& dp) {

        if (j == 0)
            return i;
        if (i == 0)
            return j;

        if (dp[i][j] != -1)
            return dp[i][j];

        int nodo, del, replace, ins;
        nodo = del = replace = ins = 1e9;
        if (s[i - 1] == t[j - 1]) {
            nodo = check(i - 1, j - 1, s, t, dp);
        } else {
            del = 1 + check(i - 1, j, s, t, dp);
            replace = 1 + check(i - 1, j - 1, s, t, dp);
            ins = 1 + check(i, j - 1, s, t, dp);
        }
        return dp[i][j] = min({del, replace, ins, nodo});
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for(int i=0; i<=m; i++) dp[i][0]=i;
        for(int j=0; j<=n; j++) dp[0][j]=j;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int nodo, del, replace, ins;
                nodo = del = replace = ins = 1e9;
                if (word1[i - 1] == word2[j - 1]) {
                    nodo = dp[i - 1][j - 1];
                } else {
                    del = 1 + dp[i - 1][j];
                    replace = 1 + dp[i - 1][j - 1];
                    ins = 1 + dp[i][j - 1];
                }
                dp[i][j] = min({del, replace, ins, nodo});
            }
        }
        return dp[m][n];
    }
};