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
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()) return false;
        int freq[26] = {0};
        for(int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }
        int k = s1.length();
        for(int i = 0; i < k; i++) {
            freq[s2[i] - 'a']--;
            if(check(freq)) return true;
        }
        for(int i = k; i < s2.length(); i++) {
            freq[s2[i] - 'a']--;
            freq[s2[i - k] - 'a']++;
            if(check(freq)) return true;
        }
        return false;
    }
};