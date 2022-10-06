class TimeMap {
public:
    unordered_map<string, map<int, string>> Map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        Map[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(Map.find(key) == Map.end()) return "";
        
        auto iter = Map[key].upper_bound(timestamp);
        
        if(iter == Map[key].begin()) return "";
        
        return prev(iter) -> second;
    }
};

