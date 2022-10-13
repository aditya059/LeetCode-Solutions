class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int num: nums) {
            int count = 0;
            for(int i = num; i > 0; i /= 10) {
                count++;
            }
            ans += 1 - (count & 1);
        }
        return ans;
    }
};