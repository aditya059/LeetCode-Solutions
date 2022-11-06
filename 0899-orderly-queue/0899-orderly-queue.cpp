class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1)
            sort(s.begin(), s.end());
        else{
            string temp = s;
            for(int i = 1; i < s.length(); i++) {
                temp = min(s.substr(i) + s.substr(0, i), temp);
            }
            s = temp;
        }
        return s;
    }
};