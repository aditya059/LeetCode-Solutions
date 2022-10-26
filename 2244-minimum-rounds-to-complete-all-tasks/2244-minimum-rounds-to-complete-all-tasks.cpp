class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> Map;
        for(int task: tasks) {
            Map[task]++;
        }
        int ans = 0;
        for(auto iter: Map) {
            if(iter.second == 1) return -1;
            ans += ceil(iter.second / 3.0);
        }
        return ans;
    }
};