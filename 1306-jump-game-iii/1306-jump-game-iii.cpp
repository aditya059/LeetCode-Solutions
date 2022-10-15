class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        queue<int> Queue;
        Queue.push(start);
        while(!Queue.empty()) {
            int sz = Queue.size();
            for(int j = 0; j < sz; j++) {
                int i = Queue.front();
                Queue.pop();
                if(arr[i] == 0) return true;
                if(i + arr[i] < arr.size() && !visited[i + arr[i]]) {
                    visited[i + arr[i]] = true;
                    Queue.push(i + arr[i]);
                }
                if(i - arr[i] >= 0 && !visited[i - arr[i]]) {
                    visited[i - arr[i]] = true;
                    Queue.push(i - arr[i]);
                }
            }
        }
        return false;
    }
};