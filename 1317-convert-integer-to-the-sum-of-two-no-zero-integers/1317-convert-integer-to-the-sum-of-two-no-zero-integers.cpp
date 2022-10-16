class Solution {
public:
    bool check(int n) {
    
        for(int i = n; i > 0; i /= 10) {
            
            if(i % 10 == 0)
                return false;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int len = n / 2;
        for(int i = 1; i <= len; i++) {
            
            if(check(i) && check(n - i))
                return{i, n - i};
        }
        return {-1, -1};
    }
};