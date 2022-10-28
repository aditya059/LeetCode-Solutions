class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for(int i = 0; i < 32; i++) {
            int power = 1 << i;
            if(n & power)
                powers.push_back(power);
        }
        int DP[32][32] = {0};
        const int MOD = 1e9 + 7;
        vector<int> ans;
        for(vector<int> query: queries) {
            long prod = 1;
            if(!DP[query[0]][query[1]]) {
                
                for(int i = query[0]; i <= query[1]; i++) {
                    prod = (prod * powers[i]) % MOD;
                }
            }
            else {
                prod = DP[query[0]][query[1]];
            }
            ans.push_back(prod);
        }
        return ans;
    }
};