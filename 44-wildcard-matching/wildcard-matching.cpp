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
        vector<int> prev(n+1,0), cur(n+1,0);
        prev[0]=1;
        for(int j=1; j<=n; j++) {
            if(p[j-1]=='*')
            prev[j]=prev[j-1];
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
        if (s[i-1] == p[j-1] || p[j-1] == '?')
            cur[j]=prev[j - 1];
        else if (p[j-1] == '*') {
            cur[j]= prev[j] || cur[j - 1];
        }
        else {
            cur[j] = 0; 
                }
            }
            prev=cur;
        }
        return prev[n];
    }
};