class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum[2] = {0};
        for(int i = 0; i < n; i++) {
            sum[i % 2] += nums[i];
        }
        for(int i = 0; i < n; i++) {
            sum[i % 2] -= nums[i];
            if(sum[0] == sum[1])
                ans++;
            sum[1 - (i % 2)] += nums[i];
        }
        return ans;
    }
};