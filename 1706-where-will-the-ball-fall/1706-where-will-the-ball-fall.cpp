class Solution {
public:
    int dfs(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &memo) {
        // Base Case
        if(row == grid.size()) return col;
        
        if(memo[row][col] != -1) return memo[row][col];
        
        int nextcol = col + grid[row][col];
        
        if(nextcol == -1 || nextcol == grid[0].size() || grid[row][col] != grid[row][nextcol])
            return -1;
        
        return memo[row][col] = dfs(grid, row + 1, nextcol, memo);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
        for(int col = 0; col < grid[0].size(); col++) {
            ans[col] = dfs(grid, 0, col, memo);
        }
        return ans;
    }
};

/*
class Solution {
public:
    int dfs(vector<vector<int>> &grid, int row, int col) {
        // Base Case
        if(row == grid.size()) return col;
        
        int nextcol = col + grid[row][col];
        
        if(nextcol == -1 || nextcol == grid[0].size() || grid[row][col] != grid[row][nextcol])
            return -1;
        
        return dfs(grid, row + 1, nextcol);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for(int col = 0; col < grid[0].size(); col++) {
            ans[col] = dfs(grid, 0, col);
        }
        return ans;
    }
};
*/