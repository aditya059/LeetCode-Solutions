class Solution {
public:
    long long solve(vector<int> &nums, int &val) {
        long long sum = 0;
        for(int num: nums) {
            sum += num / val;
        }
        return sum;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = 1e7;
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
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