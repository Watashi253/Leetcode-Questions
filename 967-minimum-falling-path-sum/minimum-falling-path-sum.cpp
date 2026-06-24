class Solution {
public:
int check(int row, int col, vector<vector<int>>& matrix, 
vector<vector<int>> &dp){
if(col<0 || col>=matrix.size())
return 1e9;

if(row==0){
    return dp[row][col]= matrix[row][col];
}

if(dp[row][col]!=1e9) return dp[row][col];

int u=matrix[row][col]+ check(row-1, col, matrix, dp);
int ur=matrix[row][col]+ check(row-1, col+1, matrix, dp);
int ul=matrix[row][col]+ check(row-1, col-1, matrix, dp);

return dp[row][col]= min(u, min(ul, ur));
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n, vector<int>(n,1e9)); 
        int ans=1e9;
        for(int i=0; i<n; i++){
            ans=min(ans, check(n-1, i, matrix, dp));
        }
       return ans;
    }
};