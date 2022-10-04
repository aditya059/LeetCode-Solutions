class Solution {
public:
    bool check(vector<int>& nums) {
        int i;
        for(i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i - 1]) break;
        }
        if(i == nums.size()) return true;
        i++;
        for(;i < nums.size(); i++) {
            if(nums[i] < nums[i - 1]) break;
        }
        return nums.size() <= i && nums[nums.size() - 1] <= nums[0];
    }
};