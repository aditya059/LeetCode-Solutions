class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib(2);
        fib[0] = 0;
        fib[1] = 1;
        for(int i = 2; fib[i - 1] <= k; i++) {
            fib.push_back(fib[i - 1] + fib[i - 2]);
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