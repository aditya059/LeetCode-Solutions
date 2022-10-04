class Solution {
public:
    bool checkString(string s) {
        int i;
        for(i = 0; i < s.length(); i++) {
            if(s[i] == 'b') break;
        }
        for(; i < s.length(); i++) {
            if(s[i] == 'a') return false;
        }
        return true;
    }
};