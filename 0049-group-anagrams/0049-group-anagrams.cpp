class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> Map;
        for(int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            Map[s].push_back(strs[i]);
        }
        for(auto iter: Map) {
            ans.push_back(iter.second);
        }
        return ans;
    }
};