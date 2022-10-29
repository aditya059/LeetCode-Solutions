class Solution {
public:
    static bool comp(pair<int, int> &A, pair<int, int> &B) {
        return A.first > B.first;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> time(n);
        for(int i = 0; i < n; i++) {
            time[i].first = growTime[i];
            time[i].second = plantTime[i];
        }
        sort(time.begin(), time.end(), comp);
        int ans = 0, currTime = 0;
        for(int i = 0; i < n; i++) {
            currTime += time[i].second;
            ans = max(ans, currTime + time[i].first);
        }
        return ans;
    }
};