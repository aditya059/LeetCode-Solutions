class Solution {
public:
    string generateTheString(int n) {
        string ans = "";
        for(int i = 0; i < n; i++) {
            ans += 'a';
        }
        if(n % 2)
            return ans;
        ans[ans.size() - 1] = 'b';
        return ans;
    }
};