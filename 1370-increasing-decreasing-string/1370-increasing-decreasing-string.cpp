class Solution {
public:
    string sortString(string s) {
        int freq[26] = {0};
        int n = s.length();
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        string ans = "";
        while(n > 0) {
            for(int i = 0; i < 26; i++) {
                if(freq[i]) {
                    ans += 'a' + i;
                    freq[i]--;
                    n--;
                }
            }
            for(int i = 25; i >= 0; i--) {
                if(freq[i]) {
                    ans += 'a' + i;
                    freq[i]--;
                    n--;
                }
            }
        }
        return ans;
    }
};