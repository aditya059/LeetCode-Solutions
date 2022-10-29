class Solution {
public:
    bool queryString(string s, int n) {
        set<int> Set;
        int len = ceil(log2(n)) + 1;
        for(int i = 0; i < s.length(); i++) {
            int val = 0;
            for(int j = i; j < min((int)s.length(), i + len); j++) {
                val = val * 2 + (s[j] - '0');
                if(val > 0 && val <= n)
                    Set.insert(val);
            }
        }
        return Set.size() == n;
    }
};