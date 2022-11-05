class Solution {
public:
    
    class TrieNode {
        public:
        string word;
        TrieNode* next[26];
    };
    
    void build(TrieNode *root, vector<string>& words) {
        
        for (string wd: words) {
            TrieNode *curr = root;
            for (char ch: wd) {
                int index = ch - 'a';
                if (curr -> next[index] == NULL) 
                    curr -> next[index] = new TrieNode();
                curr = curr -> next[index];
           }
           curr -> word = wd;
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode *curr, vector<string> &ans) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
        char ch = board[i][j];
        if (ch == '#' || curr -> next[ch - 'a'] == NULL) return;
        curr = curr -> next[ch - 'a'];
        if (curr -> word != "") {   
            ans.push_back(curr -> word);
            curr -> word = "";     
        }

        board[i][j] = '#';
        dfs(board, i - 1, j ,curr, ans); 
        dfs(board, i, j - 1, curr, ans);
        dfs(board, i + 1, j, curr, ans); 
        dfs(board, i, j + 1, curr, ans); 
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        vector<string> ans;
        build(root, words);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs (board, i, j, root, ans);
            }
        }
        return ans;
    }
};




