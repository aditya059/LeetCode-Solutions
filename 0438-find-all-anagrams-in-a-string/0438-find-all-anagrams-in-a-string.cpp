class Solution {
public:
    bool check(int freq[]) {
        for(int j = 0; j < 26; j++) {
            if(freq[j] != 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return {};
        int freq[26] = {0};
        int k = p.length();
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            freq[p[i] - 'a']++;
        }
        for(int i = 0; i < k; i++) {
            freq[s[i] - 'a']--;
            if(check(freq)) {
                ans.push_back(0);
            }
        }
        for(int i = k; i < s.length(); i++) {
            freq[s[i] - 'a']--;
            freq[s[i - k] - 'a']++;
            if(check(freq)) {
                ans.push_back(i - k + 1);
            }
        }
        return ans;
    }
};