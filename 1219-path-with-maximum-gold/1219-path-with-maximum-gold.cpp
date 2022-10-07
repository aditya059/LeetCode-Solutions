class Solution {
public:
    void dfs(int i, int j, int &ans, int val, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j]) {
            ans = max(ans, val);
            return;
        }
        
        int temp = grid[i][j];
        grid[i][j] = 0;
        
        dfs(i, j - 1, ans, val + temp, grid);
        dfs(i, j + 1, ans, val + temp, grid);
        dfs(i - 1, j, ans, val + temp, grid);
        dfs(i + 1, j, ans, val + temp, grid);
        
        grid[i][j] = temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j])
                    dfs(i, j, ans, 0, grid);
            }
        }
        return ans;
    }
};