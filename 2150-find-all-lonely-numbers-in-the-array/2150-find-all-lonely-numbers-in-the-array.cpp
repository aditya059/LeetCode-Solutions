class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int freq[1000005] = {0};
        vector<int> ans;
        for(int num: nums)
            freq[num + 1]++;
        for(int num: nums) {
            if(freq[num + 1] == 1 && !freq[num] && !freq[num + 2])
                ans.push_back(num);
        }
        return ans;
    }
};