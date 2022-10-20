class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp(nums);
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            ans.push_back(upper_bound(nums.begin(), nums.end(), temp[i] - 1) - nums.begin());
        }
        return ans;
    }
};