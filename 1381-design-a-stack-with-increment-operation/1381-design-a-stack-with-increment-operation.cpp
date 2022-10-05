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