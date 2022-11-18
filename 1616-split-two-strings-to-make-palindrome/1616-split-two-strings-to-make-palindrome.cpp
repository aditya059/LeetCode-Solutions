class Solution {
public:
    bool isPalindrome(string &a, int i, int j) {
        while(i < j && a[i] == a[j]) {
            i++;
            j--;
        }
        return i >= j;
    }
    bool solve(string &a, string &b) {
        int i = 0; 
        int j = a.size() - 1;
        while(i < j && a[i] == b[j]) {
            i++;
            j--;
        }
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }
    bool checkPalindromeFormation(string a, string b) {
        return solve(a, b) || solve(b, a);
    }
};