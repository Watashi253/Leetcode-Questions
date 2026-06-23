class Solution {
public:
    int uniquePaths(int m, int n) { 
        vector<int> prev(n,0);
        for(int i=0; i<m; i++){
            vector<int> temp(n,1);
            for(int j=0; j<n; j++){
                if(j-1>=0)temp[j] = prev[j]+temp[j-1];
            }
            prev=temp;
        }
        return prev[n-1];
        }
};