class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        string word = "";
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] != ' ')
                word += s[i];
            else if(word != "") {
                reverse(word.begin(), word.end());
                if(result != "")
                    result += ' ';
                result += word;
                word = "";
            }
        }
        if(s[0] != ' ') {
            reverse(word.begin(), word.end());
            if(result != "")
                result += ' ';
            result += word;
        }
        return result;
    }
};