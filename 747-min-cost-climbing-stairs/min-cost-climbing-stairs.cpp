class Solution {
public:
int check(int i, vector<int>& cost){
    if(i==cost.size()) return 0;
    if(i>cost.size()) return 1e5;
return min(check(i+2, cost), check(i+1, cost))+cost[i];
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1);
        dp[n-1]=cost[n-1];

        for(int i=n-2; i>=0; i--){
            dp[i]=cost[i]+ min(dp[i+1], dp[i+2]);
        }

        return min(dp[0], dp[1]);
    }
};