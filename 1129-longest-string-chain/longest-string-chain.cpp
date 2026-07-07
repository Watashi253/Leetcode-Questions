class Solution {
public:
static bool comp(string &s1, string &s2){
    return s1.size()<s2.size();
}
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), comp);
        
        unordered_map<string, int> dp;
        int maxi=1;

        for(auto word: words){
            dp[word]=1;
            for(int j=0; j<word.size(); j++){
                string pred=word.substr(0,j)+word.substr(j+1);
                if(dp.find(pred) != dp.end()){
                    dp[word] = max(dp[word], 1 + dp[pred]);
                }
            }
            maxi=max(dp[word], maxi);
        }
        return maxi;
    }
};