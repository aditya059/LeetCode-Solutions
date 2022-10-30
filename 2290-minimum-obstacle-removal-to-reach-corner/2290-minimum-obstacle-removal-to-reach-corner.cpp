class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        deque<vector<int>> Queue;
        Queue.push_front({0, 0, 0});
        visited[0][0] = true;

        while(!Queue.empty()) {
            int queueLen = Queue.size();
            for(int i = 0; i < queueLen; i++) {
                vector<int> curr = Queue.front();
                Queue.pop_front();
                
                for(auto dir: dirs) {
                    int x = curr[0] + dir[0];
                    int y = curr[1] + dir[1];
                    
                    if(x < 0 || y < 0 || x >= m || y >= n) 
                        continue;
                    
                    int temp = curr[2] + grid[x][y];
                    if(temp < visited[x][y])
                    {
                        visited[x][y] = temp;
                        if(grid[x][y])
                            Queue.push_back({x, y, temp});
                        else
                            Queue.push_front({x, y, temp});
                    }
                }
            }
        }
        return visited[m - 1][n - 1];
    }
};