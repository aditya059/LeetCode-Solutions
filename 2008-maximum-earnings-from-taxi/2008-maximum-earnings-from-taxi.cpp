class Solution {
private:
    static bool comp(vector<int> &A, vector<int> &B) {
        return A[0] < B[0];
    }
public:
    int binary_search(vector<vector<int>> &rides, int l, int h, int target) {
        int ans = h + 1;
        while(l <= h) {
            int m = l + (h - l) / 2;
            if(target > rides[m][0]) {
                l = m + 1;
            } else {
                ans = min(ans, m);
                h = m - 1;
            }
        }
        return ans;
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), comp);
        vector<long long> DP(rides.size() + 1, 0);
        for(int i = rides.size() - 1; i >= 0; i--) {
            int index = binary_search(rides, i + 1, rides.size() - 1, rides[i][1]);
            DP[i] = max(DP[i + 1], rides[i][1] - rides[i][0] + rides[i][2] + DP[index]);
        }
        return DP[0];
    }
};
