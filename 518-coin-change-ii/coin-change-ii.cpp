class Solution {
public:
int check(int ind, int amt, vector<int>& coins, vector<vector<int>>& dp){
    if(amt==0) return 1;
    if(ind==0){
        if(amt%coins[0]==0) return 1;
        return 0;
    }

    if(dp[ind][amt]!=-1) return dp[ind][amt];

    int notake=check(ind-1, amt, coins, dp);
    int take=0;
    if(coins[ind]<=amt){
        take=check(ind, amt-coins[ind], coins, dp);
    }
    return dp[ind][amt]=take+notake;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return check(n-1, amount, coins, dp);
    }
};