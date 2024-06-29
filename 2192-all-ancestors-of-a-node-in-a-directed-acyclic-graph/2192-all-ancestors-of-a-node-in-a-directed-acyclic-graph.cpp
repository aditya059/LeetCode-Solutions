class Solution {
public:
    void dfs(int curr, int &val, vector<int> adjList[], vector<bool> &visited, vector<vector<int>> &ans) {
        if(visited[curr]) return;
        visited[curr] = true;
        for(int next: adjList[curr]) {
            if(!visited[next]) {
                ans[val].push_back(next);
                dfs(next, val, adjList, visited, ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<int> adjList[n];
        for(vector<int> edge: edges) {
            adjList[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++) {
            vector<bool> visited(n);
            dfs(i, i, adjList, visited, ans);
        }
        for(int i = 0; i < n; i++) {
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};

OR

class Solution {
public:
	void dfs(int curr, int &val, vector<int> adjList[], vector<bool> &visited, vector<vector<int>> &ans) {
		if(visited[curr]) return;
		visited[curr] = true;
		for(int next: adjList[curr]) {
			if(!visited[next]) {
				ans[next].push_back(val);
				dfs(next, val, adjList, visited, ans);
			}
		}
	}
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
		vector<vector<int>> ans(n);
		vector<int> adjList[n];
		for(vector<int> edge: edges) {
			adjList[edge[0]].push_back(edge[1]);
		}
		for(int i = 0; i < n; i++) {
			vector<bool> visited(n);
			dfs(i, i, adjList, visited, ans);
		}
		return ans;
	}
};
