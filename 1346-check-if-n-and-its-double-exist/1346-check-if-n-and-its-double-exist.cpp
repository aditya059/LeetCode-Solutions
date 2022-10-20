class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> Map;
        for(int i = 0; i < arr.size(); i++) {
            if(Map.find(2 * arr[i]) != Map.end()) return true;
            if(arr[i] % 2 == 0 && Map.find(arr[i] / 2) != Map.end()) return true;
            Map[arr[i]]++;
        }
        return false;
    }
};