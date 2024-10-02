class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(!n) return {};
        vector<int> index(n);
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int &A, int &B) {
            return arr[A] < arr[B];
        });
        vector<int> ans(n);
        ans[index[0]] = 1;
        for(int i = 1; i < n; i++) {
            ans[index[i]] = ans[index[i - 1]] + (arr[index[i]] != arr[index[i - 1]]);
        }
        return ans;
    }
};
