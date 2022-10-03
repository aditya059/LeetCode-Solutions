class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> Map;
        for(int i = 0; i < nums.size(); i++) {
            if(Map.find(target - nums[i]) != Map.end()) {
                ans.push_back(i);
                ans.push_back(Map[target - nums[i]]);
                return ans;
            }
            Map[nums[i]] = i;
        }
        return ans;
    }
};