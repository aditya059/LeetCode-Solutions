class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7; 
        int n = s.length();
        long count = 1;
        long ans = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1])
                count++;
            else {
                ans = (ans + count * (count + 1) / 2) % MOD;
                count = 1;
            }
        }
        ans += count * (count + 1) / 2;
        return ans % MOD;
    }
};