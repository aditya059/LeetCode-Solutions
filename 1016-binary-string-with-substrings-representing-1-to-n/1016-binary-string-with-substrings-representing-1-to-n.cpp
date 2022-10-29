class Solution {
public:
    bool queryString(string s, int n) {
        set<int> Set;
        for(int i = 0; i < s.length(); i++) {
            int val = 0;
            for(int j = i; j < min((int)s.length(), i + 31); j++) {
                val = val * 2 + (s[j] - '0');
                if(val > 0 && val <= n)
                    Set.insert(val);
            }
        }
        return Set.size() == n;
    }
};