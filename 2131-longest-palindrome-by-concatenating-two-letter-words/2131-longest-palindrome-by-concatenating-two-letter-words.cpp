class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        int Map[26][26] = {0};
        for(string word: words) {
            if(Map[word[1] - 'a'][word[0] - 'a'] != 0) {
                ans += 4;
                Map[word[1] - 'a'][word[0] - 'a']--;
                Map[word[0] - 'a'][word[1] - 'a']--;
            }
            Map[word[0] - 'a'][word[1] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(Map[i][i]) return ans + 2;
        }
        return ans;
    }
};