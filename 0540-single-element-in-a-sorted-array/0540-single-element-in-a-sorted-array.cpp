class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        while(l < h) {
            int m = l + (h - l) / 2;
            if((m % 2 == 0 && nums[m] == nums[m + 1]) || (m % 2 == 1 && nums[m] == nums[m - 1]))
                l = m + 1;
            else
                h = m;
        }
        return nums[l];
    }
};


/*
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int l = 0;
        int h = nums.size() - 1;
        while(l <= h) {
            int m = l + (h - l) / 2;
            if(m == 0 || nums[m] != nums[m - 1] && nums[m] != nums[m + 1]) return nums[m];
            if((m - l + 1) % 2) {
                if(nums[m] == nums[m - 1]) h = m - 2;
                else l = m + 2;
            }
            else {
                if(nums[m] != nums[m - 1]) h = m - 1;
                else l = m + 1;
            }
        }
        return nums[l + 1];
    }
};
*/