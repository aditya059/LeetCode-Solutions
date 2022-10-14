class Solution {
public:
    static bool comp(vector<int> &f, vector<int> &s) {
        if(f[0] < s[0]) return true;
        if(f[0] == s[0]) return f[1] >= s[1];
        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int x = -1, y = -1, ans = 0;
        for(int i = 0; i < intervals.size(); i++){
            if(x != -1 && y != -1 && intervals[i][0] >= x && intervals[i][1] <= y) 
                continue;
            x = intervals[i][0];
            y = intervals[i][1];
            ans++;
        }
        return ans;
    }
};