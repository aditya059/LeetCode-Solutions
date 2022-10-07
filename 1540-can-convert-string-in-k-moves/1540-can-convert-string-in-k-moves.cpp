class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length() != t.length()) return false;
        int Map[26] = {0};
        for(int i = 0; i < s.length(); i++) {
            int val = (26 + t[i] - s[i]) % 26;
            if(!val) continue;
            if(val + 26 * Map[val] > k) return false;
            Map[val]++;
        }
        return true;
    }
};