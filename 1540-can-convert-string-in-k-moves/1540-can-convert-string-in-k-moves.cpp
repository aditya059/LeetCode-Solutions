class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length() != t.length()) return false;
        int Map[26] = {0};
        for(int i = 0; i < s.length(); i++) {
            Map[(26 + t[i] - s[i]) % 26]++;
        }
        for(int i = 1; i <= 25; i++) {
            if((Map[i] - 1) * 26 + i > k) return false;
        }
        return true;
    }
};