class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int temp = 0;
        for(int i = 0; i < nums.size(); i++) {
            temp = temp ^ (i + 1) ^ nums[i];
        }
        
        int i = temp & -temp;
       
        int ans1 = 0, ans2 = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] & i)
                ans1 = ans1 ^ nums[j];
            else
                ans2 = ans2 ^ nums[j];
            if((j + 1) & i)
                ans1 = ans1 ^ (j + 1);
            else
                ans2 = ans2 ^ (j + 1);
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == ans1) return {ans1, ans2};
        }
        return {ans2, ans1};
    }
};


OR


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long actSqrSum = 0;
        int actSum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            actSum += nums[i];
            actSqrSum += nums[i] * nums[i];
        }
        long expSqrSum = n * 1L * (n + 1) * (2 * n + 1) / 6;
        int expSum = n * (n + 1) / 2;
        int m = ((expSqrSum - actSqrSum) / (expSum - actSum) + (expSum - actSum)) / 2;
        return {m - expSum + actSum, m};
    }
};
