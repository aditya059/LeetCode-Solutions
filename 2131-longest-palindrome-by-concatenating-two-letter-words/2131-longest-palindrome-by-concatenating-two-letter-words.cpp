class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        int Map[26][26] = {0};
        for(string word: words) {
            short i = word[0] - 'a';
            short j = word[1] - 'a';
            if(Map[j][i] != 0) {
                ans += 4;
                Map[j][i]--;
                Map[i][j]--;
            }
            Map[i][j]++;
        }
        for(int i = 0; i < 26; i++) {
            if(Map[i][i]) return ans + 2;
        }
        return ans;
    }
};