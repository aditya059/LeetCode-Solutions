class Solution {
public:
    
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> matrix(26, vector<int> (27, 0));
        for(int i = 0; i < votes.size(); i++) {
            for(int j = 0; j < votes[0].size(); j++) {
                int index = votes[i][j] - 'A';
                matrix[index][j]++;
            }
        }
        for(int i = 0; i < 26; i++) {
            matrix[i][26] = 25 - i;
        }
        sort(matrix.begin(), matrix.end());
        string ans = "";
        for(int i = 0; i < votes[0].size(); i++) {
            ans += 'A' + 25 - matrix[25 - i][26];
        }
        return ans;
    }
};