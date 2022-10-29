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