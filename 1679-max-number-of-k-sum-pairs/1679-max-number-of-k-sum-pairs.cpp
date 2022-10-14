class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> Map;
        for(int i = 0; i < nums.size(); i++) {
            Map[nums[i]]++;
        }
        
        for(auto iter: Map) {
            ans += min(Map[iter.first], Map[k - iter.first]); 
        }
        return ans / 2;
    }
};