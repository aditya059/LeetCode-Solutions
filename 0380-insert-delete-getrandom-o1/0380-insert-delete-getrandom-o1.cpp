class RandomizedSet {
private:
    unordered_map<int, int> Map;
    vector<int> num;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(Map.find(val) != Map.end()) return false;
        num.push_back(val);
        Map[val] = num.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(Map.find(val) == Map.end()) return false;
        num[Map[val]] = num.back();
        Map[num.back()] = Map[val];
        num.pop_back();
        Map.erase(val);
        return true;
    }
    
    int getRandom() {
        return num[rand() % num.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */