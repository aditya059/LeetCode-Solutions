class Solution {
public:
    static bool comp(vector<int> &f, vector<int> &s) {
        if(f[0] < s[0]) return true;
        if(f[0] == s[0]) return f[1] >= s[1];
        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size(); i++){
            //cout << intervals[i][0] << " " << intervals[i][1] << endl;
            if(!ans.empty() && intervals[i][0] >= ans.back()[0] && intervals[i][1] <= ans.back()[1]) 
                continue;
            ans.push_back(intervals[i]);
        }
        return ans.size();
    }
};