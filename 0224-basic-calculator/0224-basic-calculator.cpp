class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int sign = 1;
        int currNum = 0;
        stack<bool> symbol;   // (true for '+', false for '-')
        symbol.push(true);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') 
                continue;
            else if(s[i] >= '0' && s[i] <= '9')
                currNum = currNum * 10 + (s[i] - '0');
            else if(s[i] == '(') {
                symbol.push(sign == 1);
            }
            else if(s[i] == ')') {
                symbol.pop();
            }
            else { // "+" or "-"
                ans += currNum * sign;
                sign = (symbol.top()? 1: -1) * (s[i] == '+'? 1: -1);
                currNum = 0;
            }
        }
        if(currNum) ans += currNum * sign;
        return ans;
    }
};