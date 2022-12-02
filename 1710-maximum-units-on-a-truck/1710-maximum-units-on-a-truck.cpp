class Solution {
public:
    static bool comp(vector<int> &A, vector<int> &B) {
        return A[1] > B[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(), comp);
        for(vector<int> boxType: boxTypes) {
            if(boxType[0] <= truckSize) {
                ans += boxType[1] * boxType[0];
                truckSize -= boxType[0];
            }
            else {
                ans += truckSize * boxType[1];
                break;
            }
        }
        return ans;
    }
};