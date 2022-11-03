class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int ans = 0;
        int val[2] = {0};
        val[0] = 1;
        short currSum = 0;
        for(short num: arr) {
            currSum = (currSum + num) % 2;
            ans = (ans + val[1 - currSum]) % MOD;
            val[currSum]++;
        }
        return ans;
    }
};