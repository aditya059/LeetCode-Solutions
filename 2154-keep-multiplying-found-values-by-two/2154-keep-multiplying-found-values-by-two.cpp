class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> Set(nums.begin(), nums.end());
        while(true) {
            if(Set.find(original) != Set.end())
                original *= 2;
            else
                return original;
        }
        return original;
    }
};