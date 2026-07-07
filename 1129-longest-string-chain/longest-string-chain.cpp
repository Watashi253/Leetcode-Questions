class Solution {
public:
static bool comp(string &s1, string &s2){
    return s1.size()<s2.size();
}
bool check(string &s1, string &s2){
    if(s1.size()-s2.size()!=1) return false;
    int i=0, j=0;
    while(i<s1.size()){
        if(j < s2.size() && s1[i]==s2[j]){
            i++, j++;
        }
        else i++;
    }
    if(i==s1.size() && j==s2.size()) return true;
    return false;
}
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), comp);
        
        vector<int> dp(n, 1);
        int maxi=1;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(check(words[i], words[j])){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};