class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adjList[n];
        vector<vector<int>> Map(n, vector<int>(n));
        for(vector<int> edge: roads) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            Map[edge[0]][edge[1]] = 1;
            Map[edge[1]][edge[0]] = 1;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                ans = max(ans, (int)adjList[i].size() + (int)adjList[j].size() - Map[i][j]);
            }
        }
        return ans;
    }
};