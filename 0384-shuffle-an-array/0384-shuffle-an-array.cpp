class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this -> nums = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> result(nums);
        for(int i = 0; i < nums.size(); i++) {
            int j = rand() % nums.size();
            swap(result[i], result[j]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */