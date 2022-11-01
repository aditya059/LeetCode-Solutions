class Solution {
public:
    bool solve(vector<vector<int>> &grid, int r, int c) {
        int count[16] = {0};
        int rowSum[3] = {0};
        int colSum[3] = {0};
        int ld = 0, rd = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(count[grid[r + i][c + j]] || grid[r + i][c + j] >= 10 || grid[r + i][c + j] < 1)
                    return false;
                count[grid[r + i][c + j]]++;
                rowSum[i] += grid[r + i][c + j];
                colSum[j] += grid[r + i][c + j];
                if(i == j) ld += grid[r + i][c + j];
                if(i + j == 2) rd += grid[r + i][c + j];
            }
        }
        return rowSum[0] == 15 && rowSum[1] == 15 && rowSum[2] == 15 && colSum[0] == 15 && colSum[1] == 15 && colSum[2] == 15 && ld == 15 && rd == 15;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                if(solve(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};