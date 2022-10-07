class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int index[26] = {0};
        for(int i = 0; i < s.length(); i++) {
            int val = s[i] - 'a';
            if(index[val] != 0 && i - index[val] != distance[val]) 
                return false;
            index[val] = i + 1;
        }
        return true;
    }
};