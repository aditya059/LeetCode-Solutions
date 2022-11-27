class Solution {
public:
    static bool comp(string &A, string &B) {
        return A.length() > B.length() || A.length() == B.length() && A < B;
    }
    bool isSubsequence(string &s, string &word) {
        int i = 0; 
        int j = 0;
        while(i < s.length() && j < word.length()) {
            if(s[i] == word[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return j == word.length();
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans;
        sort(dictionary.begin(), dictionary.end(), comp);
        for(string word: dictionary) {
            if(isSubsequence(s, word)) {
                return word;
            }
        }
        return "";
    }
};