class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int currSum = 0, ans = 0;
        int Map[50001] = {0};
        Map[0]++;
        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i] % 2;
            if(currSum >= k)
                ans += Map[currSum - k];
            Map[currSum]++;
        }
        return ans;
    }
};