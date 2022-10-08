class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for(vector<int> index: indices) {
            row[index[0]]++;
            col[index[1]]++;
        }
        int even1 = 0, even2 = 0;
        for(int val: row) {
            if(val % 2 == 0)
                even1++;
        }
        for(int val: col) {
            if(val % 2 == 0)
                even2++;
        }
        return (m - even1) * (even2) + (n - even2) * even1;
    }
};