class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int MOD = 1e9 + 7;
        int n = deliciousness.size();
        sort(deliciousness.begin(), deliciousness.end());
        int ans = 0;
        unordered_map<int, int> Map;
        for(int num: deliciousness) {
            for(int j = 1; j <= num + num; j *= 2) {
                if(Map.find(j - num) != Map.end()) {
                    ans = (ans + Map[j - num]) % MOD;
                }
            }
            Map[num]++;
        }
        return ans % MOD;
    }
};