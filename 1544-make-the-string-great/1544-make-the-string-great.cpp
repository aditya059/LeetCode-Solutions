class Solution {
public:
    string makeGood(string s) {
        string Stack = s;
        int k = 0;
        for(char ch: s) {
            if(k == 0) Stack[k++] = ch;
            else if(abs(ch - Stack[k - 1]) == 32) k--;
            else 
                Stack[k++] = ch;
        }
        return Stack.substr(0, k);
    }
};