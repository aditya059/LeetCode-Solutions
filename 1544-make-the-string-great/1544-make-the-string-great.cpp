class Solution {
public:
    string makeGood(string s) {
        int k = 0;
        for(int i = 0; i < s.length(); i++) {
            if(k == 0) s[k++] = s[i];
            else if(abs(s[i] - s[k - 1]) == 32) k--;
            else 
                s[k++] = s[i];
        }
        return s.substr(0, k);
    }
};