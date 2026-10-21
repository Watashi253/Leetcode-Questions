class Solution {
public:
int socho(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    if(i==triangle.size()-1) return triangle[i][j];
    if(i>triangle.size()-1 || j>=triangle[i].size()) return 1e8;

    if(dp[i][j]!=-1) return dp[i][j];

    return dp[i][j]=triangle[i][j] + 
    min(socho(i+1, j, triangle, dp), socho(i+1, j+1, triangle, dp));
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 1e8));
        dp[0][0]=triangle[0][0];

        for(int i=1; i<n; i++){
            for(int j=0; j<triangle[i].size(); j++){
                if(j==0)
                dp[i][j]=triangle[i][j]+dp[i-1][j];
                else
             dp[i][j]=triangle[i][j]+min(dp[i-1][j], dp[i-1][j-1]);
            }
        }

        int ans=1e8;
        for(int i=0; i<triangle[n-1].size(); i++){
            ans=min(ans, dp[n-1][i]);
        }
        return ans;
    }
};