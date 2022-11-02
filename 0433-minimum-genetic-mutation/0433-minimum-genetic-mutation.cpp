class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        char allowedChar[4] = {'A', 'C', 'G', 'T'};
        set<string> Set(bank.begin(), bank.end());
        queue<string> Queue;
        Queue.push(start);
        int ans = -1;
        while(!Queue.empty()) {
            int sz = Queue.size();
            ans++;
            for(int i = 0; i < sz; i++) {
                string curr = Queue.front();
                Queue.pop();
                if(curr == end) return ans;
                for(int j = 0; j < 8; j++) {
                    string next = curr;
                    for(char ch: allowedChar) {
                        next[j] = ch;
                        
                        if(binary_search(Set.begin(), Set.end(), next)) {
                            Queue.push(next);
                            Set.erase(next);
                        }
                    }
                }
            }
        }
        return -1;
    }
};