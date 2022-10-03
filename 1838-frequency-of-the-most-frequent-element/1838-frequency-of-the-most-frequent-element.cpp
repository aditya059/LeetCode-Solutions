class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = 0;
        int ans = 0;
        long sum = 0;
        while(end < nums.size()) {
            sum += nums[end];
            while(sum + k < (long)nums[end] * (end - start + 1)) {
                sum -= nums[start];
                start++;
            }
            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};

