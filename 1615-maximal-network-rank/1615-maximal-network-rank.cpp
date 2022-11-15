class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        vector<vector<int>> Map(n, vector<int>(n));
        for(vector<int> edge: roads) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            Map[edge[0]][edge[1]] = 1;
            Map[edge[1]][edge[0]] = 1;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                ans = max(ans, degree[i] + degree[j] - Map[i][j]);
            }
        }
        return ans;
    }
};