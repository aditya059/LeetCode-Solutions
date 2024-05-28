class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        for(int start = 0, end = 0; end < s.length(); end++) {
            maxCost -= abs(s[end] - t[end]);
            while(maxCost < 0) {
                maxCost += abs(s[start] - t[start]);
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};
