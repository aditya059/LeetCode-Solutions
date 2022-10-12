class Solution {
public:
    long long solve(vector<int> &nums, long long &val) {
        long long sum = 0;
        for(int num: nums) {
            sum += val / num;
        }
        return sum;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1e14;
        long long ans = high;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(solve(time, mid) < totalTrips)
                low = mid + 1;
            else {
                ans = min(ans, mid);
                high = mid - 1;
            }
        }
        return ans;
    }
};