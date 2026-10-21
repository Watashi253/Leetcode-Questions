class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> hash(n, vector<int>(m,0));
        int c=0;  
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                hash[i][j]=grid[i][j];
                if(i>0)hash[i][j]+=hash[i-1][j];
                if(j>0)hash[i][j]+=hash[i][j-1];
                if(i>0 && j>0)hash[i][j]-=hash[i-1][j-1];
                if(hash[i][j]<=k)c++;
            }
        }     

        return c;
    }
};