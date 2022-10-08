class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0, ans = 0;
        for(char ch: s) {
            if(ch == 'R')
                count++;
            else if(ch == 'L')
                count--;
            if(count == 0)
                ans++;
        }
        return ans;
    }
};