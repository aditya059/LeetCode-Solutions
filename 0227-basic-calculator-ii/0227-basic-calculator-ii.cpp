class Solution {
public:
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
    int calculate(string s) {
        int ans = 0;
        int currNum = 0;
        int prevNum = 0;
        char prevSign = '+';
        for(int i = 0; i < s.length(); i++) {
            if(isDigit(s[i]))
                currNum = currNum * 10 + (s[i] - '0');
            if((s[i] != ' ' && !isDigit(s[i])) || i == s.length() - 1) {
                if(prevSign == '*')
                    prevNum = prevNum * currNum;
                else if(prevSign == '/')
                    prevNum = prevNum / currNum;
                else {
                    ans += prevNum;
                    prevNum = (prevSign == '+')? currNum: -currNum; 
                }
                currNum = 0;
                prevSign = s[i];
            }
        }
        ans += prevNum;
        return ans;
    }
};