func numOfVowels(s string) int {
    count := 0
    s = strings.ToLower(s)
    for _, ch := range(s) {
        if ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' {
             count++
        }
    }
    return count
}
func halvesAreAlike(s string) bool {
    return numOfVowels(s[:len(s) / 2]) == numOfVowels(s[len(s)/2:])
}

OR

class Solution {
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    bool halvesAreAlike(string s) {
        int count = 0;
        for(int i = 0, j = s.length() - 1; i < j; i++, j--) {
            count += isVowel(s[i]) - isVowel(s[j]);
        }
        return count == 0;
    }
};
