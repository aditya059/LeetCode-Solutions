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