class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> Set;
        for(int num: arr) {
            Set.insert(num);
        }
        vector<int> temp;
        for(int i: Set) {
            temp.push_back(i);
        }
        vector<int> ans;
        for(int num: arr) {
            ans.push_back((lower_bound(temp.begin(), temp.end(), num) - temp.begin()) + 1);
        }
        return ans;
    }
};