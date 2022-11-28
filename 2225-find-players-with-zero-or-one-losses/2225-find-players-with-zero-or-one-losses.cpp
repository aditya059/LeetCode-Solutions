class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        vector<int> player(100001, -1);
        for(int i = 0; i < matches.size(); i++) {
            player[matches[i][0]] = 0;
            player[matches[i][1]] = 0;
        }
        for(int i = 0; i < matches.size(); i++) {
            player[matches[i][1]]++;
        }
        for(int i = 1; i <= 100000; i++) {
            if(!player[i]) ans[0].push_back(i);
            if(player[i] == 1) ans[1].push_back(i);
        }
        return ans;
    }
};