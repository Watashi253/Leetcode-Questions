class Solution {
public:
int check(int row, int col, vector<vector<int>>& matrix, 
vector<vector<int>> &dp){
if(col<0 || col>=matrix.size())
return 1e9;

if(row==matrix.size()-1){
    return dp[row][col]= matrix[row][col];
}

if(dp[row][col]!=1e9) return dp[row][col];

int d=matrix[row][col]+ check(row+1, col, matrix, dp);
int dl=matrix[row][col]+ check(row+1, col-1, matrix, dp);
int dr=matrix[row][col]+ check(row+1, col+1, matrix, dp);

return dp[row][col]= min(d, min(dl, dr));
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n, vector<int>(n,1e9)); 
        int ans=1e9;
        for(int i=0; i<n; i++){
            ans=min(ans, check(0, i, matrix, dp));
        }
       return ans;
    }
};