class Solution {
public:
    int gcd(int a, int b) {
        if(a % b == 0) return b;
        return gcd(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            mn = min(nums[i], mn);
            mx = max(nums[i], mx);
        }
        return gcd(mx, mn);
    }
};