class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int a = -1;
        int b = 1;
        int c = a + b;
        vector<int> fib;
        while(c <= k) {
            fib.push_back(c);
            a = b;
            b = c;
            c = a + b;
        }
        int ans = 0;
        for(int i = fib.size() - 1; i > 0; i--) {
            if(fib[i] <= k) {
                ans++;
                k -= fib[i];
            }
        }
        return ans;
    }
};