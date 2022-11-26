class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        int ans = INT_MIN;
        int maxValue = 0;
        sort(events.begin(), events.end());
        multiset<pair<int, int>> PQ;
        for(int i = 0; i < n; i++) {
            while(!PQ.empty() && PQ.begin() -> first < events[i][0]) {
                maxValue = max(maxValue, PQ.begin() -> second);
                PQ.erase(PQ.begin());
            }
            ans = max(ans, maxValue + events[i][2]);
            PQ.insert({events[i][1], events[i][2]});
        }
        return ans;
    }
};
