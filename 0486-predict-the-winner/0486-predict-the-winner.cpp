// Recursion
class Solution {
public:
    int solve(int i, int j, vector<int> &nums) {
        if(i == j) return nums[i];
        return max(nums[i] - solve(i + 1, j, nums), nums[j] - solve(i, j - 1, nums));
    }
    bool PredictTheWinner(vector<int>& nums) {
        return solve(0, nums.size() - 1, nums) >= 0;
    }
};

// DP
class Solution {
public:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &memo) {
        if(i == j) return nums[i];
        if(memo[i][j] != -1) return memo[i][j];
        return memo[i][j] = max(nums[i] - solve(i + 1, j, nums, memo), nums[j] - solve(i, j - 1, nums, memo));
    }
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), -1));
        return solve(0, nums.size() - 1, nums, memo) >= 0;
    }
};
