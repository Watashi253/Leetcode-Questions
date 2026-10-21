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
        vector<int> prev(n+1, 1e8), curr(n+1, 1e8);
        for(int i=0; i<n; i++){
            prev[i]=triangle[n-1][i];
        }

            for(int i=n-2; i>=0; i--){
              for(int j=i; j>=0; j--){
                curr[j]=triangle[i][j]+min(prev[j], prev[j+1]);
            }
            prev=curr;
            }

        return prev[0];
    }
};