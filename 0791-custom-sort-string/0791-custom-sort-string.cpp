class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> pos(26, INT_MAX);
        for(int i = 0; i < order.length(); i++) {
            pos[order[i] - 'a'] = min(pos[order[i] - 'a'], i);
        }
        sort(s.begin(), s.end(), [&](char &a, char &b) {return pos[a - 'a'] < pos[b - 'a'];});
        return s;
    }
};

/*
class Solution {
public:
    string customSortString(string order, string s) {
        sort(s.begin(), s.end(), [&](char &a, char &b) {return order.find(a) < order.find(b);});
        return s;
    }
};
*/