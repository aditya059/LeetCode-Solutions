class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> PQ;
        PQ.push_back({0, 0});
        visited[0][0] = true;
        dist[0][0] = 0;

        while(!PQ.empty()) {
            pair<int, int> curr = PQ.front();
            PQ.pop_front();
            
            int ux = curr.first;
            int uy = curr.second;
            
            for(auto dir: dirs) {
                int vx = ux + dir[0];
                int vy = uy + dir[1];

                if(vx < 0 || vy < 0 || vx >= m || vy >= n) 
                    continue;
                
                if(!visited[vx][vy]) {
                    visited[vx][vy] = true;
                    
                    dist[vx][vy] = dist[ux][uy] + grid[vx][vy];
                    if(grid[vx][vy])
                        PQ.push_back({vx, vy});
                    else
                        PQ.push_front({vx, vy});
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};