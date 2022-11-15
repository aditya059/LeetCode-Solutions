class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> degree(n);
        vector<int> ans;
        for(vector<int> edge: edges) {
            degree[edge[1]]++;
        }
        for(int i = 0; i < n; i++){
            if(!degree[i]) ans.push_back(i);
        }
        return ans;
    }
};