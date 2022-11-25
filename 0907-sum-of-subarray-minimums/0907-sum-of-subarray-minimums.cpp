class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long ans = 0;
        int n = arr.size();
        stack<int> Stack;
        for(int i = 0; i <= n; i++) {
            while(!Stack.empty() && (i == n || arr[i] <= arr[Stack.top()])) {
                int middle = Stack.top();
                Stack.pop();
                int right = i;
                int left = Stack.empty()? -1: Stack.top();
                long count = (middle - left) * (right - middle);
                ans = (ans + (arr[middle] * count % MOD) % MOD) % MOD;
            }
            Stack.push(i);
        }
        return ans;
    }
};
/*
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long ans = 0;
        int n = arr.size();
        stack<int> Stack;
        vector<int> DP(n);
        for(int i = 0; i < n; i++) {
            while(!Stack.empty() && arr[i] <= arr[Stack.top()]) {
                Stack.pop();
            }
            DP[i] = Stack.empty()? i + 1: i - Stack.top();
            Stack.push(i);
        }
        while(!Stack.empty()) Stack.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!Stack.empty() && arr[i] < arr[Stack.top()]) {
                Stack.pop();
            }
            long right = Stack.empty()? n - i: Stack.top() - i;
            ans = (ans + (((DP[i] * right) % MOD) * arr[i]) % MOD) % MOD;
            Stack.push(i);
        }
        return ans;
    }
};
*/