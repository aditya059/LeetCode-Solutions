class Solution {
public:
    long long solve(vector<int> &nums, long long &val) {
        long long sum = 0;
        for(int num: nums) {
            sum += num / val;
        }
        return sum;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1;
        long long high = 1e12;
        long long ans = 0;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(solve(candies, mid) >= k) {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};