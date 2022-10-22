class Solution {
public:
    bool check(map<int, int> &Map, map<int, int> &Set) {
        for(auto iter: Set) {
            if(Map[iter.first] < Set[iter.first])
            return false;
        }
        return true;
    }
    string minWindow(string &str, string &p) {
        // Your code here
        map<int, int> Set;
        map<int, int> Map;
        for(int i = 0; i < p.length(); i++) {
            Set[p[i]]++;
        }
        int i = 0; 
        int j = 0;
        int s = 0;
        int ans = INT_MAX;
        while(j <= str.length()) {
            while(i < str.length() && check(Map, Set)) {
                if(j - i < ans) {
                    ans = j - i;
                    s = i;
                }
                Map[str[i]]--;
                i++;
            }
            Map[str[j]]++;
            j++;
        }
        if(ans == INT_MAX) 
            return "";
        string a = str.substr(s, ans);
        return a;
    }
    

};