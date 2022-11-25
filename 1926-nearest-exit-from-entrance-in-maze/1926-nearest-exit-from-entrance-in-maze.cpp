class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> Queue;
        Queue.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int ans = -1;
        while(!Queue.empty()) {
            int sz = Queue.size();
            ans++;
            for(int i = 0; i < sz; i++) {
                pair<int, int> curr = Queue.front();
                Queue.pop();
                for(pair<int, int> dir: dirs) {
                    int x = curr.first + dir.first;
                    int y = curr.second + dir.second;
                    if(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.') {
                        if(x == 0 || x == m - 1 || y == 0 || y == n - 1) return ans + 1;
                        maze[x][y] = '+';
                        Queue.push({x, y});
                    }
                }
            }
        }
        return -1;
    }
};