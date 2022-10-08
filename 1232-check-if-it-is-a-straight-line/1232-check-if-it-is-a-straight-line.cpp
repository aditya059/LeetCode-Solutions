class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int diffX = coordinates[1][0] - coordinates[0][0];
        int diffY = coordinates[1][1] - coordinates[0][1];
        for(vector<int> coor: coordinates) {
            int A = diffX * (coor[1] - coordinates[0][1]);
            int B = diffY * (coor[0] - coordinates[0][0]);
            if(A != B) return false;
        }
        return true;
    }
};