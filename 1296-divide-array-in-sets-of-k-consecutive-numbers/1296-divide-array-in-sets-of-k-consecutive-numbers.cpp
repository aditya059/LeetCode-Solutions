class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> temp; 
        for(int num: nums) {
            if(temp.empty() || temp.back().first != num)
                temp.push_back({num, 1});
            else
                temp.back().second++;
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