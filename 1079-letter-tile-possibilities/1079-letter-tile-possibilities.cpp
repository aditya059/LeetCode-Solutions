class Solution {
public:
    void dfs(int count[], int &ans) {
        for(int i = 0; i < 26; i++) {
            if(count[i] > 0) {
                ans++;
                count[i]--;
                dfs(count, ans);
                count[i]++;
            } 
        }
    }
    int numTilePossibilities(string tiles) {
        int count[26] = {0};
        int ans = 0;
        for(char ch: tiles) count[ch - 'A']++;
        dfs(count, ans);
        return ans;
    }
};

/*

class Solution {
public:
    void dfs(string &tiles, int index, string &temp, set<string> &Set, vector<bool> &index_used) {
        for(int i = 0; i < tiles.size(); i++) {
            if(!index_used[i]) {
                temp.push_back(tiles[i]);
                Set.insert(temp);
                index_used[i] = true;
                dfs(tiles, i, temp, Set, index_used);
                index_used[i] = false;
                temp.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        set<string> Set;
        string temp = "";
        vector<bool> index_used(tiles.size());
        dfs(tiles, 0, temp, Set, index_used);
        return Set.size();
    }
};

*/