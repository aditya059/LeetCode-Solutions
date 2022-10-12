class Solution {
public:
    int solve(vector<int> &nums, int &val) {
        int sum = 0;
        for(int num: nums) {
            sum += ceil(1.0 * num / val);
        }
        return sum;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = INT_MAX;
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(solve(quantities, mid) > n)
                low = mid + 1;
            else {
                ans = min(ans, mid);
                high = mid - 1;
            }
        }
        return ans;
    }
};