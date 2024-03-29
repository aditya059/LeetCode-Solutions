class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long, int>> DP(n);
        int ans = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long diff = (long)nums[i] - (long)nums[j];
                int count = 0;
                if(DP[j].find(diff) != DP[j].end()) {
                    count = DP[j][diff]; 
                }
                DP[i][diff] += count + 1;
                ans += count;
            }
        }
        return ans;
    }
};