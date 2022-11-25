class Solution {
public:
	int sumSubarrayMins(vector<int>& arr) {
		const int MOD = 1e9 + 7;
		long ans = 0;
		int n = arr.size();
		stack<int> Stack;
		vector<int> left(n);
		for(int i = 0; i < n; i++) {
			while(!Stack.empty() && arr[i] <= arr[Stack.top()]) {
				Stack.pop();
			}
			left[i] = Stack.empty()? i + 1: i - Stack.top();
			Stack.push(i);
		}
		while(!Stack.empty()) Stack.pop();
		for(int i = n - 1; i >= 0; i--) {
			while(!Stack.empty() && arr[i] < arr[Stack.top()]) {
				Stack.pop();
			}
			int right = Stack.empty()? n - i: Stack.top() - i;
			ans = (ans + (((left[i] * 1L * right) % MOD) * arr[i]) % MOD) % MOD;
			Stack.push(i);
		}
		return ans;
	}
};