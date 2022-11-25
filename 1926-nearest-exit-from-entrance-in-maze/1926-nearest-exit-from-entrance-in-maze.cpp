class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<vector<int>> Queue;
        Queue.push(entrance);
        maze[entrance[0]][entrance[1]] = '+';
        int ans = -1;
        while(!Queue.empty()) {
            int sz = Queue.size();
            ans++;
            for(int i = 0; i < sz; i++) {
                vector<int> curr = Queue.front();
                Queue.pop();
                for(vector<int> dir: dirs) {
                    int x = curr[0] + dir[0];
                    int y = curr[1] + dir[1];
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