class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int freq[26] = {0};
        for(string word: words) {
            for(char ch: word) {
                freq[ch - 'a']++;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(freq[i] % words.size() != 0) return false;
        }
        return true;
    }
};