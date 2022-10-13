class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int ans = 0;
        int count = 0;
        while(end < nums.size()) {
            if(!nums[end++])
                count++;
            while(count > k) {
                if(!nums[start++]) 
                    count--;
            }
            ans = max(ans, end - start);
        }
        return ans;
    }
};