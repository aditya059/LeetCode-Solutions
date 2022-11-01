class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rowSum(m + 1, vector<int>(n + 1)), colSum(rowSum);
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                rowSum[i][j] = rowSum[i][j - 1] + grid[i - 1][j - 1];
                colSum[i][j] = colSum[i - 1][j] + grid[i - 1][j - 1];
            }
        }
        int ans = 1;
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = min(m - i, n - j); k >= 0; k--) {
                    int sum = rowSum[i][j + k] - rowSum[i][j - 1], ldiag = 0, rdiag = 0; 
                    bool flag = true;
                    for(int l = 0; l <= k; l++) {
                        if(sum != rowSum[i + l][j + k] - rowSum[i + l][j - 1] || sum != colSum[i + k][j + l] - colSum[i - 1][j + l]) {
                            flag = false;
                            break;
                        }
                        ldiag += grid[i + l - 1][j + l - 1];
                        rdiag += grid[i + l - 1][j - 1 + k - l];
                    }
                    if(flag && ldiag == sum && rdiag == sum) 
                        ans = max(ans, k + 1);
                }
            }
        }
        
        return ans;
    }
};