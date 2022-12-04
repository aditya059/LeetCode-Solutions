class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int count[5] = {0};
        int ans = 0, frog = 0;
        map<char, int> Map = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        for(char ch: croakOfFrogs) {
            count[Map[ch]]++;
            if(ch == 'c') 
                ans = max(ans, ++frog);
            else if(--count[Map[ch] - 1] < 0)
                return -1;
            else if(ch == 'k')
                frog--;
        }
        return frog == 0? ans: -1;
    }
};