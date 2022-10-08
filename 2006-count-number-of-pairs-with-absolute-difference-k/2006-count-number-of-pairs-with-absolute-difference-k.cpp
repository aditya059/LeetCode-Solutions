class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        map<int, int> Map;
        for(int num: nums)
            Map[num]++;
        int ans = 0;
        for(auto iter: Map) {
            if(Map.find(iter.first - k) != Map.end())
                ans += iter.second * Map[iter.first - k];
        }
        return ans;
    }
};