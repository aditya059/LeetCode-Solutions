class Solution {
public:
    int solve(vector<int>& jobDifficulty, int d, vector<vector<int>> &DP, int index) {
        if(d == 1) {
            int mx = 0;
            for(int i = index; i < jobDifficulty.size(); i++) 
                mx = max(mx, jobDifficulty[i]);
            return mx;
        }
        if(DP[d][index] != -1) return DP[d][index];
        int mx = 0;
        int ans = INT_MAX;
        for(int i = index; i < jobDifficulty.size() - d + 1; i++) {
            mx = max(mx, jobDifficulty[i]);
            ans = min(ans, mx + solve(jobDifficulty, d - 1, DP, i + 1));
        }
        return DP[d][index] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n) return -1;
        vector<vector<int>> DP(d + 1, vector<int>(n, -1));
        return solve(jobDifficulty, d, DP, 0);
    }
};
