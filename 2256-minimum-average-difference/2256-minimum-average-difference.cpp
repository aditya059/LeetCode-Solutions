class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0L);
        int n = nums.size();
        int avg;
        int ans = 0;
        int minAvg = INT_MAX;
        long long currSum = nums[0];
        for(int i = 1; i < n; i++) {
            avg = (currSum / i) - (sum - currSum) / (n - i);
            avg = abs(avg);
            currSum += nums[i];
            if(avg < minAvg) {
                ans = i - 1;
                minAvg = avg;
            }
        }
        if(sum / n < minAvg) ans = n - 1;
        return ans;
    }
};