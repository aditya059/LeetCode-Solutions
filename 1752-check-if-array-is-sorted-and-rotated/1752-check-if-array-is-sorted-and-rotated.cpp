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

OR

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int inversion = nums[0] < nums[n - 1];
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1]) inversion++;
            if(inversion > 1) return false;
        }
        return true;
    }
};
