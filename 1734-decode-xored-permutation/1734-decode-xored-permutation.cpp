class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int allxorred = 0;
        for(int i = 1; i <= n; i++) {
            allxorred = allxorred xor i; 
        }
        vector<int> ans(n);
        ans[0] = allxorred;
        
        for(int i = 1; i < encoded.size(); i += 2) {
            ans[0] = ans[0] xor encoded[i];
        }
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] xor encoded[i - 1];
        }
        return ans;
    }
};