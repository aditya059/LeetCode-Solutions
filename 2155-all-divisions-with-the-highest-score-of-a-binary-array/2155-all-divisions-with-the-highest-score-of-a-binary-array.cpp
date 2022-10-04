class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int ones = 0;
        for(int i = 0; i < nums.size(); i++) {
            ones += nums[i];
        }
        int zeroes = 0;
        vector<int> ans;
        int maxScore = INT_MIN;
        for(int i = 0; i <= nums.size(); i++) {
            int score = zeroes + ones;
            if(score > maxScore) {
                maxScore = score;
                ans.clear();
                ans.push_back(i);
            }
            else if(score == maxScore) 
                ans.push_back(i);
            if(i < nums.size()) {
                zeroes += 1 - nums[i];
                ones -= nums[i];
            }
        }
        return ans;
    }
};