class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> freq;
        for(int iter: nums) freq[iter]++;
        vector<pair<int, int>> temp(freq.size()); 
        for(auto iter: freq) {
            temp.push_back({iter.first, iter.second});
        }
        for(auto i = 0; i + k <= temp.size(); i++) {
            if(!temp[i].second) continue;
            for(auto j = 1; j < k; j++) {
                temp[i + j].second -= temp[i].second;
                if(temp[i + j].second < 0 || temp[i + j].first - temp[i].first != j) return false;
            }
            temp[i].second = 0;
        }
        for(pair<int, int> iter: temp) {
            if(iter.second) return false;
        }
        return true;
    }
};