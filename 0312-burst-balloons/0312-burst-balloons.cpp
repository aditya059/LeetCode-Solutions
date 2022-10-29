class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> DP(n + 2, vector<int> (n + 2, 0));
        for(int left = n; left >= 1; left--) {
            for(int right = 1; right <= n; right++) {
                if(left > right) continue;;
                for(int i = left; i <= right; i++) {
                    int coins = nums[left - 1] * nums[i] * nums[right + 1] + DP[left][i - 1] + DP[i + 1][right];
                    DP[left][right] = max(DP[left][right], coins);
                }
            }
        }
        return DP[1][n];
    }
};


/*
class Solution {
public:
    int solve(vector<int> &nums, int left, int right, vector<vector<int>> &memo) {
        if(left > right) return 0;
        if(memo[left][right] != -1) return memo[left][right];
        int maxCoins = INT_MIN;
        for(int i = left; i <= right; i++) {
            int coins = nums[left - 1] * nums[i] * nums[right + 1] + solve(nums, left, i - 1, memo) + solve(nums, i + 1, right, memo);
            maxCoins = max(maxCoins, coins);
        }
        return memo[left][right] = maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> memo(n + 1, vector<int> (n + 1, -1));
        return solve(nums, 1, n, memo);
    }
};
*/