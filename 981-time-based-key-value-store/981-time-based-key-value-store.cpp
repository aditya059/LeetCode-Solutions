class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> Map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        Map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(Map.find(key) == Map.end()) return "";
        
        int l = 0;
        int h = Map[key].size() - 1;
        int t = INT_MIN;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(Map[key][mid].first == timestamp) return Map[key][mid].second;
            else if(Map[key][mid].first > timestamp) h = mid - 1;
            else {
                t = max(t, mid);
                l = mid + 1;
            }
        }
        if(t == INT_MIN) return "";
        return Map[key][t].second;
    }
};

