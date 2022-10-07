class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int start = 0;
        int end = 0;
        int cost = 0;
        while(end < s.length()) {
            cost += abs(s[end] - t[end]);
            while(cost > maxCost) {
                cost -= abs(s[start] - t[start]);
                start++;
            }
            end++;
            ans = max(ans, end - start);
        }
        return ans;
    }
};