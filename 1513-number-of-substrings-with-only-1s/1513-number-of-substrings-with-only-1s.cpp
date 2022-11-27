class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7; 
        int n = s.length();
        long count = 0;
        long ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                ans += count * (count + 1) / 2;
                count = 0;
                continue;
            }
            count++;
        }
        ans += count * (count + 1) / 2;
        return ans % MOD;
    }
};