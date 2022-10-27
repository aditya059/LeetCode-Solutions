class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        map<pair<int, int>, int> count;
        vector<pair<int, int>> list1;
        vector<pair<int, int>> list2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j]) list1.push_back({i, j});
                if(img2[i][j]) list2.push_back({i, j});
            }
        }
        int ans = 0;
        for(int i = 0; i < list1.size(); i++) {
            for(int j = 0; j < list2.size(); j++) {
                count[{list1[i].first - list2[j].first, list1[i].second - list2[j].second}]++;
            }
        }
        for(auto iter: count) {
            ans = max(ans, iter.second);
        }
        return ans;
    }
};