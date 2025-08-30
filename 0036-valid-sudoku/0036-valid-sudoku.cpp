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

OR

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int countInRow[9][10] = {0}, countInCol[9][10] = {0}, countInBox[9][10] = {0};
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int digit = board[i][j] - '0', k = (i / 3) * 3 + (j / 3);
                if(countInRow[i][digit] || countInCol[j][digit] || countInBox[k][digit]) {
                    return false;
                }
                countInRow[i][digit]++;
                countInCol[j][digit]++;
                countInBox[k][digit]++;
            }
        }
        return true;
    }
};
