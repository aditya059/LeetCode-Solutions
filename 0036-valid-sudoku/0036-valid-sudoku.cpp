class Solution {
public:
    const int N = 9;
    bool isValid(vector<vector<char>>& grid, char k, int m, int n) {
        int count = 0;
        for(int i = 0; i < 9; i++) {
            if(grid[m][i] == k)
            count++;
            if(grid[i][n] == k)
            count++;
        }
        m = (m / 3) * 3;
        n = (n / 3) * 3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(grid[m + i][n + j] == k)
                count++;
            }
        }
        if(count == 3)
        return true;
        return false;
    }
    bool solve(vector<vector<char>>& grid) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] != '.') {
                   if(!isValid(grid, grid[i][j], i, j)) {
                        return false;
                   }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};