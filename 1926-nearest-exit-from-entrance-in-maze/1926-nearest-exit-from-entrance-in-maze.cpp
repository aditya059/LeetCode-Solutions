class Solution {
public:
    bool reachedDestination(vector<int> &source, vector<int> &curr, int &m, int &n) {
        if(source[0] == curr[0] && source[1] == curr[1]) return false;
        if(curr[0] == 0 || curr[0] == m - 1 || curr[1] == 0 || curr[1] == n - 1) return true;
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<vector<int>> Queue;
        Queue.push(entrance);
        int ans = -1;
        while(!Queue.empty()) {
            int sz = Queue.size();
            ans++;
            for(int i = 0; i < sz; i++) {
                vector<int> curr = Queue.front();
                Queue.pop();
                if(reachedDestination(entrance, curr, m, n)) return ans;
                for(vector<int> dir: dirs) {
                    int x = curr[0] + dir[0];
                    int y = curr[1] + dir[1];
                    if(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.') {
                        maze[x][y] = '+';
                        Queue.push({x, y});
                    }
                }
            }
        }
        return -1;
    }
};