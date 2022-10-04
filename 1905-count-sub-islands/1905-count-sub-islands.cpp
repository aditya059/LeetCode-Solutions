class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int &val) {
        if(i < 0 || j < 0 || i >= grid1.size() || j >= grid1[0].size() || !grid2[i][j])
            return;
        
        if(grid2[i][j] and !grid1[i][j]) {
            val = 1;
            return;
        }
        
        grid2[i][j] = 0;
            
        dfs(grid1, grid2, i - 1, j, val);
        dfs(grid1, grid2, i + 1, j, val);
        dfs(grid1, grid2, i, j - 1, val);
        dfs(grid1, grid2, i, j + 1, val);
    
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j]) {
                    int val = 0;
                    dfs(grid1, grid2, i, j, val);
                    ans += 1 - val;
                }
            }
        }
        return ans;
    }
};