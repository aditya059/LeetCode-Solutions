class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> Map;
        for(string word: words) {
            string temp = word;
            swap(temp[0], temp[1]);
            
            if(Map[temp] != 0) {
                ans += 4;
                Map[temp]--;
                Map[word]--;
            }
            Map[word]++;
        }
        for(auto iter: Map) {
            if(iter.second != 0 && iter.first[0] == iter.first[1]) {
                return ans + 2;
            }
        }
        return ans;
    }
};