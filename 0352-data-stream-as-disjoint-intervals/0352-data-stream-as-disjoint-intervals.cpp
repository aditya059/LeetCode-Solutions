class SummaryRanges {
private:
    map<int, vector<int>> Map;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if(Map.find(value) != Map.end()) return;
        auto iter = Map.lower_bound(value);
        if(iter != Map.begin() && iter != Map.end() && prev(iter) -> second[1] + 1 == value && iter -> first - 1 == value) {
            prev(iter) -> second[1] = iter -> second[1];
            Map.erase(iter);
        }
        else if(iter != Map.begin() && prev(iter) -> second[1] + 1 >= value) {
            prev(iter) -> second[1] = max(value, prev(iter) -> second[1]);
        }
        else if(iter != Map.end() && iter -> first == value + 1) {
            Map[value] = {value, iter -> second[1]};
            Map.erase(iter);
        }
        else {
            Map[value] = {value, value};
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto iter: Map) 
            ans.push_back(iter.second);
        return ans;
    }
};
/*
class SummaryRanges {
private:
    struct comp {
        bool operator()(const vector<int> &A, const vector<int> &B) const {return A[0] < B[0];}
    };
    set<vector<int>, comp> Set;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        auto iter = Set.lower_bound({value, value});
        int start, end;
        if(iter != Set.begin() && iter != Set.end() && (*prev(iter))[1] + 1 == value && (*iter)[0] - 1 == value) {
            // Merge 2 intervals
            start = (*prev(iter))[0];
            end = (*iter)[1];
            Set.erase(prev(iter));
            Set.erase(iter);
            Set.insert({start, end});
        }
        else if(iter != Set.begin() && (*prev(iter))[1] + 1 >= value) {
            start = (*prev(iter))[0];
            end = max(value, (*prev(iter))[1]);
            Set.erase(prev(iter));
            Set.insert({start, end});
        }
        else if(iter != Set.end() && (*iter)[0] == value + 1) {
            end = (*iter)[1];
            Set.erase(iter);
            Set.insert({value, end});
        }
        else {
            Set.insert({value, value});
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans(Set.begin(), Set.end());
        return ans;
    }
};
*/

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

