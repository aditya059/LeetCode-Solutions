class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size()));
        int i = 0;
        int j = 0;
        while(i < rowSum.size() && j < colSum.size()) {
            ans[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];
            i += (rowSum[i] == 0);
            j += (colSum[j] == 0);
        }
        return ans;
    }
};
/*
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size()));
        for(int i = 0; i < rowSum.size(); i++) {
            for(int j = 0; j < colSum.size(); j++) {
                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }
        return ans;
    }
};
*/