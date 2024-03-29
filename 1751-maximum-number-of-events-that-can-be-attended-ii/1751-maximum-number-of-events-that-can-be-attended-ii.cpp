class Solution {
public:
    int binary_search(vector<vector<int>> &intervals, int l, int h, int target) {
        int ans = h + 1;
        while(l <= h) {
            int m = l + (h - l) / 2;
            if(target > intervals[m][0]) {
                l = m + 1;
            } else {
                ans = min(ans, m);
                h = m - 1;
            }
        }
        return ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> DP(2, vector<int>(n + 1));
        vector<int> index(n);
        for(int i = n - 1; i >= 0; i--) {
            DP[0][i] = max(DP[0][i + 1], events[i][2]);
            index[i] = binary_search(events, i + 1, n - 1, events[i][1] + 1);
        }
        for(int i = 1; i < k; i++) {
            for(int j = n - 1; j >= 0; j--) {
                DP[i & 1][j] = max(DP[i & 1][j + 1], events[j][2] + DP[(i - 1) & 1][index[j]]);
            }
        }
        return DP[(k - 1) & 1][0];
    }
};

/*
class Solution {
public:
    int binary_search(vector<vector<int>> &intervals, int l, int h, int target) {
        int ans = h + 1;
        while(l <= h) {
            int m = l + (h - l) / 2;
            if(target > intervals[m][0]) {
                l = m + 1;
            } else {
                ans = min(ans, m);
                h = m - 1;
            }
        }
        return ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> DP(2, vector<int>(n + 1));
        for(int i = n - 1; i >= 0; i--)
            DP[0][i] = max(DP[0][i + 1], events[i][2]);
        for(int j = 1; j < k; j++) {
            for(int i = n - 1; i >= 0; i--) {
                int index = binary_search(events, i + 1, n - 1, events[i][1] + 1);
                DP[j % 2][i] = max(DP[j % 2][i + 1], events[i][2] + DP[(j - 1) % 2][index]);
            }
        }
        return DP[(k - 1) % 2][0];
    }
};
*/