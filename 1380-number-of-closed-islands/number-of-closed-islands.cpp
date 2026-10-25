class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        // 1. Eliminate all land connected to the borders
        for (int r = 0; r < rows; ++r) {
            if (grid[r][0] == 0) dfs(grid, r, 0, rows, cols);
            if (grid[r][cols - 1] == 0) dfs(grid, r, cols - 1, rows, cols);
        }
        for (int c = 0; c < cols; ++c) {
            if (grid[0][c] == 0) dfs(grid, 0, c, rows, cols);
            if (grid[rows - 1][c] == 0) dfs(grid, rows - 1, c, rows, cols);
        }
        
        // 2. Count the remaining closed islands
        int closed_islands = 0;
        for (int r = 1; r < rows - 1; ++r) {
            for (int c = 1; c < cols - 1; ++c) {
                if (grid[r][c] == 0) {
                    closed_islands++;
                    dfs(grid, r, c, rows, cols); // Flood fill to sink it
                }
            }
        }
        
        return closed_islands;
    }

private:
    void dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols) {
        // Out of bounds or already water
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 1) {
            return;
        }
        
        // Mark as water
        grid[r][c] = 1;
        
        // Explore all 4 directions
        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r, c + 1, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
    }
};