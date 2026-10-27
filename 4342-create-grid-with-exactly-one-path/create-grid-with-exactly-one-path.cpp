class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m);

        for(int i=0; i<m; i++){
            grid[i]=".";
        }

        for(int i=1; i<n; i++){
            grid[m-1]+=".";
        }

        for(int i=0; i<m-1; i++){
            for(int j=1; j<n; j++){
                grid[i]+="#";
            }
        }

        return grid;
    }
};