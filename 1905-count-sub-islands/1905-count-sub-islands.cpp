class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool &flag) {
        if(i < 0 || j < 0 || i >= grid1.size() || j >= grid1[0].size() || !grid2[i][j])
            return;
        
        if(grid2[i][j] and !grid1[i][j]) {
            flag = false;
            return;
        }
        
        grid2[i][j] = 0;
            
        dfs(grid1, grid2, i - 1, j, flag);
        dfs(grid1, grid2, i + 1, j, flag);
        dfs(grid1, grid2, i, j - 1, flag);
        dfs(grid1, grid2, i, j + 1, flag);
    
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j]) {
                    bool flag = true;
                    dfs(grid1, grid2, i, j, flag);
                    if(flag)
                        ans++;
                }
            }
        }
        return ans;
    }
};