class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = n - 1;
        int count = 0;
        while(i < m) {
            while(j >= 0 && grid[i][j] < 0)
                j--;
            count += n - j - 1;
            i++;
        }
        return count;
    }
};