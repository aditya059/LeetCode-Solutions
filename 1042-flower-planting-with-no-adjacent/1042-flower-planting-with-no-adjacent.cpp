class Solution {
public:
    void dfs(int curr, vector<int> adjList[], vector<bool> &visited, vector<int> &ans) {
        if(visited[curr]) return;
        visited[curr] = true;
        for(int next: adjList[curr]) {
            dfs(next, adjList, visited, ans);
        }
        set<int> Set({1, 2, 3, 4});
        for(int next: adjList[curr]) {
            Set.erase(ans[next]);
        }
        ans[curr] = *Set.begin();
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n);
        vector<int> adjList[n];
        vector<bool> visited(n);
        for(vector<int> edge: paths) {
            adjList[edge[1] - 1].push_back(edge[0] - 1);
            adjList[edge[0] - 1].push_back(edge[1] - 1);
        }
        for(int i = 0; i < n; i++) {
            dfs(i, adjList, visited, ans);
        }
        return ans;
    }
};