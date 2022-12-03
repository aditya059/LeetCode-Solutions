class Solution {
public:
    string frequencySort(string s) {
        string freq[128];
        for(int i = 0; i < s.length(); i++)
            freq[s[i]] += s[i];
        priority_queue<pair<int, string>> pq;
        for(int i = 0; i < 128; i++) {
            if(freq[i].size()) pq.push({freq[i].length(), freq[i]});
        }
        string ans = "";
        while(!pq.empty()) {
            ans += pq.top().second;
            pq.pop();
        }
        return ans;
    }
};