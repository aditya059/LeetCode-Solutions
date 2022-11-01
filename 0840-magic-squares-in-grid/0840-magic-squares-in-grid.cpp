class Solution {
public:
    bool solve(vector<vector<int>> &grid, int row, int col) {
        int count[10] = {0};
        int rowSum[3] = {0};
        int colSum[3] = {0};
        int ld = 0, rd = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int r = row + i;
                int c = col + j;
                if(grid[r][c] >= 10 || grid[r][c] < 1 || count[grid[r][c]])
                    return false;
                count[grid[r][c]]++;
                rowSum[i] += grid[r][c];
                colSum[j] += grid[r][c];
                if(i == j) ld += grid[r][c];
                if(i + j == 2) rd += grid[r][c];
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