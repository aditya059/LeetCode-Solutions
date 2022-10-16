class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n) return -1;
        vector<int> DP(n + 1, INT_MAX / 100);
        DP[n] = 0;
        for(int i = 1; i <= d; i++) {
            for(int j = 0; j <= n - i; j++) {
                int temp = INT_MAX / 100;
                int p = 0;
                for(int k = j; k <= n - i; k++) {
                    p = max(p, jobDifficulty[k]);
                    temp = min(temp, p + DP[k + 1]);
                }
                DP[j] = temp;
            }
        }
        return DP[0];
    }
};
