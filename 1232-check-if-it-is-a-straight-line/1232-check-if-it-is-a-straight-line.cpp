class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int diffX = coordinates[1][0] - coordinates[0][0];
        int diffY = coordinates[1][1] - coordinates[0][1];
        for(vector<int> coor: coordinates) {
            if(diffX * (coor[1] - coordinates[0][1]) != diffY * (coor[0] - coordinates[0][0])) return false;
        }
        return true;
    }
};