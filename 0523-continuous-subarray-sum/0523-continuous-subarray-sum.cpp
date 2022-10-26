class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1) return false;
        int currSum = 0;
        unordered_map<int, int> Map;
        Map[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            currSum = (currSum + nums[i]) % k;
            if(Map.find(currSum) != Map.end()) {
                if(i - Map[currSum] >= 2)
                    return true;
            }
            else
                Map[currSum] = i;
        }
        return false;
    }
};