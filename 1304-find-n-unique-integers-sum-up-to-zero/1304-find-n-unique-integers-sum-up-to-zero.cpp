class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int sz = n >> 1;
        for(int i = 1; i <= sz; i++) {
            ans.push_back(-i);
            ans.push_back(i);
        }
        if(n % 2)
            ans.push_back(0);
        return ans;
    }
};