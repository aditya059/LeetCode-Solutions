class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> Stack;
        for(char ch: s) {
            if(!Stack.empty() && Stack.top() == ch)
                Stack.pop();
            else
                Stack.push(ch);
        }
        string ans = "";
        while(!Stack.empty()) {
            ans += Stack.top();
            Stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};