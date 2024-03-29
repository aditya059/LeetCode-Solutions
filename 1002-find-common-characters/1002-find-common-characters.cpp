class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> freq1(26, INT_MAX);
        vector<int> freq2(26);
        for(int i = 0; i < words.size(); i++) {
            fill(freq2.begin(), freq2.end(), 0);
            for(int j = 0; j < words[i].size(); j++) {
                freq2[words[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; j++) {
                freq1[j] = min(freq1[j], freq2[j]);
            }
        }
        string s = "";
        for(int i = 0; i < 26; i++) {
            if(freq1[i] == INT_MAX) continue;
            while(freq1[i]--) {
                char ch = 'a' + i;
                s += ch;
                ans.push_back(s);
                s = "";
            }
        }
        return ans;
    }
};