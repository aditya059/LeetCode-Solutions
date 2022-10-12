class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> IDsInGroup;
        for(int i = 0; i < groupSizes.size(); i++) {
            IDsInGroup[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto iter: IDsInGroup) {
            if(iter.second.size() <= iter.first)
                ans.push_back(iter.second);
            else {
                vector<int> temp;
                for(int ID: iter.second) {
                    temp.push_back(ID);
                    if(temp.size() == iter.first) {
                        ans.push_back(temp);
                        temp.clear();
                    }
                }
            }
        }
        return ans;
    }
};