class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> ans;
        for(int num: nums)
            freq[num]++;
        for(int num: nums) {
            if(freq[num] == 1 && !freq[num - 1] && !freq[num + 1])
                ans.push_back(num);
        }
        return ans;
    }
};