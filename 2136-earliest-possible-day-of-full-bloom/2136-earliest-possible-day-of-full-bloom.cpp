class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) {return growTime[i] > growTime[j];});
        int ans = 0, currTime = 0;
        for(int index: indices) {
            currTime += plantTime[index];
            ans = max(ans, currTime + growTime[index]);
        }
        return ans;
    }
};

/*
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
*/