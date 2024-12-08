class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        int ans = 0;
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

OR

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size(), maxVal = 0, ans = 0;
        auto comp = [&](int &i, int &j) {
            return events[i][1] > events[j][1];
        };
        priority_queue<int, vector<int>, decltype(comp)> PQ(comp);
        for(int i = 0; i < n; i++) {
            while(!PQ.empty() && events[PQ.top()][1] < events[i][0]) {
                maxVal = max(maxVal, events[PQ.top()][2]);
                PQ.pop();
            }
            ans = max(ans, maxVal + events[i][2]);
            PQ.push(i);
        }
        return ans;
    }
};
