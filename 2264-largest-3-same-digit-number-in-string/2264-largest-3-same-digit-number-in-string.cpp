class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int mx = INT_MIN;
        for(int i = 0; i <= num.size() - 3; i++) {
            string s = num.substr(i, 3);
            if(s[0] == s[1] && s[1] == s[2] && s[0] > mx) {
                ans = s;
                mx = s[0];
            }
        }
        return ans;
    }
};