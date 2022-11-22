class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        vector<int> DP(n + 1, INT_MAX); 
        DP[0] = 0;
        for(int i = 1; i <= m; i++) {
            int temp = i * i;
            for(int j = 1; j <= n; j++) {
                if(j >= temp)
                    DP[j] = min(DP[j], 1 + DP[j - temp]);
            }
        }
        return DP[n];
    }
};