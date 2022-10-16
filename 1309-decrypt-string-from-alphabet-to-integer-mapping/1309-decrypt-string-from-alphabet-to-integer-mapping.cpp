class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        char ch;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == '#') {
                ch = 'a' - 1 + stoi(s.substr(i - 2, 2));
                i -= 2;
            }
            else {
                ch = 'a' + (s[i] - '0') - 1;
            }
            ans = ch + ans;
        }
        return ans;
    }
};