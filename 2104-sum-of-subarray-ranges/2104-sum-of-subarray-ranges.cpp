class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int minimum = INT_MAX;
            int maximum = INT_MIN;
            for(int j = i; j < n; j++) {
                minimum = min(nums[j], minimum);
                maximum = max(nums[j], maximum);
                ans += maximum - minimum;
            }
        }
        return ans;
    }
};

/*const int MOD = 1e9 + 7;
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
        */