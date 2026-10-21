class Solution {
public:
int dekho(int i, string &s, vector<int>& dp){
    if(i==s.size()) return 1;

    if(dp[i]!=-1) return dp[i];

    if(s[i]=='0') return dp[i]=0;

    dp[i] = dekho(i + 1, s, dp);

    if (i + 1 < s.size()) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                dp[i] += dekho(i + 2, s, dp);
            }
        }
    
    return dp[i];
}
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1, -1);
        return dekho(0,s, dp);
    }
};