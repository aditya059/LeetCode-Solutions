class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int maxCount = 0;
        int start = 0;
        int end = 0;
        int ans = 0;
        while(end < s.length()) {
            count[s[end] - 'A']++;
            if(maxCount < count[s[end] - 'A'])
                maxCount = count[s[end] - 'A'];
            while(end - start + 1 - maxCount > k) {
                count[s[start] - 'A']--;
                start++;
                for(int i = 0; i < 26; i++) {
                    if(maxCount < count[s[end] - 'A'])
                        maxCount = count[s[end] - 'A'];
                }
            }
            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};