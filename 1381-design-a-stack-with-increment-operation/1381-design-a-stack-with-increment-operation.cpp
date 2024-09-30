class CustomStack {
public:
    vector<int> Stack;
    int maxSize;
    CustomStack(int maxSize) {
        this -> maxSize = maxSize;
    }
    
    void push(int x) {
        if(Stack.size() >= maxSize)
            return;
        Stack.push_back(x);
    }
    
    int pop() {
        if(Stack.empty()) return -1;
        int ans = Stack.back();
        Stack.pop_back();
        return ans;
    }
    
    void increment(int k, int val) {
        int i = 1;
        for(auto iter = Stack.begin(); iter != Stack.end(); iter++) {
            *iter += val;
            if(i == k) return;
            i++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

OR

class CustomStack {
public:
    vector<int> Stack, incr;
    int maxSize;
    CustomStack(int maxSize) {
        this -> maxSize = maxSize;
    }
    
    void push(int x) {
        if(Stack.size() >= maxSize)
            return;
        Stack.push_back(x);
        incr.push_back(0);
    }
    
    int pop() {
        if(Stack.empty()) return -1;
        int ans = Stack.back() + incr.back();
        Stack.pop_back();
        int val = incr.back();
        incr.pop_back();
        if(incr.size()) incr.back() += val;
        return ans;
    }
    
    void increment(int k, int val) {
        k = min(k, (int)incr.size());
        if(k)
            incr[k - 1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
