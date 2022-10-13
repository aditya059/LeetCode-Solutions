class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0 && k) {
                k--;
                nums[i] = -nums[i];
            }
            else {
                break;
            }
        }
        k %= 2;
        int sum = 0;
        int mn = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mn = min(mn, nums[i]);
        }
        if(k)
            return sum - 2 * mn;
        return sum;
    }
};