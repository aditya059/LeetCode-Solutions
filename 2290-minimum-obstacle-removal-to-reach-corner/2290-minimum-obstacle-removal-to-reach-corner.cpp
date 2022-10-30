// Dijkstra's - O(m * n * log (m * n))
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        set<pair<int, pair<int,int>>> PQ;
        PQ.insert({0, {0, 0}});
        dist[0][0] = 0;
        while(!PQ.empty()) {
            pair<int, pair<int,int>> curr = *PQ.begin();
            PQ.erase(PQ.begin());
            int ux = curr.second.first;
            int uy = curr.second.second;
            
            for(auto dir: dirs) {
                int vx = ux + dir[0];
                int vy = uy + dir[1];

                if(vx < 0 || vy < 0 || vx >= m || vy >= n) 
                    continue;
                
                int cost = dist[ux][uy] + grid[vx][vy];
                
                if(cost < dist[vx][vy]) {
                    auto iter = PQ.find({dist[vx][vy], {vx, vy}});
                    if(iter != PQ.end())
                        PQ.erase(iter);
                    dist[vx][vy] = cost;
                    PQ.insert({dist[vx][vy], {vx, vy}});
                }

            }
        }
        return dist[m - 1][n - 1];
    }
};