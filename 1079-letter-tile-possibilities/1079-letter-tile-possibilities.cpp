class Solution {
public:
    void dfs(int count[], int &ans) {
        for(int i = 0; i < 26; i++) {
            if(count[i] > 0) {
                ans++;
                count[i]--;
                dfs(count, ans);
                count[i]++;
            } 
        }
    }
    int numTilePossibilities(string tiles) {
        int count[26] = {0};
        int ans = 0;
        for(char ch: tiles) count[ch - 'A']++;
        dfs(count, ans);
        return ans;
    }
};