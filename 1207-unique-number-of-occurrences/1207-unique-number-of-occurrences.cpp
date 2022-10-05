class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int iter: arr) {
            freq[iter]++;
        }
        unordered_set<int> Map;
        for(auto iter: freq) {
            if(Map.find(iter.second) != Map.end())
                return false;
            Map.insert(iter.second);
        }
        return true;
    }
};