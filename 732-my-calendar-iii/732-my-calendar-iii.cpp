class MyCalendarThree {
public:
    map<int, short> Map;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        Map[start]++;
        Map[end]--;
        if(Map[end] == 0) Map.erase(end);
        int sum = 0, ans = 0;
        for(auto iter: Map) {
            sum += iter.second;
            ans = max(ans, sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */