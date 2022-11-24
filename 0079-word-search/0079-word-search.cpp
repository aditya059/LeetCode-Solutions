class Solution {
public:
    void solve(vector<vector<char>>& board, string &word, int index, bool &ans, int i, int j) {
        if(index == word.length()) {
            ans = true;
            return;
        }
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        if(word[index] == board[i][j]) {
            board[i][j] = 0;
            solve(board, word, index + 1, ans, i - 1, j);
            solve(board, word, index + 1, ans, i, j - 1);
            solve(board, word, index + 1, ans, i + 1, j);
            solve(board, word, index + 1, ans, i, j + 1);
            board[i][j] = word[index];
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(word[0] == board[i][j])
                    solve(board, word, 0, ans, i, j);
            }
        }
        return ans;
    }
};