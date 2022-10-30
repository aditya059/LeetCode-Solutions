class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        set<vector<int>> PQ;
        PQ.insert({0, 0, 0});
        dist[0][0] = 0;
        while(!PQ.empty()) {
            vector<int> curr = *PQ.begin();
            PQ.erase(PQ.begin());
            int ux = curr[1];
            int uy = curr[2];
            
            for(auto dir: dirs) {
                int vx = ux + dir[0];
                int vy = uy + dir[1];

                if(vx < 0 || vy < 0 || vx >= m || vy >= n) 
                    continue;
                
                int cost = grid[vx][vy];
                
                if(dist[ux][uy] + cost < dist[vx][vy]) {
                    //PQ.erase({dist[vx][vy], vx, vy});
                    dist[vx][vy] = dist[ux][uy] + cost;
                    PQ.insert({dist[vx][vy], vx, vy});
                }

            }
        }
        return dist[m - 1][n - 1];
    }
};