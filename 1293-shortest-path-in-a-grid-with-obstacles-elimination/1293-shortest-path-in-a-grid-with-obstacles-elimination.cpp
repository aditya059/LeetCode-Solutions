class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<vector<int>> Queue;
        Queue.push({0, 0, k});
        visited[0][0] = true;
        int steps = -1;
        while(!Queue.empty()) {
            int queueLen = Queue.size();
            steps++;
            for(int i = 0; i < queueLen; i++) {
                vector<int> curr = Queue.front();
                Queue.pop();
                
                if(curr[0] == m - 1 && curr[1] == n - 1 && k >= 0)
                    return steps;
                
                for(auto dir: dirs) {
                    int x = curr[0] + dir[0];
                    int y = curr[1] + dir[1];
                    
                    if(x < 0 || y < 0 || x >= m || y >= n) 
                        continue;
                    
                    if(curr[2] - grid[x][y] > visited[x][y])
                    {
                        visited[x][y] = curr[2] - grid[x][y];
                        Queue.push({x, y, curr[2] - grid[x][y]});
                    }
                }
            }
        }
        return -1;
    }
};