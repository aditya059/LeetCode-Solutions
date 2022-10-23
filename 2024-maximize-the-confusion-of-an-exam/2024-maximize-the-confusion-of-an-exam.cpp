class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        unordered_map<int, int> count;
        int maxCount = 0;
        int start = 0;
        int end = 0;
        int ans = 0;
        while(end < s.length()) {
            count[s[end]]++;
            if(maxCount < count[s[end]])
                maxCount = count[s[end]];
            while(end - start + 1 - maxCount > k) {
                count[s[start]]--;
                start++;
                maxCount = max(count['T'], count['F']);
            }
            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};