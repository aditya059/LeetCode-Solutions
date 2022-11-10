class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        int last = 1;
        for(int i = 1; i <= n; i++) {
            if(!(i & (i - 1)))
                last = i;
            ans[i] = 1 + ans[i - last];
        }
        return ans;
    }
};