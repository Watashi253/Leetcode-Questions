class Solution {
public: 
    int minimumTotal(vector<vector<int>>& triangle) {
         int n=triangle.size();
         int ans=INT_MAX;
         vector<vector<int>> dp = triangle;;
         
         dp[0][0]=triangle[0][0];

         for(int i=1; i<n; i++){
            for(int j=0; j<triangle[i].size(); j++){
                int up=1e9, upl=1e9;
                if(i-1>=0 && j<triangle[i-1].size())
                up= triangle[i][j]+dp[i-1][j];
                if(i-1>=0 && j-1>=0)
                upl= triangle[i][j]+dp[i-1][j-1];
                dp[i][j]=min(up, upl);
            }
         }
         for(int i=0; i<triangle[n-1].size(); i++){
           ans=min(ans,dp[n-1][i]);
         }
         return ans;
    }
};