class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, bool &flag) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            flag = false;
            return;
        }
        if(visited[i][j] || grid[i][j]) return; 
        visited[i][j] = true;
        grid[i][j] = 1;
        dfs(i - 1, j, grid, visited, flag);
        dfs(i + 1, j, grid, visited, flag);
        dfs(i, j - 1, grid, visited, flag);
        dfs(i, j + 1, grid, visited, flag);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!grid[i][j]) {
                    bool isIsland = true;
                    dfs(i, j, grid, visited, isIsland);
                    if(isIsland) {
                        cout << i << " " << j << endl;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};