class Solution {
public:
    int precompute(unordered_map<int, int> &memo, int val) {
        if(val == 1) return 0;
        if(memo.find(val) != memo.end())
            return memo[val];
        int ans = 0;
        if(val % 2 == 0)
            ans = 1 + precompute(memo, val >> 1);
        else
            ans = 1 + precompute(memo, val * 3 + 1);
        return memo[val] = ans; 
    }
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> memo;
        vector<pair<int, int>> temp;
        for(int i = lo; i <= hi; i++) {
            int power = precompute(memo, i);
            temp.push_back({power, i});
        }
        sort(temp.begin(), temp.end());
        return temp[k - 1].second;
    }
};