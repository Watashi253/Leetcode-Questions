class Solution {
public: 
    int minimumTotal(vector<vector<int>>& triangle) {
         int n=triangle.size();
         int ans=INT_MAX;
         vector<vector<int>> dp = triangle;
        
         for(int i=n-2; i>=0; i--){
            for(int j=triangle[i].size()-1; j>=0; j--){
                int d=1e9, dr=1e9;
                if(i+1<n) d= triangle[i][j]+dp[i+1][j];
                if(i+1<n) dr= triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(d, dr);
            }
         }

         return dp[0][0];
    }
};