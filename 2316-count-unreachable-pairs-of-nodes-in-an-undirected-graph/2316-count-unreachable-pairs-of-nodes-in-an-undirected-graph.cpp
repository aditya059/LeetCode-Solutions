class Solution {
public:
    void dfs(int curr, vector<int> adjList[], vector<bool> &visited, long long &len) {
        if(visited[curr]) return;
        visited[curr] = true;
        len++;
        for(int next: adjList[curr]) {
            dfs(next, adjList, visited, len);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        vector<int> adjList[n];
        vector<bool> visited(n);
        for(vector<int> edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                long long len = 0;
                dfs(i, adjList, visited, len);
                ans += len * (n - len);
            }
        }
        return ans / 2;
    }
};