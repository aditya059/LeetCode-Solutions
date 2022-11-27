/*
// Brute Force O(n^2)
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
*/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        stack<int> StackI;  // Increasing Stack
        stack<int> StackD;  // Decreasing Stack
        for(int i = 0; i <= n; i++) {
            while(!StackI.empty() && (i == n || nums[i] <= nums[StackI.top()])) {
                int middle = StackI.top();
                StackI.pop();
                int right = i;
                int left = StackI.empty()? -1: StackI.top();
                long long count = (middle - left) * (right - middle);
                ans = ans - nums[middle] * count;
            }
            StackI.push(i);
            while(!StackD.empty() && (i == n || nums[i] >= nums[StackD.top()])) {
                int middle = StackD.top();
                StackD.pop();
                int right = i;
                int left = StackD.empty()? -1: StackD.top();
                long long count = (middle - left) * (right - middle);
                ans = ans + nums[middle] * count;
            }
            StackD.push(i);
        }
        return ans;
    }
};

    