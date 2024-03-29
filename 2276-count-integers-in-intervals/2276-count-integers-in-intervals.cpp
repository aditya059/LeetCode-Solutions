class CountIntervals {
    private:
    map<int, int> intervals;
    int ans;
public:
    CountIntervals() {
        ans = 0;
    }
    
    void add(int left, int right) {
        auto iter = intervals.upper_bound(left);
        if(iter != intervals.begin() && prev(iter) -> second >= left) iter--;
        while(iter != intervals.end() && right >= iter -> first) {
            ans -= iter -> second - iter -> first + 1;
            left = min(left, iter -> first);
            right = max(right, iter -> second);
            iter = intervals.erase(iter);
        }
        ans += right - left + 1;
        intervals[left] = right;
    }
    
    int count() {
        return ans;
    }
};
/*
class CountIntervals {
    private:
    struct comp {
        bool operator()(const vector<int> &A, const vector<int> &B) const {return A[0] < B[0];}
    };
    set<vector<int>, comp> Set;
    int ans;
public:
    CountIntervals() {
        ans = 0;
    }
    
    void add(int left, int right) {
        auto iter = Set.lower_bound({left, right});
        if(iter != Set.begin() && (*prev(iter))[1] >= left) iter--;
        while(iter != Set.end() && right >= (*iter)[0]) {
            ans -= (*iter)[1] - (*iter)[0] + 1;
            left = min(left, (*iter)[0]);
            right = max(right, (*iter)[1]);
            iter = Set.erase(iter);
        }
        ans += right - left + 1;
        Set.insert(iter, {left, right});
    }
    
    int count() {
        return ans;
    }
};
*/

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
