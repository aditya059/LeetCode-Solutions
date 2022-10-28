class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for(int i = 0; i < 32; i++) {
            int power = 1 << i;
            if(n & power)
                powers.push_back(power);
        }
        const int MOD = 1e9 + 7;
        vector<int> ans;
        for(vector<int> query: queries) {
            long prod = 1;
            for(int i = query[0]; i <= query[1]; i++) {
                prod = (prod * powers[i]) % MOD;
            }
            ans.push_back(prod);
        }
        return ans;
    }
};