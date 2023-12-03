class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 1; i < n; i++) {
            int diffX = abs(points[i][0] - points[i - 1][0]);
            int diffY = abs(points[i][1] - points[i - 1][1]);
            ans += min(diffX, diffY) + abs(diffX - diffY);
        }
        return ans;
    }
};


OR


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 1; i < n; i++) {
            int diffX = abs(points[i][0] - points[i - 1][0]);
            int diffY = abs(points[i][1] - points[i - 1][1]);
            ans += max(diffX, diffY);
        }
        return ans;
    }
};
