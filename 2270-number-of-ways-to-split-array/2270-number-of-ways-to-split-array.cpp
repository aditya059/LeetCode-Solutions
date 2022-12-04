class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long sum = accumulate(nums.begin(), nums.end(), 0L);
        int ans = 0;
        int n = nums.size();
        long currSum = nums[0];
        for(int i = 1; i < n; i++) {
            if(currSum + currSum >= sum)
                ans++;
            currSum += nums[i];
        }
        return ans;
    }
};