class Solution {
public:
    void dfs(int curr, string &s, vector<int> adjList[], vector<bool> &visited, vector<int> &indexes, string &values) {
        indexes.push_back(curr);
        values += s[curr];
        visited[curr] = true;
        for(int next: adjList[curr]) {
            if(!visited[next])
                dfs(next, s, adjList, visited, indexes, values);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<bool> visited(s.length());
        vector<int> adjList[s.length()];
        for(vector<int> pair: pairs) {
            adjList[pair[0]].push_back(pair[1]);
            adjList[pair[1]].push_back(pair[0]);
        }
        for(int i = 0; i < s.length(); i++) {
            if(!visited[i]) {
                vector<int> indexes;
                string values = "";
                dfs(i, s, adjList, visited, indexes, values);
                sort(indexes.begin(), indexes.end());
                sort(values.begin(), values.end());
                for(int i = 0; i < indexes.size(); i++) {
                    s[indexes[i]] = values[i];
                }
            }
        }
        return s;
    }
};