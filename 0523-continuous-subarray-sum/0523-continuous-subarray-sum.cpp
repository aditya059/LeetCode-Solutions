class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> Map;
        int sum = 0;
        Map[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;
            if(Map.find(sum) == Map.end())
                Map[sum] = i;
            else if(i - Map[sum] > 1) 
                return true;
        }
        return false;
    }
};
