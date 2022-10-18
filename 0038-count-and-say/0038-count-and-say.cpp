class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string s = countAndSay(n - 1);
        if(s.length() == 1)
            return "1" + s;
        string r = "";
        int count = 1, i;
        for(i = 1; i < s.length(); i++) {
            if(s[i] == s[i - 1])
                count++;
            else {
                r += to_string(count) + s[i - 1];
                count = 1;
            }
        }
        r += to_string(count) + s[i - 1];
        return r;
    }
};