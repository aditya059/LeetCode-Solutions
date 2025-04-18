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

OR

class Solution {
    string solve(string &prevRLE) {
        int len = 1;
        char ch = prevRLE[0];
        string newRLE = "";
        for(int i = 1; i < prevRLE.length(); i++) {
            if(prevRLE[i] == ch) {
                len++;
            } else {
                newRLE += to_string(len) + ch;
                len = 1;
                ch = prevRLE[i];
            }
        }
        return newRLE + to_string(len) + ch;
    }
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i < n; i++) {
            ans = solve(ans);
        }
        return ans;
    }
};
