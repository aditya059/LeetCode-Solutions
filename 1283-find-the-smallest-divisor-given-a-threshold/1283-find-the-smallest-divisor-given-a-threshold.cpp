class Solution {
public:
    int solve(vector<int> &nums, int &val) {
        int sum = 0;
        for(int num: nums) {
            sum += ceil(1.0 * num / val);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        int low = 1;
        int high = nums[nums.size() - 1];
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(solve(nums, mid) > threshold)
                low = mid + 1;
            else {
                ans = min(ans, mid);
                high = mid - 1;
            }
        }
        return ans;
    }
};