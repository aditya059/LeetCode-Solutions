class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> Stack;
        for(int i = n - 1; i >= 0; i--) {
            while(!Stack.empty() && heights[i] > heights[Stack.top()]) {
                ans[i]++;
                Stack.pop();
            }
            if(!Stack.empty()) ans[i]++;
            Stack.push(i);
        }
        return ans;
    }
};