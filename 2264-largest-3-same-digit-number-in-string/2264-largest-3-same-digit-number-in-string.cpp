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


OR


class Solution {
public:
    string largestGoodInteger(string num) {
        int mx = INT_MIN, j = -1;
        for(int i = 2; i < num.size(); i++) {
            if(num[i - 2] == num[i - 1] && num[i - 1] == num[i] && num[i] > mx) {
                j = i;
                mx = num[i];
            }
        }
        return j == -1? "": num.substr(j - 2, 3);
    }
};
